#include "KingPiece.hh"
#include "ChessBoard.hh"
#include <iostream>

using Student::KingPiece;
using Student::ChessBoard;

KingPiece::KingPiece(ChessBoard &board, Color col, int startRow, int startColumn, Type type)
    : ChessPiece(board, col, startRow, startColumn, type) { }

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
    int crow = getRow();
    int ccol = getColumn();
    int rowDiff = abs(crow - toRow);
    int colDiff = abs(ccol - toColumn);

    // Check if the move is within one square in any direction
    if (rowDiff > 1 || colDiff > 1) {
        return false;
    }

    // Ensure the destination is either empty or contains an opponent piece
    ChessPiece *target = getBoard().getPiece(toRow, toColumn);
    if (target == nullptr || target->getColor() != getColor()) {
        return true;
    }

    return false;
}

const char* KingPiece::toString() {
    return (getColor() == Black) ? "\u265A" : "\u2654"; // Unicode for Black or White King
}
