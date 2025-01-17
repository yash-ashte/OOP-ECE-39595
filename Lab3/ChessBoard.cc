#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include "QueenPiece.hh"
#include "KnightPiece.hh"
#include <iostream>

using Student::ChessBoard;
using Student::ChessPiece;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            //std::cout<<row<<column<<std::endl;
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}

ChessBoard::ChessBoard(int numRow, int numCol): numRows(numRow), numCols(numCol) {
    board.resize(numRows);
    
    for (int i = 0; i < numRows; i++)
    {
        board[i].resize(numCols, nullptr);
        
    }
    
}



void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
    if (board[startRow][startColumn] != nullptr) {
        delete board[startRow][startColumn]; // Clean up existing piece to avoid memory leaks
    }

    if (ty == Rook) {
        board[startRow][startColumn] = new RookPiece(*this, col, startRow, startColumn, Rook);
    } else if (ty == Pawn) {
        board[startRow][startColumn] = new PawnPiece(*this, col, startRow, startColumn, Pawn);
    } else if (ty == Bishop) {
        board[startRow][startColumn] = new BishopPiece(*this, col, startRow, startColumn, Bishop);
    } else if (ty == King) {
        board[startRow][startColumn] = new KingPiece(*this, col, startRow, startColumn, King);
    }
    else if (ty == Queen) {
        board[startRow][startColumn] = new QueenPiece(*this, col, startRow, startColumn, Queen);
    } else if (ty == Knight) {
        board[startRow][startColumn] = new KnightPiece(*this, col, startRow, startColumn, Knight);
    }
}

std::vector<std::vector<ChessPiece *>>& ChessBoard::getBoardVec(){
    return board;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece *piece = board.at(fromRow).at(fromColumn);
    if (piece == nullptr) {
        return false;
    }

    // Ensure the piece can legally move to the new location
    if (!piece->canMoveToLocation(toRow, toColumn)) {
        return false;
    }

    // Temporarily move the piece to check if the move would put the king in check
    ChessPiece *target = board.at(toRow).at(toColumn); // Save the piece at the destination
    board.at(toRow).at(toColumn) = piece;
    board.at(fromRow).at(fromColumn) = nullptr;
    piece->setPosition(toRow, toColumn);

    bool kingInCheck = false;

    // Find the player's king and check if it's under threat
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            ChessPiece *p = board.at(i).at(j);
            if (p != nullptr && p->getType() == King && p->getColor() == piece->getColor()) {
                if (isPieceUnderThreat(i, j)) {
                    kingInCheck = true;
                }
            }
        }
    }

    // Undo the move
    board.at(fromRow).at(fromColumn) = piece;
    board.at(toRow).at(toColumn) = target;
    piece->setPosition(fromRow, fromColumn);

    // If the move puts the king in check, it is not valid
    return !kingInCheck;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece* piece = getPiece(fromRow, fromColumn);
    if (piece == nullptr || piece->getColor() != turn || !isValidMove(fromRow, fromColumn, toRow, toColumn)) {
        return false;
    }

    ChessPiece* target = getPiece(toRow, toColumn);
    //bool enPassant = false;

    /*if (piece->getType() == Pawn) {
        auto epTarget = getEnPassantTarget();
        if (toRow == epTarget.first && toColumn == epTarget.second) {
            enPassant = true;
            target = getPiece(fromRow, toColumn); 
        }
    }*/

    board[toRow][toColumn] = piece;
    board[fromRow][fromColumn] = nullptr;
    piece->setPosition(toRow, toColumn);
    if (target != nullptr) {
        delete target;
    }

    if (piece->getType() == Pawn) {
        if ((piece->getColor() == White) &&  (piece->getRow() == 0)) {
            delete piece;
            board[toRow][toColumn] = new QueenPiece(*this, White, toRow, toColumn, Queen);
        }
        else if((piece->getColor() == Black) &&  (piece->getRow() == numRows - 1)) {
            delete piece;
            board[toRow][toColumn] = new QueenPiece(*this, Black, toRow, toColumn, Queen);
        }
    }

    /*if (enPassant) {
        delete target;
        board[fromRow][toColumn] = nullptr;
    } else if (target != nullptr) {
        delete target;
    }
    if (piece->getType() == Pawn && std::abs(toRow - fromRow) == 2) {
        enPassantTarget = {toRow - (toRow > fromRow ? 1 : -1), toColumn};
    } else {
        enPassantTarget = {-1, -1};
    }*/

    turn = (turn == White) ? Black : White;
    return true;
}


bool ChessBoard::isPieceUnderThreat(int row, int column) {
    ChessPiece *piece = board.at(row).at(column);
    if (piece == nullptr) {
        return false;
    }

    // Loop through all pieces on the board
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            ChessPiece *attacker = board.at(i).at(j);
            if (attacker != nullptr && attacker->getColor() != piece->getColor()) {
                if (attacker->canMoveToLocation(row, column)) {
                    return true; // There is a direct attack to this position
                }
            }
        }
    }

    return false;
}

float ChessBoard::scoreBoard() {
    wScore = 0;
    bScore = 0;
    for (int i = 0; i < numRows; i++) 
    {
        for (int j = 0; j < numCols; j++){
            ChessPiece* piece = getPiece(i,j);
            if (piece != NULL)
            {
                if (piece->getColor() == White)
                {
                    if (piece->getType() == King)
                    {
                        wScore += 200;
                    }
                    else if (piece->getType() == Queen)
                    {
                        wScore += 9;
                    }
                    else if (piece->getType() == Rook)
                    {
                        wScore += 5;
                    }
                    else if (piece->getType() == Knight || piece->getType() == Bishop)
                    {
                        wScore += 3;
                    }
                    else
                    {
                        wScore += 1;
                    }
                    
                }
                else
                {
                     if (piece->getType() == King)
                    {
                        bScore += 200;
                    }
                    else if (piece->getType() == Queen)
                    {
                        bScore += 9;
                    }
                    else if (piece->getType() == Rook)
                    {
                        bScore += 5;
                    }
                    else if (piece->getType() == Knight || piece->getType() == Bishop)
                    {
                        bScore += 3;
                    }
                    else
                    {
                        bScore += 1;
                    }
                    
                }
                for (int k = 0; k < numRows; k++)
                {
                    for (int l = 0; l < numCols; l++)
                    {
                        if (isValidMove(i,j,k,l)){
                            if (piece->getColor() == White){
                                wScore += 0.1;
                            }
                            else{
                                bScore += 0.1;
                            }
                        }
                    }
                    
                }
                
                
            }
            
        }
    }
    return (turn == White)? wScore - bScore : bScore - wScore;
    
}

float ChessBoard::getHighestNextScore() {
    return 0.0;
}


ChessBoard::~ChessBoard() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (board[i][j] != nullptr) {
                delete board[i][j];  // Free the dynamically allocated ChessPiece
                board[i][j] = nullptr;  // Set the pointer to nullptr after deletion
            }
        }
    }
    // The std::vector itself will clean up its internal memory when destroyed
}



