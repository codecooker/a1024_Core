//
//  Matrix.h
//  a1024_core
//
//  Created by 焉逢 on 15/8/5.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#ifndef __a1024_core__Matrix__
#define __a1024_core__Matrix__

#include <stdio.h>
#include <vector>
#include <string>
#include "Direction.h"
#include "MatrixItem.h"

using std::__1::vector;
using std::string;

class Matrix {
    private :
        long colCount;
        long rowCount;
        void vectorGoDirection(vector<MatrixItem*> vector,Direction *direction);
    public :
        Matrix(long colCount,long rowCount);
        Matrix();
        vector<vector<MatrixItem*>> *data;
        string toString();
        string indexString();
        virtual ~Matrix();
        void reset(long colCount,long rowCount,vector<vector<MatrixItem*>> **data);
        void goDirection(Direction *direction);
        void syncMatrix();
};

#endif /* defined(__a1024_core__Matrix__) */
