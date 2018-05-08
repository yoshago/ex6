//
// Created by יהונתן on 07/05/2018.
//

#ifndef UNTITLED1_BOARD_H
#define UNTITLED1_BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "square.h"
#include "IllegalCoordinateException.h"
#include "IllegalCharException.h"

using namespace std;
class Board{

    square** board;
    int size;



public:
    Board(int);
    square& operator [](tuple<int,int> tup);
    friend ostream& operator <<(ostream&, const Board&);
    Board& operator =(char);
    Board& operator =(Board&);


};

#endif //UNTITLED1_BOARD_H
