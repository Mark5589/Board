//
// Created by mark  gurin on 04/05/2018.
//

#include "Board.h"

//Board::Board(int size) {
//    this->size = size;
//    this->board =  int[size][size];
//
//}
Board::Board(int n) {
    this->size = n;
//    board = new char*[size_()];
    board = new Cell*[size_()];
    int i,j;
    for ( i = 0; i < size_(); ++i) {
        this->board[i] = new Cell[size_()];
    }
    for (i = 0; i < size_(); ++i) {
        for (j = 0; j <size_() ; j++) {
            this->board[i][j].setCell('.');
        }
    }
}

Board::~Board() {
    for (int i = 0; i < size_(); ++i) {
        delete [] board[i];
    }
    delete [] board;
}

std::ostream &operator<<(std::ostream &stream, const Board &other) {
    for (int i = 0; i < other.size_(); ++i) {
        for (int j = 0; j < other.size_(); ++j) {
            stream << other.board[i][j].getCell();
        }
        stream<<"\n";
    }
    return stream;
}

//void operator=(std::initializer_list<int> list, char c) {
//    int row = *list.begin();
//    int col = *(list.begin()+1);
//    if()
//
//}


Cell& Board::operator[](std::initializer_list<int> list) {
    int row = *list.begin();
    int col = *(list.begin()+1);
    setX(row);
    setY(col);
    if(row >= (*this).size_() || row < 0 || col >= (*this).size_() || col < 0){
        IllegalCoordinateException ex;
        ex.set(row, col);
        throw ex;
    }


    return this->board[row][col];
}



Board &Board::operator=(char c) {
    if(c == 'X' || c == 'O'){
        int i,j;
        for (i = 0; i < size_(); ++i) {
            for (j = 0; j <size_() ; j++) {
                board[i][j] = c;
            }
        }
        return *this;
    }
    else if( c == '.'){
        int i, j;
        for (i = 0; i < size_(); ++i) {
            for (j = 0; j <size_() ; j++) {
                board[i][j] = '.';
            }
        }
        return *this;
    }


    else{
        IllegalCharException ex;
        ex.setChar(c);
        throw ex;
    }
}

Board &Board::operator=(const Board &other) {
    if((*this).board == other.board)return (*this);

        if((*this).size_() != other.size_()){
            for (int i = 0; i <this->size_() ; ++i) {
                delete[] this->board[i];
            }
            delete[] this->board;

            this->size = other.size_();
            this->board = new Cell*[this->size_()];
            for (int j = 0; j < size_() ; ++j) {
                this->board[j] = new Cell[size_()];
            }

            for (int k = 0; k < (*this).size_(); ++k) {
                for (int i = 0; i < (*this).size_(); ++i) {
                    this->board[k][i] =other.board[k][i];
                }
            }
        }
    return (*this);


}






