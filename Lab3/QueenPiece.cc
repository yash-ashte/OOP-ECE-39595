#include "QueenPiece.hh"
#include "ChessBoard.hh"
#include <cmath>

using Student::QueenPiece;

QueenPiece::QueenPiece(ChessBoard &b, Color c, int r, int col, Type t)
    : ChessPiece(b, c, r, col, t) {}

bool QueenPiece::canMoveToLocation(int toRow, int toColumn) {
    int cr = getRow();
    int cc = getColumn();
    auto& bv = getBoard().getBoardVec();

    if (cr == toRow || cc == toColumn) {
        int d = cr == toRow ? (toColumn - cc) : (toRow - cr);
        int s = d > 0 ? 1 : -1;
        if (cr == toRow) {
            for (int i = cc + s; i != toColumn; i += s) {
                if (bv[cr][i] != nullptr) return false;
            }
        } else {
            for (int i = cr + s; i != toRow; i += s) {
                if (bv[i][cc] != nullptr) return false;
            }
        }
    } else if (std::abs(cr - toRow) == std::abs(cc - toColumn)) {
        int rs = toRow > cr ? 1 : -1;
        int cs = toColumn > cc ? 1 : -1;
        for (int i = 1; i < std::abs(toRow - cr); ++i) {
            if (bv[cr + i * rs][cc + i * cs] != nullptr) return false;
        }
    } else {
        return false;
    }

    ChessPiece* t = bv[toRow][toColumn];
    return (t == nullptr || t->getColor() != getColor());
}

const char* QueenPiece::toString() {
    return getColor() == Black ? "\u265B" : "\u2655";
}
