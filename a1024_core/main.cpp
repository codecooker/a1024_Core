//
//  main.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/5.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include <iostream>
#include "Matrix.h"

int main(int argc, const char * argv[]) {
    std::cout<<"press up down right left"<<std::endl;
    const int blockCount = 10;
    Matrix *matrix = new Matrix(blockCount, blockCount);
    //随机4个方块
    for (int i = 0; i < blockCount * 2; ++i) {
        long x = random() % blockCount;
        long y = random() % blockCount;
        long value = (random() % 2 + 1) * 2;
        while (matrix->data->at(y).at(x)->value != 0) {
            x = random() % blockCount;
            y = random() % blockCount;
        }
        matrix->data->at(y).at(x)->value = value;
        matrix->data->at(y).at(x)->isUsed = true;
    }
    std::cout<<matrix->toString();
    std::cout<<"\n\n\n"<<std::endl;
    
    char operatorChar = 's';
    Direction *direction = new Direction(0,0);
    switch (operatorChar) {
        case 'w':
            direction->y = -1;
            break;
        case 's':
            direction->y = 1;
            break;
        case 'a':
            direction->x = -1;
            break;
        case 'd':
            direction->x = 1;
            break;
        default:
            break;
    }
    matrix->goDirection(direction);
    std::cout<<matrix->toString();
    return 0;
}
