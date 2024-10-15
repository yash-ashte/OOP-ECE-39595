#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
//#include <iostream>

//Delete these later
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using Student::ChessBoard;
using Student::ChessPiece;


void isValidScan(ChessBoard& board) {  // Pass by reference to avoid copying
    int row = board.getNumRows();
    int col = board.getNumCols();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < row; k++) {
                for (int l = 0; l < col; l++) {
                    board.isValidMove(i, j, k, l);
                }
            }
        }
    }
}


void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan


    // Corresponding code
    Student::ChessBoard sBoard(6, 6);
    sBoard.createChessPiece(White, Rook, 4, 3);
    //std::cout << sBoard.getPiece(3,2)->canMoveToLocation(3,2)<<std::endl;
    sBoard.createChessPiece(White, Pawn, 3, 5);
    sBoard.createChessPiece(White, Rook, 3, 1);
    sBoard.createChessPiece(Black, Pawn, 5, 3);
    sBoard.createChessPiece(White, Pawn, 4, 5);
    sBoard.createChessPiece(Black, Pawn, 4, 3);
    //std::cout<<sBoard.getPiece(4,3)->getType()<<std::endl;
    //std::cout<<sBoard.getPiece(4,3)->getColor()<<std::endl;
    std::cout << sBoard.displayBoard().str() << std::endl;
    isValidScan(sBoard);
    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.
    
    return;
}






int main()
{
    test_part1_4x4_1();
    //parseConfigFile("./test_files/part1_4x4_1.txt");
    return EXIT_SUCCESS;
}
