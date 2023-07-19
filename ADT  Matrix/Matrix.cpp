#include "Matrix.h"
#include "MatrixIterator.h"
#include <exception>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
    if (nrLines <= 0 || nrCols <= 0)
        throw exception();
    this->nrLines = nrLines;
    this->nrColumns = nrCols;
    this->Columns = new TElem[nrCols + 1];
    for (int i = 0; i <= nrCols; ++i) {
        this->Columns[i] = 0;
    }

    this->capacity = (nrLines * nrCols);
    this->Line = new TElem[this->capacity];
    this->Values = new TElem[this->capacity];
    // initializing the Line & Values arrays
    this->Line[0] = 0;
    this->Values[0] = 0;
}
//Theta(1)


int Matrix::nrOfLines() const {
    return this->nrLines;
}
//Theta(1)

int Matrix::nrOfColumns() const {
    return this->nrColumns;
}
//Theta(1)

TElem Matrix::element(int i, int j) const {
    // if (i, j) is not a valid position
    if (j < 0 || j >= this->nrOfColumns() || i < 0 || i >= this->nrOfLines())
        throw exception();
    // searching for the element
    for (int index = this->Columns[j]; index < this->Columns[j + 1]; ++index) {
        if (this->Line[index] == i)
            return this->Values[index];
    }
    // in case (i, j) was not found in the matrix, than it's zero
    return NULL_TELEM;
}
//Best case: Theta(1), Worst case: Theta(nrLines) => Total complexity: O(nrLines)


TElem Matrix::modify(int i, int j, TElem value) {
    // if (i, j) is not a valid position
    if (j < 0 || j >= this->nrOfColumns() || i < 0 || i >= this->nrOfLines())
        throw exception();
    // in case (i, j) is already a non-zero value in the matrix
    {
        for (int index = this->Columns[j]; index < this->Columns[j + 1] ; ++index) {
            if (this->Line[index] == i) {
                TElem returnedValue = this->Values[index];
                if (value == 0) // if value is zero, then (i, j) should be deleted from the Values array
                {
                    // deleting (i, j) from the Line & Values arrays
                    for (int deleteIndex = index; deleteIndex < this->Columns[this->nrColumns] - 1; ++deleteIndex) {
                        this->Line[deleteIndex] = this->Line[deleteIndex + 1];
                        this->Values[deleteIndex] = this->Values[deleteIndex + 1];
                    }
                    this->Line[this->Columns[this->nrColumns]] = 0;
                    this->Values[this->Columns[this->nrColumns]] = 0;

                    //decreasing the starting positions in Columns array
                    for (int l = j + 1; l <= this->nrColumns; ++l) {
                        this->Columns[l]--;
                    }
                    return returnedValue;
                } else {
                    this->Values[index] = value;
                }
                return returnedValue;
            }
        }
    }

    // in case (i, j) is a zero value in the matrix -> add it
    /*for (int index = this->Columns[j]; index < this->Columns[j + 1] + (this->Columns[j] == this->Columns[j + 1]); ++index) { // find its index in Line & Values arrays
        if (i > this->Line[index] || (index == this->Columns[j] && i < this->Line[index])) {    //while the index on that column is less, just increase the index
            // make space for it in Line & Values arrays
            for (int addIndex = this->Columns[this->nrColumns]; addIndex > index; --addIndex) {
                this->Line[addIndex] = this->Line[addIndex - 1];
                this->Values[addIndex] = this->Values[addIndex - 1];
            }
            // add the value in Line & Values
            this->Line[index] = i;
            this->Values[index] = value;

            // increasing the starting positions in Columns array
            for (int l = j + 1; l <= this->nrColumns; ++l) {
                this->Columns[l]++;
            }
            return NULL_TELEM;
            break; // after adding just break
        }
    }*/

    // make space for it in Line & Values arrays
    for (int addIndex = this->Columns[this->nrColumns]; addIndex > this->Columns[j]; --addIndex) {
        this->Line[addIndex] = this->Line[addIndex - 1];
        this->Values[addIndex] = this->Values[addIndex - 1];
    }
    // add the value in Line & Values
    this->Line[this->Columns[j]] = i;
    this->Values[this->Columns[j]] = value;

    // increasing the starting positions in Columns array
    for (int l = j + 1; l <= this->nrColumns; ++l) {
        this->Columns[l]++;
    }
    return NULL_TELEM;
}
//Best case: Theta(1), Worst case: Theta(nrLines) => Total complexity: O(nrLines)

TElem *Matrix::getColumns() const {
    return this->Columns;
}

TElem *Matrix::getLine() const {
    return this->Line;
}

TElem *Matrix::getValues() const {
    return this->Values;
}

MatrixIterator Matrix::iterator() const {
    return MatrixIterator(*this);
}

//MatrixIterator Matrix::iterator() const {
//}


