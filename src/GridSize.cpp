//
// Created by Pawel on 24.04.2021.
//

#include "GridSize.h"
#include <iostream>

GridSize::GridSize(int width, int height): width(width), height(height){

}
GridSize::GridSize(GridSize &&other) noexcept {
    std::cout<<"Before move constructor address: width - "<<&other.width<<" height - "<<&other.height<<std::endl;
//    this->width = std::move(other.width);
//    this->height = std::move(other.height);

    width = other.width;
    height = other.height;

    other.width=0;
    other.height=0;

    std::cout<<"After move constructor address: width - "<<&other.width<<" height - "<<&other.height<<std::endl;

}

GridSize::~GridSize() {

}