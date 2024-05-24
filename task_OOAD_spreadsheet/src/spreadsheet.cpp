#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <iomanip>

#include "../header/spreadsheet.h"

SpreadSheet::SpreadSheet()
	: board{nullptr}
	, rowcnt{0}
	, colcnt{0}
{}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)
	: board {new Cell*[rhv.rowcnt]} 
	, rowcnt{rhv.rowcnt}
    , colcnt{rhv.colcnt}
{
	for (size_t i = 0; i < rowcnt; ++i) {
		board[i] = new Cell[colcnt];
			for (size_t j = 0; j < colcnt; ++j) {
				board[i][j] = rhv.board[i][j];
			}
	}
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv) 
{
	board = rhv.board;
	rowcnt = rhv.rowcnt;
    colcnt = rhv.colcnt;
	rhv.board = nullptr;
	rhv.rowcnt = 0;
    rhv.colcnt = 0;
}

SpreadSheet::SpreadSheet(size_t size) 
	: board{new Cell*[size]}
	, rowcnt{size}
    , colcnt{size}
{
	for (size_t i = 0; i < size; ++i) { 
		board[i] = new Cell[size];
	}
}

SpreadSheet::SpreadSheet(size_t row, size_t col)
	: board{new Cell*[row]}
    , rowcnt{row}
    , colcnt{col}
{
	for (size_t i = 0; i < row; ++i) {
		board[i] = new Cell[col];
	}
}

SpreadSheet::~SpreadSheet()
{
	clear();
}

const SpreadSheet& 
SpreadSheet::operator=(const SpreadSheet& rhv) 
{
	if (this != &rhv){
		clear();
    	board = new Cell*[rhv.rowcnt];
    	rowcnt = rhv.rowcnt;
    	colcnt = rhv.colcnt;
		for (size_t i = 0; i < rhv.rowcnt; ++i) {
        	board[i] = new Cell[rhv.colcnt];
				for (size_t j = 0; j < rhv.colcnt; ++j) {
					board[i][j] = rhv.board[i][j];
			}
		}
	}
	return *this;
}

const SpreadSheet& 
SpreadSheet::operator=(SpreadSheet&& rhv) {
	if (this != &rhv) {
		clear();
		rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
		board = rhv.board; 
		rhv.board = nullptr;
		rowcnt = 0;
		colcnt = 0;  	
	}
    return *this;
}


SpreadSheet::Row
SpreadSheet::operator[](size_t pos) {
	return Row(board[pos]);
}

const SpreadSheet::Row
SpreadSheet::operator[](size_t pos) const {
	return Row(board[pos]);
}

void 
SpreadSheet::clear() noexcept {
	for (size_t i = 0; i < rowcnt; ++i) {
		delete [] board[i];
	}
delete [] board;
board = nullptr;
}

std::size_t 
SpreadSheet::row() const {
	return rowcnt;
}
    
std::size_t 
SpreadSheet::col() const {
	return colcnt;
}

void 
SpreadSheet::mirrorH() {
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < colcnt / 2; ++j ) {
			std::swap(board[i][j], board[i][colcnt - j - 1]);
		}
	}
}
 
void 
SpreadSheet::mirrorV() {
	for (size_t i = 0; i < rowcnt / 2; ++i) {
		for (size_t j = 0; j < colcnt; ++j) {
			std::swap(board[i][j], board[rowcnt - 1 - i][j]);
		}
	}
}	


void 
SpreadSheet::mirrorD() {
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = 0; j < i; ++j) {
			std::swap(board[i][j], board[j][i]);
		}
	} 
}
	
void 
SpreadSheet::mirrorSD() {
	for (int i = 0; i < rowcnt; ++i) {
		for (int j = 0; j < colcnt - 1 - i; ++j) {
                std::swap(board[i][j], board[rowcnt - 1 - j][colcnt - 1 - i]);
		}
	}
}

void 
SpreadSheet::rotate(int cnt) {
	if (cnt <= 0) return;
	cnt %= 4;
	
	while(cnt--) {
		Cell** temp = new Cell*[colcnt];
			for (size_t i = 0; i < colcnt; ++i) {
				temp[i] = new Cell[rowcnt];
					for (size_t j = 0; j < rowcnt; ++j) {
						temp[i][j] = board[rowcnt - 1 -j][i];
					}
			}

	size_t new_rowcnt = colcnt;
	size_t new_colcnt = rowcnt;
	
	clear();
	board = temp;
	colcnt = new_colcnt;
	rowcnt = new_rowcnt;
	temp = nullptr;
	}
}
	


void 
SpreadSheet::removeRow(size_t row) {
	if (row >= rowcnt) {
		throw 1;
	}
	for (size_t i = 0; i < rowcnt; ++i) {
		if (i == row) {
			delete[] board[i];
			board[i] = nullptr;
			for (size_t i = row; i < rowcnt; ++i) {
				board[i] = board[i + 1];
			}
		}
	}
	--rowcnt;
}

void 
SpreadSheet::removeRows(std::initializer_list<size_t> rows) {
	for (size_t rowcnt : rows) {
		removeRow(rowcnt);
	}
}
    
void 
SpreadSheet::removeCol(size_t col) {
	if (col >= colcnt) {
		throw 1;
	}
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = col; j < colcnt - 1; ++j) {
			board[i][j] = board[i][j + 1];		
    	}
	}
}

void 
SpreadSheet::removeCols(std::initializer_list<size_t> cols) {
	for (size_t col : cols) {
		removeCol(col);
	 }
}
	
void 
SpreadSheet::resizeRow(size_t r) {
	resize(r, colcnt);	
}

void 
SpreadSheet::resizeCol(size_t c) {
	resize(c, rowcnt);
}

void 
SpreadSheet::resize(size_t r, size_t c) {
	Cell** temp = new Cell*[r];
		for (size_t i = 0; i < r; ++i) {
			temp[i] = new Cell[c];
		}

	size_t min_rowcnt = std::min(r, rowcnt);
	size_t min_colcnt = std::min(c, colcnt);
	for (size_t i = 0; i < min_rowcnt; ++i) {
		for (size_t j = 0; j < min_colcnt; ++j) {
			temp[i][j] = board[i][j];
		}
	}
	clear();
	board = temp;
	rowcnt = r;
	colcnt = c;
	temp = nullptr;
}

SpreadSheet 
SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols) {
	SpreadSheet temp(rows.size(), cols.size());
		size_t row_ind = 0;
		for (size_t i : rows) {
			size_t col_ind = 0;
			for (size_t j : cols) {
				if (i < rowcnt && j < colcnt) {
					temp.board[row_ind][col_ind] = board[i][j];
				}
				++col_ind;
			}
			++row_ind;
  		}
	return temp;
}

SpreadSheet::Row::Row(Cell* row) 
	: row{row}
{}

Cell& 
SpreadSheet::Row::operator[](size_t pos) {
	return row[pos];
}

const Cell& 
SpreadSheet::Row::operator[](size_t pos) const {
	return row[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv) {
	if (lhv.row() != rhv.row() || lhv.col() != rhv.col()) {
		return false;
	}

	for (size_t i = 0; i < rhv.row(); ++i) {
		for (size_t j = 0; j < rhv.col(); ++j) {
			if (lhv[i][j] != rhv[i][j]) {
				return false;
			}
		}
	}
return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv) {
	return !(lhv == rhv);
}

std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) {
	for (size_t i = 0; i < ob.row(); ++i) {
		for (size_t j = 0; j < ob.col(); ++j) {
			out << std::setw(5) << ob[i][j];
		}
		out << std::endl;
	}
return out;
}
