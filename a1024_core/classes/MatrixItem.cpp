//
//  MatrixItem.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/10.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include "MatrixItem.h"


string MatrixItem::toString() {
    return this->newIndex->toString();
}

MatrixItem::~MatrixItem() {
    delete this->newIndex;
}