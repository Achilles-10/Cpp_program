//
// Created by 10299 on 2018/1/25.
//

#ifndef CPPLEARN_GOLF_H
#define CPPLEARN_GOLF_H

const int Len = 40;
struct golf {
	char fullname[Len];
	int handicap;
};

void setgolf(golf &g, const char *name, int hc);

int setgolf(golf &g);

void handicap(golf &, int hc);

void showgolf(const golf &g);

#endif //CPPLEARN_GOLF_H
