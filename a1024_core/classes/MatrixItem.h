//
//  MatrixItem.h
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#ifndef __a1024_core__MatrixItem__
#define __a1024_core__MatrixItem__

#include <stdio.h>
#include "IndexPath.h"

class MatrixItem {
public:
    IndexPath *newIndex;
    long valueAddr;
    string toString();
    string indexSting();
    virtual ~MatrixItem();
    MatrixItem();
    bool isMerged;
    bool isUsed;
    long value;
};

#endif /* defined(__a1024_core__MatrixItem__) */
