#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class MatrixIterator;

class Matrix {
private:
    int nrLines, nrColumns; // the dimension of the matrix
    int capacity; //the capacity
    TElem *Columns; // the array where at position i we have the position from the Lines array where the sequence of elements from column i begins
    TElem *Line; // the array where we store the indexes of the lines
    TElem *Values; // the array where we store the values
    /*TElem Columns[2001] = {0};
    TElem Line[2000000] = {0};
    TElem Values[2000000] = {0};*/
public:
    friend class MatrixIterator;
	//constructor
	Matrix(int nrLines, int nrCols);

	//returns the number of lines
	int nrOfLines() const;

	//returns the number of columns
	int nrOfColumns() const;

	//returns the element from line i and column j (indexing starts from 0)
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem element(int i, int j) const;

	//modifies the value from line i and column j
	//returns the previous value from the position
	//throws exception if (i,j) is not a valid position in the Matrix
	TElem modify(int i, int j, TElem value);

    // get Columns list
    TElem* getColumns() const;

    // get Line list
    TElem* getLine() const;

    // get Values list
    TElem* getValues() const;

    // iterator
    MatrixIterator iterator() const;
};

