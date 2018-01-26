//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_MOVE_H
#define CPPLEARN_MOVE_H

class Move {
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);

	void showmove() const;

	Move add(const Move &m) const;

	void reset(double a = 0, double b = 0);
};

#endif //CPPLEARN_MOVE_H