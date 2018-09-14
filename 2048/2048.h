#ifndef INC_2048_H
#define INC_2048_H

class Board {
private:
	enum {
		Size = 4
	};

	class Tile {        //小格
	private:
		int value;
		bool state;
	public:
		Tile() : state(false), value(0) {}

		explicit Tile(int num) : state(true), value(num) {}

		void UnSetState() { state = false; }

		void SetState() { state = true; }

		void SetValue(int num) { value = num; }

		bool GetState() const { return state; }

		int GetValue() const { return value; }
	};

	int turn;        //操作次数

	Tile Table_Now[Size][Size];
	//添加后退前进操作
	//Tile Table_Prev[Size][Size];
	//Tile Table_Next[Size][Size];

	int RandomNum() const;

	void AddRandomNum();

	void SetUpBoard();

	void Draw() const;

	//void CopyBoard();

	void RowInvert(int row);

	void RowTighten(int row);

	void RowMerge(int row);

	void MatrixTransform();//矩阵转置
	void MatrixInvert();//矩阵颠倒
	void MatrixTighten();//矩阵靠紧
	void MatrixMerge();//矩阵合并

	bool CanMoveRow(int row) const;

	bool CanMoveMatrix() const;

	bool GameEnd();

	bool IsWin() const;

	bool IsLose() const;


public:
	Board();

	void MoveLeftMatirx();

	void MoveRightMatrix();

	void MoveUpMatrix();

	void MoveDownMatrix();

	void RestartGame();
	//添加后退前进操作
	//void LastMatrix();
	//void NextMatrix();
};


class Manager : public Board {
public:
	void MoveLeft();

	void MoveRight();

	void MoveUp();

	void MoveDown();

	void Restart();
	//void Forward();
	//void Back();
};


#endif //INC_2048_H
