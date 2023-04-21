//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>
#include "Line.h"
#ifndef DOTS_BOX_H
#define DOTS_BOX_H

class Box {
private:
//    References of lines
    coordinate line_top;
    coordinate line_bottom;
    coordinate line_left;
    coordinate line_right;


    value player;
public:
    Box(coordinate line_top, coordinate line_bottom, coordinate line_left, coordinate line_right, value player);
    Box();
    coordinate getLineTopCoord();
    coordinate getLineBottomCoord();
    coordinate getLineLeftCoord();
    coordinate getLineRightCoord();
    value getPlayer(){
        return this->player;
    }
    void setPlayer(value player){
        this->player = player;
    }
};

#endif //DOTS_BOX_H
