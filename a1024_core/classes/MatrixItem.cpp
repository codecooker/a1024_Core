//
//  MatrixItem.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include "MatrixItem.h"
#include <stdlib.h>

MatrixItem::MatrixItem() {
    this->isMerged = false;
    this->value = 0;
    this->isUsed = false;
}

string MatrixItem::toString() {
    char *stringData = (char *)malloc(10);
    sprintf(stringData, "%ld",this->value);
    return stringData;
}

string MatrixItem::indexSting() {
    return this->newIndex->toString();
}

MatrixItem::~MatrixItem() {
    delete this->newIndex;
}