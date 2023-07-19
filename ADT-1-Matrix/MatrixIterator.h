#pragma once
#include "Matrix.h"
// the iterator will return the elements of the matrix column by column, starting from line 0, column 0
class MatrixIterator {
    friend class Matrix;
private:
    const Matrix& matrix;
    int currentIndexInLineList;

public:
    explicit MatrixIterator(const Matrix& m);
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;


};
