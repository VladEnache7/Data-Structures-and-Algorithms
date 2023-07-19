//
// Created by Admin on 29-Mar-23.
//

#include "MatrixIterator.h"

MatrixIterator::MatrixIterator(const Matrix& m) : matrix(m) {
    this->currentIndexInLineList = 0;
}
//Theta(1)

void MatrixIterator::first() {
    this->currentIndexInLineList = 0;
}
//Theta(1)

void MatrixIterator::next() {
    if (this->valid())
        this->currentIndexInLineList++;
}
//Theta(1)

bool MatrixIterator::valid() const {
    return (this->currentIndexInLineList < this->matrix.getColumns()[this->matrix.nrOfColumns()] - 1);
}

TElem MatrixIterator::getCurrent() const {
    if (this->valid())
        return this->matrix.getValues()[this->currentIndexInLineList];
}

