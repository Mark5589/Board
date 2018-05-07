//
// Created by mark  gurin on 04/05/2018.
//
#pragma once

#ifndef BOARD_BOARD_HPP
#define BOARD_BOARD_HPP

#include <iostream>
#include <initializer_list>
#include <string>
#include "Cell.hpp"
#include "MyException.hpp"

class Board {
    int x,y;
    int size;
    Cell **board;

public:
    Board(int n);
    ~Board();
    int size_()const {return size;}
    friend std::ostream&operator<<(std::ostream& stream , const Board& board);
      Cell& operator[](std::initializer_list<int> list);
//      Board& operator[](std::initializer_list<int> list);
    void setX(int x){this->x = x;}
    void setY(int y){this->y = y;}
    Board&operator=(char c);
    Board&operator=(const Board&other);



};

//void operator=(std::initializer_list<int> list, char c);





#endif //BOARD_BOARD_HPP
