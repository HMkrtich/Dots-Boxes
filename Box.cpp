//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>
#include "Box.h"


Box::Box(coordinate line_top, coordinate line_bottom, coordinate line_left, coordinate line_right, value player) {
    this->line_top = line_top;
    this->line_bottom = line_bottom;
    this->line_left = line_left;
    this->line_right = line_right;
    this->player = player;
}
Box::Box(){
    this->line_top = coordinate();
    this->line_bottom = coordinate();
    this->line_left = coordinate();
    this->line_right = coordinate();
    this->player = 0;
}
coordinate Box::getLineTopCoord() {
    return this->line_top;
}
coordinate Box::getLineBottomCoord() {
    return this->line_bottom;
}
coordinate Box::getLineLeftCoord() {
    return this->line_left;
}
coordinate Box::getLineRightCoord() {
    return this->line_right;
}
