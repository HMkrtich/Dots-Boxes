//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>
#include "Box.h"
#include "Board.h"
#include "Line.h"
Board::Board() {
    this->width = 4;
    this->height = 4;

    player1_score = 0;
    player2_score = 0;

    this->board_squares = new Box*[this->width];
    value size = std::max(this->width, this->height) + 1;

    for (value i = 0; i < this->width; i++) {
        this->board_squares[i] = new Box[this->height];
        for(value j = 0; j < this->height; j++) {
            coordinate top_line = coordinate(0, i, j);
            coordinate bottom_line = coordinate(0, i + 1, j);
            coordinate left_line = coordinate(1, j, i);
            coordinate right_line = coordinate(1, j + 1, i);
            moves.add(top_line);
            moves.add(bottom_line);
            moves.add(left_line);
            moves.add(right_line);
            this->board_squares[i][j] = Box(top_line, bottom_line, left_line, right_line, -1);
        }
    }
}
Board::Board(const value width,const value height)  {
    this->width = width;
    this->height = height;

    player1_score = 0;
    player2_score = 0;

    assert (width > 0 && height > 0);
//    Creating 2 dimensional Box array
    this->board_squares = new Box*[this->width];
//    Creating 3 dimensioal Line array
    value size = std::max(this->width, this->height) + 1;

    for (value i = 0; i < this->width; i++) {
        this->board_squares[i] = new Box[this->height];
        for(value j = 0; j < this->height; j++) {
            coordinate top_line = coordinate(0, i, j);
            coordinate bottom_line = coordinate(0, i + 1, j);
            coordinate left_line = coordinate(1, j, i);
            coordinate right_line = coordinate(1, j + 1, i);
            this->moves.add(top_line);
            this->moves.add(bottom_line);
            this->moves.add(left_line);
            this->moves.add(right_line);

            this->board_squares[i][j] = Box(top_line, bottom_line, left_line, right_line, -1);
        }
    }
    for(value i = 0; i < this->moves.getSize(); i++) {
        std::string key = std::to_string(this->moves.getSet()[i].x) +" "+ std::to_string(this->moves.getSet()[i].y) + " " + std::to_string(this->moves.getSet()[i].z);
        this->coord_index[key] = i;
    }

//
}
value Board::getWidth() {
    return this->width;
}
value Board::getHeight() {
    return this->height;
}





