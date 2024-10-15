#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class RookPiece : public ChessPiece
    {
        public:
            RookPiece(ChessBoard& board, Color col, int startRow, int startColumn, Type type);
            
            bool canMoveToLocation(int toRow, int toColumn);
            const char *toString();
            //~RookPiece();
        
    };
}

#endif
