//
//  DIrection.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include "Direction.h"
#include <stdlib.h>

Direction::Direction(long x,long y) {
    if (labs(x) != 0) {
        this->x = labs(x) / labs(x);
    }
    if (labs(y) != 0) {
        this->y = labs(y) / labs(y);
    }
}

bool Direction::isRight() {
    if (this->x == 1 && this->y == 0) {
        return true;
    }
    return false;
}

bool Direction::isLeft() {
    if (this->x == -1 && this->y == 0) {
        return true;
    }
    return false;
}

bool Direction::isUp() {
    if (this->x == 0 && this->y == -1) {
        return true;
    }
    return false;
}

bool Direction::isDown() {
    if (this->x == 0 && this->y == 1) {
        return true;
    }
    return false;
}