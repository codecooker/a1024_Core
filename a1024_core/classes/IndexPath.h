//
//  IndexPath.h
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#ifndef __a1024_core__IndexPath__
#define __a1024_core__IndexPath__

#include <stdio.h>
#include <string>

class Direction;

using std::string;

class IndexPath {
public:
    long x;
    long y;
    IndexPath(long x,long y);
    string toString();
    void goDirection(Direction *direction);
    long vectorIndex(Direction *direction);
};

#endif /* defined(__a1024_core__IndexPath__) */
