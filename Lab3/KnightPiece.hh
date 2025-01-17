#ifndef __KNIGHTPIECE_H__
#define __KNIGHTPIECE_H__

#include "ChessPiece.hh"

namespace Student {
    class KnightPiece : public ChessPiece {
    public:
        KnightPiece(ChessBoard& b, Color c, int r, int col, Type t);
        bool canMoveToLocation(int toRow, int toColumn) override;
        const char* toString() override;

    };
}

#endif
