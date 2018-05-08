
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
			this->board[i][j].set(b.board[i][j].get());
		}
	}
	return *this;
}
square& Board::operator[](vector<int> v) {
	if(v[0]>=0 && v[1]>=0 && v[0]<size && v[1]<size){
		return this->board[v[0]][v[1]];
	}
	else throw IllegalCoordinateException(v[0],v[1]);

}

Board::Board()
{
	this->size=0;
	this->board=NULL;
}

Board::Board(const Board& b)
{
	this->size=b.size;
	this->board= new square*[size];
	for (int i=0;i<size;i++) {
		board[i] = new square[size];
	}
	for (int i = 0; i < b.size; i++) {
		for (int j = 0; j < b.size; j++) {
			this->board[i][j].set(b.board[i][j].get());
		}
	}
}

Board::~Board(){
    for (int i = 0; i <size ; ++i) {
            delete[] board[i];
    }delete[] board;
}
