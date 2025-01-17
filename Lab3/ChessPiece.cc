#include "ChessPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column, Type type)
    : board(board), color(color), row(row), column(column), type(type) {}

Color ChessPiece::getColor(){
    return color;
}


//FIX THIS LATEWR
//FIX
//FIX
Type ChessPiece::getType(){
    return type;
}

int ChessPiece::getRow(){
    return row;
}

int ChessPiece::getColumn(){
    return column;
}

void ChessPiece::setPosition(int row, int column){
    this->row = row;
    this->column = column;
}

ChessBoard& ChessPiece::getBoard(){
    return board;
}


