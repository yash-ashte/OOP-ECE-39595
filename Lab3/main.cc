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

void parseConfigFile(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Step 1: Read number of points (ignore for now)
    int points;
    std::getline(file, line);
    std::stringstream(line) >> points;

    std::cout << points << std::endl;

    // Step 2: Read board dimensions
    int rows, cols;
    std::getline(file, line);
    std::stringstream(line) >> rows >> cols;

    std::cout << rows << " " << cols << std::endl;

    // Step 3: Initialize the ChessBoard
    ChessBoard board(rows, cols);

    // Step 4: Parse the initial setup (piece positions)
    while (std::getline(file, line)) {

        if (line == "~") break;

        char color, type;
        int row, col;
        std::stringstream piece_stream(line);
        piece_stream >> color >> type >> row >> col;

        // Create and place the piece on the board
        Color pieceColor = (color == 'b') ? Black : White;
        Type pieceType;
        switch (type) {
            case 'k': pieceType = King; break;
            case 'r': pieceType = Rook; break;
            case 'p': pieceType = Pawn; break;
            case 'b': pieceType = Bishop; break;
            default: continue;
        }
        std::cout << color << " " << type << " " << row << " " << col << std::endl;
        board.createChessPiece(pieceColor, pieceType, row, col);
    }
    std::cout << board.displayBoard().str() << std::endl;
    // Step 5: Parse the tests and execute them
    while (std::getline(file, line)) {
        std::stringstream command(line);
        std::string test_type;
        command >> test_type;

        if (test_type == "movePiece") {
            int fromRow, fromCol, toRow, toCol;
            command >> fromRow >> fromCol >> toRow >> toCol;
            std::cout << "Move from (" << fromRow << ", " << fromCol << ") to ("
                      << toRow << ", " << toCol << ") : " << std::endl; // << (result ? "Valid" : "Invalid") << std::endl;
            bool result = board.movePiece(fromRow, fromCol, toRow, toCol);
            if (result) {std::cout << board.getPiece(toRow, toCol)->getType() << board.getPiece(toRow, toCol)->getColor() << std::endl;}
            std::cout << (result ? "Valid" : "Invalid") << std::endl;
            std::cout << board.displayBoard().str() << std::endl;
        } else if (test_type == "isValidScan") {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    for (int k = 0; k < rows; ++k) {
                        for (int l = 0; l < cols; ++l) {
                            //std::cout << i << j << k << l << std::endl;
                            board.isValidMove(i, j, k, l);
                        }
                    }
                }
            }
            std::cout << "isValidScan completed!" << std::endl;
        } else if (test_type == "underThreatScan") {
            std::cout << "start under Threat scan\n";
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    bool underThreat = board.isPieceUnderThreat(i, j);
                    if (underThreat)
                    {
                        std::cout << "Piece at (" << i << ", " << j << ") is " 
                              << "under threat" << std::endl;
                    }
                    
                    
                }
            }
            std::cout << "underThreatScan completed!" << std::endl;
        }
    }

    file.close();
}





int main()
{
    //test_part1_4x4_1();
    parseConfigFile("./test_files/part2_4x4_1.txt");
    return EXIT_SUCCESS;
}
