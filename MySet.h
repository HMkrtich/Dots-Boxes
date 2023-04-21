//
// Created by Mkrtich Hovsepyan on 14.04.2023.
//

#ifndef DOTS_MYSET_H
#define DOTS_MYSET_H
#include <iostream>
#include "Line.h"
#include <vector>

class MySet {
private:
    value size;
    std::vector<coordinate> set;
public:
    MySet(){
        this->size = 0;
    }
    MySet(const MySet &mySet){
        this->size = mySet.size;
        for(value i = 0; i < mySet.set.size(); i++)
            this->set.push_back(mySet.set[i]);
    }

    void add(coordinate coord){
        std::cout<<this->set.size()<<std::endl;
        for(value i = 0; i < set.size(); i++){
            std::cout<<i<<std::endl;
            if(this->set[i].x == coord.x && this->set[i].y == coord.y && this->set[i].z == coord.z){
                return;
            }
        }
        std::cout<<7<<std::endl;
        this->set.push_back(coord);
        this->size++;
    }
    void remove(coordinate coord){
        for(value i = 0; i < this->size; i++){
            if(this->set[i].x == coord.x && this->set[i].y == coord.y && this->set[i].z == coord.z){
                this->set.erase(this->set.begin() + i);
                this->size--;
                return;
            }
        }
    }
    constexpr value getSize() const{
        return this->size;
    }
    bool isEmpty(){
        return this->size == 0;
    }
    std::vector<coordinate> &getSet(){
        return this->set;
    }



};
#endif //DOTS_MYSET_H
