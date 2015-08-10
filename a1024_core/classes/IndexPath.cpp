//
//  IndexPath.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include "IndexPath.h"
#include <stdlib.h>
#include "Direction.h"

IndexPath::IndexPath(long x,long y) {
    this->x = x;
    this->y = y;
}

string IndexPath::toString() {
    char *stringData = (char *)malloc(100);
    sprintf(stringData, "(%ld,%ld)",this->x,this->y);
    return std::__1::string(stringData);
}

void IndexPath::goDirection(Direction *direction) {
    this->x += direction->x;
    this->y += direction->y;
}
