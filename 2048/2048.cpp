#include "2048.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Board::Board() : turn(0) {
	SetUpBoard();
}

void Board::Draw() const {
	string help[3] = {"\t2048 Game", "Moves: Arrow Keys, R - Reset, ESC - Exit",
	                  "Let the biggest number in the corner"};
	enum {
		Title, Operation, Tips
	};

	system("cls");

	cout << help[Title] << endl << endl;
	cout << "Turn: " << turn << endl << endl << endl;
	for (int i = 0; i < Size; ++i) {
		cout << "\t |";
		for (int j = 0; j < Size; ++j) {
			if (Table_Now[i][j].GetState())
				printf("%4d |", Table_Now[i][j].GetValue());
			else
				printf("%4c |", ' a ');
		}

		cout << endl << endl;
	}
	cout << endl << help[Operation] << endl << endl;
	cout << "Tips:  " << help[Tips] << endl;


}

int Board::RandomNum() const {
	srand(time(NULL));
	int temp = rand() % 100 + 1;
	if (temp > 80)
		return 4;
	else
		return 2;
}

void Board::AddRandomNum() {
	int x, y;
	int count = 0;
	int index[Size * Size][2];

	for (x = 0; x < Size; x++) {
		for (y = 0; y < Size; y++) {
			if (!Table_Now[x][y].GetState()) {
				index[count][0] = x;
				index[count][1] = y;
				count++;
			}
		}
	}

	if (count > 0) {
		int num = rand() % count;
		x = index[num][0];
		y = index[num][1];
		Table_Now[x][y].SetValue(RandomNum());
		Table_Now[x][y].SetState();
	}
}

void Board::SetUpBoard() {
	AddRandomNum();
	AddRandomNum();
	Draw();
}

void Board::RestartGame() {
	turn = 0;
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j) {
			Table_Now[i][j].UnSetState();
			Table_Now[i][j].SetValue(0);
		}
	}
	SetUpBoard();
}

void Board::RowInvert(int row) {
	Tile temp;
	for (int column = 0; column < Size / 2; ++column) {
		temp = Table_Now[row][column];
		Table_Now[row][column] = Table_Now[row][Size - column - 1];
		Table_Now[row][Size - column - 1] = temp;
	}
}

void Board::MatrixInvert() {
	for (int i = 0; i < Size; ++i)
		RowInvert(i);
}

void Board::MatrixTransform() {
	Tile temp;
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = i + 1; j < Size; ++j) {
			temp = Table_Now[i][j];
			Table_Now[i][j] = Table_Now[j][i];
			Table_Now[j][i] = temp;
		}
	}
}


//left
void Board::RowTighten(int row) {
	int i, j, count = 0;
	int new_row[Size] = {0};
	for (int column = 0; column < Size; ++column) {
		if (Table_Now[row][column].GetState())
			new_row[count++] = Table_Now[row][column].GetValue();
	}
	for (j = 0; j < count; ++j) {
		Table_Now[row][j].SetValue(new_row[j]);
		Table_Now[row][j].SetState();
	}
	for (i = j; i < Size; ++i) {
		Table_Now[row][i].UnSetState();
	}
}

void Board::RowMerge(int row) {
	int new_row[Size] = {0};
	bool pair = false;
	for (int i = 0; i < Size; ++i) {
		if (pair) {
			new_row[i] = Table_Now[row][i].GetValue() * 2;
			pair = false;
		}
		else {
			if (Table_Now[row][i].GetValue() == Table_Now[row][i + 1].GetValue()) {
				pair = true;
				new_row[i] = 0;
			}
			else
				new_row[i] = Table_Now[row][i].GetValue();
		}
	}
	for (int j = 0; j < Size; ++j) {
		if (new_row[j] == 0)
			Table_Now[row][j].UnSetState();
		else {
			Table_Now[row][j].SetValue(new_row[j]);
			Table_Now[row][j].SetState();
		}
	}
}

void Board::MatrixTighten() {
	for (int row = 0; row < Size; ++row)
		RowTighten(row);
}

void Board::MatrixMerge() {
	for (int row = 0; row < Size; ++row)
		RowMerge(row);
}

bool Board::CanMoveRow(int row) const {
	for (int i = 0; i < Size; ++i) {
		if (!Table_Now[row][i].GetState())
			return true;
		else if (Table_Now[row][i].GetState() &&
		         Table_Now[row][i].GetValue() == Table_Now[row][i + 1].GetValue())
			return true;
	}
	return false;
}

bool Board::CanMoveMatrix() {
	for (int row = 0; row < Size; ++row) {
		if (CanMoveRow(row))
			return true;
	}
	MatrixTransform();
	for (int row = 0; row < Size; ++row) {
		if (CanMoveRow(row)) {
			MatrixTransform();
			return true;
		}
	}
	MatrixTransform();
	return false;
}

bool Board::IsLose() {
	return !CanMoveMatrix();
}

bool Board::IsWin() {
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j) {
			if (Table_Now[i][j].GetValue() == 2048)
				return true;
		}
	}
	return false;
}


bool Board::AfterMove() {
	bool Win, Lose;
	Win = IsWin();
	Lose = IsLose();
	if (Win) {
		Draw();
		cout << "\n\n\tCongratulations!\t\nYou Win!!!\n\t<ESC to quit>\n";
		return false;
	}

	else if (Lose) {
		Draw();
		cout << "\n\n\tGame Over\n <ESC to quit>";
		return false;
	}
	else {
		AddRandomNum();
		turn++;
		Draw();
		return true;
	}

}

void Board::MoveLeftMatrix() {
	MatrixTighten();
	MatrixMerge();
	MatrixTighten();
	AfterMove();
}

void Board::MoveRightMatrix() {
	MatrixInvert();
	MoveLeftMatrix();
	MatrixInvert();
	AfterMove();
}

void Board::MoveUpMatrix() {
	MatrixTransform();
	MoveLeftMatrix();
	MatrixTransform();
	AfterMove();
}

void Board::MoveDownMatrix() {
	MatrixTransform();
	MoveRightMatrix();
	MatrixTransform();
	AfterMove();
}

