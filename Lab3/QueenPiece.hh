#ifndef __QUEENPIECE_H__
#define __QUEENPIECE_H__

#include "ChessPiece.hh"

namespace Student {
    class QueenPiece : public ChessPiece {
    public:
        QueenPiece(ChessBoard& b, Color c, int r, int col, Type t);
        bool canMoveToLocation(int toRow, int toColumn) override;
        const char* toString() override;
    };
}

#endif
