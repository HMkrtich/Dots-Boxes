#ifndef DOTS_GAME_H
#define DOTS_GAME_H

#include <iostream>
#include "Board.h"
class Game {
private:
    Board board;
    value player;
    value recursion_count = 0;
    value sizes[3] = {12, 24, 40};

public:
    // Cheking if the game is ended
    Game(const value width, const value height) {
        this->board = Board(width, height);
        this->player = 1;
    }


    // Returns the possible moves
    value best_depth(value k){
        value limit = 10000;
        value depth = 0;
        value product = 1;
        for(value i = k; i> 0;i--){
            product *= i;
            if(product < limit){
                depth++;
            }
            else{
                return depth;
            }
        }
        return depth;
    }
    void start(){
        // Print the board
        // Instructions
        board.show_board();
        std::cout << "Format of coordinate: x, y and direction" << std::endl;
        std::cout << "Directions: right, bottom, left, top" << std::endl;
        std::cout << "Example: 0 0 right" << std::endl;
//        this->board.show_board();
        play();
    }
    std::bitset<12> get_bitset(){
        std::bitset<12> bitset;
        auto moves = this->board.get_moves().getSet();
        for(value i = 0; i < moves.size(); i++){
            if(moves[i].getStatus())
                bitset.set(i);
        }
        return bitset;
    }

    void checkBoard(){
        for (value i = 0; i < this->board.getWidth(); i++) {
            for (value j = 0; j < this->board.getHeight(); j++) {
                if (this->board.getBoardSquares()[i][j].getPlayer() == -1 &&
                    this->board.getBottomLineStatus(i, j) &&
                    this->board.getRightLineStatus(i, j) && this->board.getTopLineStatus(i, j) &&
                    this->board.getLeftLineStatus(i, j)) {
                    this->board.getBoardSquares()[i][j].setPlayer(1);
                    this->board.player1Score();
                }
            }

        }
    }
    // play
    void play(){
        // Check if the game is ended
        if(board.fullBoard()){
            std::cout << "Game ended" << std::endl;
            return;
        }
        // Get user input
        if(player == 1) {
            value x, y;
            std::string direction;
            std::cout << "Enter the coordinate of line: ";
            std::cin >> x >> y >> direction;

            std::cout<<"x is: "<<x<<" y is: "<<y<<" direction is: "<<direction<<std::endl;
            // Check if the move is valid
            if (x >= 0 && x < this->board.getWidth() && y >= 0 && y < this->board.getHeight()) {
                if (direction == "right") {
                    if (this->board.getRightLineStatus(x, y)) {
                        std::cout << "Invalid move" << std::endl;
                        play();
                    }
                    value before = evaluate(this->board);
                    this->board.setRightLineStatus(x, y);
                    checkBoard();
                    value after = evaluate(this->board);
                    this->board.show_board();
                    if (before == after) {
                        player = 2;
                    }

                }else if (direction == "bottom") {
                    if (this->board.getBottomLineStatus(x, y)) {
                        std::cout << "Invalid move" << std::endl;
                        play();
                    }
                    value before = evaluate(this->board);
                    this->board.setBottomLineStatus(x, y);
                    checkBoard();
                    value after = evaluate(this->board);
                    this->board.show_board();
                    if(before == after){
                        player = 2;
                    }

                } else if (direction == "left") {
                    if (this->board.getLeftLineStatus(x, y)) {
                        std::cout << "Invalid move" << std::endl;
                        play();
                    }
                    value before = evaluate(this->board);
                    this->board.setLeftLineStatus(x, y);
                    checkBoard();
                    value after = evaluate(this->board);
                    this->board.show_board();
                    if(before == after){
                        player = 2;
                    }
                } else if (direction == "top") {
                    if (this->board.getTopLineStatus(x, y)) {
                        std::cout << "Invalid move" << std::endl;
                        play();
                    }
                    value before = evaluate(this->board);
                    this->board.setTopLineStatus(x, y);
                    checkBoard();
                    value after = evaluate(this->board);
                    this->board.show_board();
                    if(before == after){
                        player = 2;
                    }
                } else {
                    std::cout << "Invalid move" << std::endl;
                    play();
                }
            } else {
                std::cout << "Invalid move" << std::endl;
                play();
            }

        }
        else if(player == 2) {
            value before = evaluate(this->board);
            auto bestMove = makeBestMove();
            board.setLineStatus(bestMove, player);
            value after = evaluate(this->board);
            board.show_board();
            if (before == after) {
                player = 1;
            }
            else{
                this->board.player2Score();
            }
        }
        play();
    }
    static value evaluate(Board& board){
        value score = 0;
        for(value i = 0; i < board.getWidth(); i++){
            for(value j = 0; j < board.getHeight(); j++){
                if(board.getBoardSquares()[i][j].getPlayer() == 1){
                    score++;
                }
                else if(board.getBoardSquares()[i][j].getPlayer() == 2){
                    score--;
                }
            }
        }
        return score;
    }
    static value evaluate(value arr[], value size){

        value score = 0;
        for(value i = 0; i < size; i++){
            if(arr[i] == 1){
                score++;
            }
            else if(arr[i] == 2){
                score--;
            }
        }
        return score;
    }
    void toArray(value (&arr)[]){
        std::cout<<board.getWidth()*board.getHeight()<<std::endl;
        for(value i = 0; i < board.getWidth(); i++){
            for(value j = 0; j < board.getHeight(); j++){
                std::cout<<i*board.getHeight() + j<<std::endl;
                arr[i*board.getHeight() + j] = board.getBoardSquares()[i][j].getPlayer();
            }
        }
        std::cout<<"Array is: "<<std::endl;
        for(value i = 0; i < board.getWidth()*board.getHeight(); i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"End array"<<std::endl;
    }
    bool getStatus(std::bitset<12> bitSet, coordinate coord){
        for(value i = 0; i < board.get_moves().getSize(); i++){
            if(board.get_moves().getSet()[i].x == coord.x && board.get_moves().getSet()[i].y == coord.y &&
                                            board.get_moves().getSet()[i].z == coord.z){
                if(bitSet[i] == 1)
                    return true;
                else{
                    return false;
                }
            }
        }
    }
    std::tuple<value*,bool> update(value arr[], std::bitset<12> bitSet, value size, value i, value p){
        bool changed = false;
        auto line_coord = board.get_moves().getSet()[i];
//        std::string key = std::to_string(move.x) + std::to_string(move.y) + std::to_string(move.z);
        if(line_coord.x == 0){
            value x = line_coord.y;
            value y = line_coord.z;
            std::string key1 = "1 " + std::to_string(y) + " " + std::to_string(x),
                    key2 = "1 " + std::to_string(y+1) + " " + std::to_string(x),
                    key3 = "0 " + std::to_string(x+1) + " " + std::to_string(y);

            if(bitSet[board.getCoordIndex()[key1]]==1 && bitSet[board.getCoordIndex()[key2]]==1 && bitSet[board.getCoordIndex()[key3]]==1){
                changed = true;
                arr[x*board.getHeight() + y] = p;
            }
            key1 = "1 " + std::to_string(y) + " " + std::to_string(x-1),
            key2 = "1 " + std::to_string(y+1) + " " + std::to_string(x-1),
            key3 = "0 " + std::to_string(x-1) + " " + std::to_string(y);
            if(bitSet[board.getCoordIndex()[key1]]==1 && bitSet[board.getCoordIndex()[key2]]==1 && bitSet[board.getCoordIndex()[key3]]==1){
                changed = true;
                arr[(x-1)*board.getHeight() + y] = p;
            }
        }
        else{
            value x = line_coord.z;
            value y = line_coord.y;
            std::string key1 = "1 " + std::to_string(y+1) + " " + std::to_string(x),
                    key2 = "0 " + std::to_string(x) + " " + std::to_string(y),
                    key3 = "0 " + std::to_string(x+1) + " " + std::to_string(y);
            if(bitSet[board.getCoordIndex()[key1]]==1 && bitSet[board.getCoordIndex()[key2]]==1 && bitSet[board.getCoordIndex()[key3]]==1){
                changed = true;
                arr[x*board.getHeight() + y] = p;
            }
            key1 = "1 " + std::to_string(y-1) + " " + std::to_string(x),
            key2 = "0 " + std::to_string(x) + " " + std::to_string(y-1),
            key3 = "0 " + std::to_string(x+1) + " " + std::to_string(y-1);
            if(bitSet[board.getCoordIndex()[key1]]==1 && bitSet[board.getCoordIndex()[key2]]==1 && bitSet[board.getCoordIndex()[key3]]==1){
                changed = true;
                arr[x*board.getHeight() + y] = p;
            }
        }


        std::tuple<value*,bool> ans = std::tuple(arr, changed);
        return ans;
    }
    value makeBestMove(){
        value bestScore = 1000;
        value bestMove;
        bool found = false;
        MySet validMoves = board.get_moves();
        std::vector<coordinate> moves = validMoves.getSet();

        recursion_count = 0;
        value arr[board.getWidth()*board.getHeight()];
        for(value i = 0; i < board.getWidth(); i++){
            for(value j = 0; j < board.getHeight(); j++){
                arr[i*board.getHeight() + j] = board.getBoardSquares()[i][j].getPlayer();
            }
        }
        auto bitSet = get_bitset();
        for(value i = 0; i < moves.size(); i++) {
            if (bitSet[i] == 0) {
                auto tuple = update(arr, bitSet, board.getWidth()*board.getHeight(),i, 2);
                auto newArr = std::get<0>(tuple);
                value score = minimax(bitSet, newArr, 2, true, -1000, 1000);
                if (score < bestScore) {
                    bestScore = score;
                    bestMove = i;
                }
                found = true;
            }
        }
        if (!found) {
            std::cout << "No valid moves" << std::endl;
            return bestMove;
        }
        return bestMove;
    }
    value minimax(std::bitset<12> bitSet,value *arr, value depth, bool isMaximizing, value alpha, value beta, bool show = false){
        bool found = false;
        value bestScore;
//
        if(depth == 0){
            return evaluate(arr, board.getWidth()*board.getHeight());
        }

        found = false;
        value size = board.get_moves().getSize();
        if(isMaximizing){
            bestScore = -1000;
            for(value i = 0; i < size; i++){
                if(bitSet[i] == 0) {
                    found = true;
                    bitSet[i] = true;
                    auto tuple = update(arr, bitSet, board.getWidth()*board.getHeight(),i,1);
                    auto newArr = std::get<0>(tuple);
                    bool changed = std::get<1>(tuple);
                    value score;
                    if (changed) {
                        score = minimax(bitSet, newArr, depth-1, true, alpha, beta,show);
                    } else {
                        score = minimax(bitSet, newArr, depth-1, false, alpha, beta,show);
                    }
                    bitSet[i] = false;
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, bestScore);
                    if(beta <= alpha){
                        break;
                    }
                }
            }
        }
        else{
            bestScore = 1000;
            for(value i = 0; i < size; i++){
                if(bitSet[i] == 0) {
                    found = true;
                    bitSet[i] = true;
                    auto tuple = update(arr, bitSet,board.getWidth()*board.getHeight(),i,2);
                    auto newArr = std::get<0>(tuple);
                    bool changed = std::get<1>(tuple);
                    value score;
                    if (changed) {
                        score = minimax(bitSet,newArr, depth-1, false, alpha, beta,show);

                    } else {
                        score = minimax(bitSet,newArr, depth-1, true, alpha, beta,show);
                    }
                    bitSet[i] = false;
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, bestScore);
                    if(beta <= alpha){
                        break;
                    }

                }
            }
        }
        if(found) {
//            for(value i = 0; i < board.getWidth(); i++){
//                for(value j = 0; j < board.getHeight(); j++){
//                    std::cout<<arr[i*board.getHeight() + j]<<" ";
//                }
//                std::cout<<std::endl;
//            }
//            std::cout<<"Best score: "<<bestScore<<std::endl;

            return bestScore;
        }
        else {
            return evaluate(arr, board.getWidth()*board.getHeight());
        }
    }
    Board getBoard(){
        return board;
    }
};
#endif //DOTS_GAME_H

