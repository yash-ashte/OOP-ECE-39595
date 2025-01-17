#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

namespace Student
{
    class KingPiece : public ChessPiece
    {
    public:
        KingPiece(ChessBoard& board, Color col, int startRow, int startColumn, Type type);
        
        bool canMoveToLocation(int toRow, int toColumn) override;
        const char *toString() override;
    };
}

#endif
