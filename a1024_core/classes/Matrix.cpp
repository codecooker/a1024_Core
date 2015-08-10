//
//  Matrix.cpp
//  a1024_core
//
//  Created by 焉逢 on 15/8/5.
//  Copyright (c) 2015年 codecooker.com. All rights reserved.
//

#include "Matrix.h"

Matrix::Matrix() {
    this->colCount = 0;
    this->rowCount = 0;
}

Matrix::Matrix(long colCount,long rowCount) {
    this->colCount = colCount;
    this->rowCount = rowCount;
    this->reset(colCount, rowCount,&this->data);
}

Matrix::~Matrix() {
    delete this->data;
}

void Matrix::vectorGoDirection(vector<MatrixItem*> aVector,Direction *direction) {
    if (direction->isRight() || direction->isDown()) {
        for (long i = aVector.size() - 1; i >= 0; --i) {
            long directionCount = 0;
            for (long j = i + 1; j < aVector.size(); ++j) {
                if (aVector.at(j)->value == 0) {
                    directionCount++;
                    continue;
//                    aVector.at(i)->newIndex->goDirection(direction);
                }else if(aVector.at(j)->value == aVector.at(i)->value && !aVector.at(j)->isMerged){
//                    aVector.at(i)->newIndex->goDirection(direction);
                    aVector.at(j)->value += aVector.at(i)->value;
                    aVector.at(i)->value = 0;
                    aVector.at(j)->isMerged = true;
                    directionCount = 0;
                }else {
                    break;
                }
            }
            if (directionCount) {
                aVector[i + directionCount]->value = aVector[i]->value;
                aVector[i]->value = 0;
            }
        }
    }else if(direction->isLeft() || direction->isUp()){
        for (long i = 0; i < aVector.size(); ++i) {
            long directionCount = 0;
            for (long j = i - 1; j >= 0; --j) {
                if (aVector.at(j)->value == 0) {
                    directionCount++;
                    continue;
//                    aVector.at(i)->newIndex->goDirection(direction);
                }else if(aVector.at(j)->value == aVector.at(i)->value && !aVector.at(j)->isMerged){
//                    aVector.at(i)->newIndex->goDirection(direction);
                    aVector.at(j)->value += aVector.at(i)->value;
                    aVector.at(i)->value = 0;
                    aVector.at(j)->isMerged = true;
                }else {
                    break;
                }
            }
            if (directionCount) {
                aVector[i - directionCount]->value = aVector[i]->value;
                aVector[i]->value = 0;
            }
        }
    }
}

void Matrix::syncMatrix() {
//    vector<vector<MatrixItem*>> *aData = NULL;
//    this->reset(this->colCount, this->rowCount, &aData);
    for (size_t i = 0; i < this->data->size(); ++i) {
        vector<MatrixItem*> rowVector = this->data->at(i);
        for (size_t j = 0; j < rowVector.size(); ++j) {
            MatrixItem *item = rowVector.at(j);
//            if (item->value != 0) {
//                aData->at(item->newIndex->y)[item->newIndex->x] = item;
//            }
            item->isMerged = false;
        }
    }
//    this->data = aData;
}

void Matrix::goDirection(Direction *direction) {
    if (direction->isLeft() || direction->isRight()) {
        for (size_t i = 0; i < this->data->size(); ++i) {
            this->vectorGoDirection(this->data->at(i), direction);
        }
    }else if (direction->isUp() || direction->isDown()) {
        for (size_t i = 0; i < this->colCount; ++i) {
            vector<MatrixItem*> colVector = vector<MatrixItem*>();
            for (size_t j = 0; j < this->rowCount; ++j) {
                vector<MatrixItem*> rowVector = this->data->at(j);
                colVector.push_back(rowVector.at(i));
            }
            this->vectorGoDirection(colVector, direction);
            colVector.clear();
        }
    }
//    this->syncMatrix();
}

void Matrix::reset(long colCount, long rowCount, vector<vector<MatrixItem *> > **aData) {
    vector<vector<MatrixItem*>> *data = new vector<vector<MatrixItem*>>();
    for (long i = 0; i < rowCount; ++i) {
        vector<MatrixItem*> *rowVector = new vector<MatrixItem*>();
        for (long j = 0; j < colCount; ++j) {
            MatrixItem *item = new MatrixItem();
            item->newIndex = new IndexPath(j,i);
            rowVector->push_back(item);
        }
        data->push_back(*rowVector);
    }
    *aData = data;
}

string Matrix::toString() {
    string str = "";
    for (size_t i = 0; i < this->data->size(); ++i) {
        vector<MatrixItem*> rowVector = this->data->at(i);
        for (size_t j = 0; j < rowVector.size(); ++j) {
            str += rowVector[j]->toString();
            str += "\t";
        }
        str += "\n";
    }
    return str;
}

string Matrix::indexString() {
    string str = "";
    for (size_t i = 0; i < this->data->size(); ++i) {
        vector<MatrixItem*> rowVector = this->data->at(i);
        for (size_t j = 0; j < rowVector.size(); ++j) {
            str += rowVector[j]->indexSting();
            str += "\t";
        }
        str += "\n";
    }
    return str;
}