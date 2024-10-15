#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
        public:
            PawnPiece(ChessBoard& board, Color col, int startRow, int startColumn, Type type);
            
            bool canMoveToLocation(int toRow, int toColumn);
            const char *toString();
        



    };
}

#endif
