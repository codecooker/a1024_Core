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
    Matrix *matrix = new Matrix(2, 1);
    char operatorChar = '\0';
    while (scanf("%c",&operatorChar)) {
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
        std::cout<<"\n\n\n\n"<<std::endl;
    }
    return 0;
}
