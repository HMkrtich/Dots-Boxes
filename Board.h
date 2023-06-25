//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//

#ifndef DOTS_BOARD_H
#define DOTS_BOARD_H
#include <iostream>
#include <vector>
#include <set>
#include "Box.h"
#include "MySet.h"
#include <map>



// Board class
class Board {
private:
    unsigned long width = 4;
    unsigned long height = 4;
    Box **board_squares;
    MySet moves;
    std::unordered_map<std::string, value> coord_index;
    bool newSquare = false;
    value player1_score;
    value player2_score;
public:
    Board();
    Board(const value width, const value height);

//    Copy constructor
    Board(const Board &board){
        this->width = board.width;
        this->height = board.height;

        player1_score = 0;
        player2_score = 0;

        this->board_squares = new Box*[this->width];
        value size = std::max(this->width, this->height) + 1;

        for (value i = 0; i < this->width; i++) {
            this->board_squares[i] = new Box[this->height];
            for(value j = 0; j < this->height; j++) {
                this->board_squares[i][j] = board.board_squares[i][j];
            }
        }
        this->moves = board.moves;

    }
    std::unordered_map<std::string, value> getCoordIndex(){
        return this->coord_index;
    }
    value getWidth();

    value getHeight();
    void player1Score(value changed = 1){
        player1_score += changed;
    }
    void player2Score(value changed = 1){
        player2_score += changed;
    }
    value getPlayer1Score(){
        return player1_score;
    }
    value getPlayer2Score(){
        return player2_score;
    }
    bool fullBoard() const{
        if(player1_score + player2_score == width * height){
            return true;
        }
        return false;
    }
    Box **getBoardSquares(){
        return board_squares;
    }
    MySet& getMoves(){
        return this->moves;
    }
    bool getRightLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 1 && this->moves.getSet()[i].y == y+1 && this->moves.getSet()[i].z == x){
                return this->moves.getSet()[i].getStatus();
            }
        }
    }
    bool getBottomLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 0 && this->moves.getSet()[i].y == x+1 && this->moves.getSet()[i].z == y){
                return this->moves.getSet()[i].getStatus();
            }
        }
    }
    bool getLeftLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 1 && this->moves.getSet()[i].y == y && this->moves.getSet()[i].z == x){
                return this->moves.getSet()[i].getStatus();
            }
        }
    }
    bool getTopLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 0 && this->moves.getSet()[i].y == x && this->moves.getSet()[i].z == y){
                return this->moves.getSet()[i].getStatus();
            }
        }
    }
    void setRightLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 1 && this->moves.getSet()[i].y == y+1 && this->moves.getSet()[i].z == x){
                this->moves.getSet()[i].setStatus();
                return;
            }
        }
    }
    void setBottomLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 0 && this->moves.getSet()[i].y == x+1 && this->moves.getSet()[i].z == y){
                this->moves.getSet()[i].setStatus();
                return;
            }
        }
    }
    void setLeftLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 1 && this->moves.getSet()[i].y == y && this->moves.getSet()[i].z == x){
                this->moves.getSet()[i].setStatus();
                return;
            }
        }
    }
    void setTopLineStatus(value x, value y){
        for(value i = 0; i < this->moves.getSize(); i++){
            if(this->moves.getSet()[i].x == 0 && this->moves.getSet()[i].y == x && this->moves.getSet()[i].z == y){
                this->moves.getSet()[i].setStatus();
                return;
            }
        }
    }
    void setLineStatus(value i, value player){
        this->moves.getSet()[i].setStatus();
        auto line_coord = this->moves.getSet()[i];
//       Check if new square is created
        if(line_coord.x == 0){
            value x = line_coord.y;
            value y = line_coord.z;
            if(this->getLeftLineStatus(x, y) && this->getBottomLineStatus(x, y) && this->getRightLineStatus(x, y)){
                this->newSquare = true;
                this->board_squares[x][y].setPlayer(player);
            }
            if(this->getRightLineStatus(x-1, y) && this->getTopLineStatus(x-1, y) && this->getLeftLineStatus(x-1, y)){
                this->newSquare = true;
                std::cout<<"New Square"<<std::endl;

                this->board_squares[x-1][y].setPlayer(player);
            }
        }
        else{
            value x = line_coord.z;
            value y = line_coord.y;
            if(this->getBottomLineStatus(x, y-1) && this->getLeftLineStatus(x, y-1) && this->getTopLineStatus(x, y-1)){
                this->newSquare = true;
                this->board_squares[x][y-1].setPlayer(player);
            }
            if(this->getBottomLineStatus(x, y) && this->getRightLineStatus(x, y) && this->getTopLineStatus(x, y)){
                this->newSquare = true;
                this->board_squares[x][y].setPlayer(player);
            }
        }
    }
//    Show board
    void showBoard(){
//        print x axis
        std::cout<<"    ";

        for (value i = 0; i < this->height; i++) {
            std::cout << "   " << i << " ";
        }
        std::cout << std::endl;
        for (value i = 0; i < this->width; i++) {
            std::cout<<"    ";
            for (value j = 0; j < this->height; j++) {
                if (!this->getTopLineStatus(i, j))
                    std::cout << "*-  -";
                else {
                    std::cout << "*----";
                }
                if(j == this->height - 1){
                    std::cout << "*";
                }
            }
            std::cout<<std::endl;
            std::cout<<" ";
            std::cout<< i << "  ";
            for (value j = 0; j < this->height; j++) {
                if (!this->getLeftLineStatus(i, j))
                    std::cout << "| ";
                else {
                    std::cout << "I ";
                }
                if(this->board_squares[i][j].getPlayer() == 3)
                    std::cout << "   ";
                else {
                    std::cout <<" "<< this->board_squares[i][j].getPlayer() << " ";
                }
                if(j == this->height - 1){
                    if (!this->getRightLineStatus(i, j))
                        std::cout << "|";
                    else {
                        std::cout << "I";
                    }
                }
            }
            std::cout << std::endl;
            if(i == this->width - 1){
                std::cout<<"    ";
                for (value j = 0; j < this->height; j++) {
                    if (!this->getBottomLineStatus(i, j))
                        std::cout << "*-  -";
                    else {
                        std::cout << "*----";
                    }
                    if(j == this->height - 1){
                        std::cout << "*";
                    }
                }
            }
        }
        std::cout << std::endl;
    }
};

#endif //DOTS_BOARD_H
