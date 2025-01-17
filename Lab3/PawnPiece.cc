#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include <iostream>


using Student::PawnPiece;
using Student::ChessBoard;

PawnPiece::PawnPiece(ChessBoard &board, Color col, int startRow, int startColumn, Type type)
    : ChessPiece(board, col, startRow, startColumn, type) { }


bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
    int crow = getRow();
    int ccol = getColumn();
    auto& boardVec = getBoard().getBoardVec();
    int direction = (getColor() == White) ? -1 : 1;

    // Single-step forward
    if (toRow == crow + direction && toColumn == ccol && boardVec[toRow][toColumn] == nullptr) {
        return true;
    }

    // Two-step forward
    if (toRow == crow + 2 * direction && toColumn == ccol &&
        crow == (getColor() == White ? 6 : 1) &&
        boardVec[toRow][toColumn] == nullptr &&
        boardVec[crow + direction][toColumn] == nullptr) {
        return true;
    }

    // Capture diagonally
    if (toRow == crow + direction && (toColumn == ccol - 1 || toColumn == ccol + 1)) {
        ChessPiece* target = boardVec[toRow][toColumn];
        if (target != nullptr && target->getColor() != getColor()) {
            return true;
        }

        // Check en passant
        auto epTarget = getBoard().getEnPassantTarget();
        if (epTarget.first == toRow && epTarget.second == toColumn) {
            return true;
        }
    }

    return false;
}

const char* PawnPiece::toString(){
    if (getColor() == 0)
    {
        return "\u265F";
    }
    else
    {
        return "\u2659";
    }
        
        
}
    
    
    
