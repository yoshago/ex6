
#include "Board.h"
Board::Board(int size) {
    this->size =size;
    this->board = new square*[size];
    for (int i=0;i<size;i++) {
        board[i] = new square[size];
    }
}
ostream & operator<<(ostream & os,const Board & b) {
    for(int i = 0;i<b.size;i++){
        for(int j = 0;j<b.size;j++){
           os<<b.board[i][j];
        }
        os<<"\n";
    }
    return os;
}

Board& Board::operator=(char c) {
    if(c=='X'||c=='O'||c=='.') {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                this->board[i][j] = c;
            }
        }
    }
    else throw IllegalCharException(c);
    return *this;
}
Board& Board::operator=(Board & b) {
    free(this->board);
    this->size = b.size;
    this->board = new square*[b.size];
    for (int i=0;i<b.size;i++) {
        board[i] = new square[b.size];
    }
    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < b.size; j++) {
            this->board[i][j] = b.board[i][j];
        }
    }
    return *this;
}
square& Board::operator[](tuple<int, int> t) {
    if(get<0>(t)>=0&&get<1>(t)>=0&&get<0>(t)<size&&get<1>(t)<size){
        return this->board[get<0>(t)][get<1>(t)];
    }
    else throw IllegalCoordinateException(get<0>(t),get<1>(t));

}


