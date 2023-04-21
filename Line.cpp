//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>
#include "Line.h"


Line::Line(value x1, value x2, value x3, bool free) {
    this->coord = coordinate(x1, x2, x3);
    this->exists = free;
}
Line::Line(coordinate coord, bool free) {
    this->coord = coord;
    this->exists = free;
}
coordinate Line::getCoord() {
    return this->coord;
}
bool Line::getStatus(){
    return this->exists;
}
void Line::setStatus() {
    this->exists = true;
}

Line::Line() {
    this->coord = coordinate(0, 0, 0);
    this->exists = false;

}
