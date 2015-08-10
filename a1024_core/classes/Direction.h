//
//  DIrection.h
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#ifndef __a1024_core__DIrection__
#define __a1024_core__DIrection__

#include <stdio.h>

class Direction {
public:
    long x;
    long y;
    Direction(long x,long y);
    bool isLeft();
    bool isRight();
    bool isUp();
    bool isDown();
};

#endif /* defined(__a1024_core__DIrection__) */
