

#ifndef UNTITLED1_BOARD_H
#define UNTITLED1_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <vector>

#include "square.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;
class Board{

	square** board;
	int size;

public:
	Board(int);
	Board(const Board&);
	square& operator [](vector<int> v);
	friend ostream& operator <<(ostream&, const Board&);
	Board& operator =(char);
	Board& operator =(Board&);
};

#endif //UNTITLED1_BOARD_H
