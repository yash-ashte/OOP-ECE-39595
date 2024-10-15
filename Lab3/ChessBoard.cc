#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

#include <iostream>

using Student::ChessBoard;
using Student::ChessPiece;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}

ChessBoard::ChessBoard(int numRow, int numCol): numRows(numRow), numCols(numCol) {
    board.resize(numRows);
    
    for (int i = 0; i < numRows; i++)
    {
        board[i].resize(numCols, nullptr);
        
    }
    
}



void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
    if (board[startRow][startColumn] != nullptr) {
        delete board[startRow][startColumn];  // Delete the existing piece to avoid memory leaks
    }

    if (ty == Rook) {
        board[startRow][startColumn] = new RookPiece(*this, col, startRow, startColumn, Rook );
    }
    else if (ty == Pawn) {
        board[startRow][startColumn] = new PawnPiece(*this, col, startRow, startColumn, Pawn);
    }
    else if (ty == Bishop)
    {
        board[startRow][startColumn] = new BishopPiece(*this, col, startRow, startColumn, Bishop);
    }
    
}

std::vector<std::vector<ChessPiece *>>& ChessBoard::getBoardVec(){
    return board;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece* piece = board.at(fromRow).at(fromColumn);
    bool f;
    if (piece == nullptr) {
        //std::cout << fromRow << "," << fromColumn << " " << toRow << "," << toColumn << " " << "N" << " " << false << std::endl;
        return false;
    }
    else {
        //std::cout << fromRow << "," << fromColumn << " " << toRow << "," << toColumn << " " << piece->getType() << std::endl ;
        f = piece->canMoveToLocation(toRow,toColumn);
        //std::cout << fromRow << "," << fromColumn << " " << toRow << "," << toColumn << " " << piece->getType() << " " << f << std::endl;
    }

    return f ;   
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece* piece = getPiece(fromRow, fromColumn);
    ChessPiece* target = getPiece(toRow, toColumn);
    bool moved = false;
    if (turn == piece->getColor() && isValidMove(fromRow, fromColumn, toRow, toColumn)){
        if (target != NULL)
        {
            delete target;
        }
        piece->setPosition(toRow,toColumn);
        moved = true;
    }
    if (turn == Black)
    {
        turn = White;
    }
    else{
        turn = Black;
    }
    return false;
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
    bool res = false;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (board.at(i).at(j) != nullptr)
            {
                res = (res || isValidMove(i, j, row, column));
            } 
        }
        
    }
    return res;
    
}

ChessBoard::~ChessBoard() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];  // Free the dynamically allocated ChessPiece
                board[i][j] = nullptr;  // Set the pointer to nullptr after deletion
            }
        }
    }
    // The std::vector itself will clean up its internal memory when destroyed
}



