//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>
#ifndef DOTS_LINE_H
#define DOTS_LINE_H
//
// Created by Mkrtich Hovsepyan on 09.04.2023.
//
#include <iostream>

using value = int;
struct coordinate {
    coordinate() = default;
    coordinate(value x, value y, value z, bool status = false): x(x), y(y), z(z), status(status){};
    value x;
    value y;
    value z;
    bool status = false;
    bool getStatus(){
        return this->status;
    }
    void setStatus(){
        this->status = true;
    }
};
class Line {
private:
    coordinate coord;
    bool valid = false;
    bool exists = false;
public:
    Line(value x1, value x2, value x3, bool exists);
    Line(coordinate coord, bool player);
    coordinate getCoord();
    bool getStatus();
    void setStatus();
    bool isValid(){
        return this->valid;
    }
    void setValid(){
        this->valid = true;
    }

    Line();
};

#endif //DOTS_LINE_H
