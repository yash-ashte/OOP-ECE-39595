#include "KnightPiece.hh"
#include "ChessBoard.hh"
#include <cmath>

using Student::KnightPiece;

KnightPiece::KnightPiece(ChessBoard &b, Color c, int r, int col, Type t)
    : ChessPiece(b, c, r, col, t) {}

bool KnightPiece::canMoveToLocation(int toRow, int toColumn) {
    int cr = getRow();
    int cc = getColumn();
    int rd = std::abs(cr - toRow);
    int cd = std::abs(cc - toColumn);

    if (!((rd == 2 && cd == 1) || (rd == 1 && cd == 2))) {
        return false;
    }

    ChessPiece* t = getBoard().getPiece(toRow, toColumn);
    return (t == nullptr || t->getColor() != getColor());
}

const char* KnightPiece::toString() {
    return getColor() == Black ? "\u265E" : "\u2658";
}
