#include "PawnPiece.hh"
#include "ChessBoard.hh"
#include <iostream>


using Student::PawnPiece;
using Student::ChessBoard;

PawnPiece::PawnPiece(ChessBoard &board, Color col, int startRow, int startColumn, Type type)
    : ChessPiece(board, col, startRow, startColumn, type) { }


bool PawnPiece::canMoveToLocation(int toRow, int toColumn){
    int crow = getRow();
    int ccol = getColumn();
    //std::cout << crow <<" "<<ccol<<std::endl;
    std::vector<std::vector<ChessPiece*>>& bard = getBoard().getBoardVec();
    //std::cout<<"here\n";
    if (getColor() == Black)
    {   
        if (crow == 1 && crow + 2 == toRow && ccol == toColumn)
        {
            if (bard.at(toRow).at(ccol) == nullptr && bard.at(toRow - 1).at(ccol) == nullptr )
            {
                return true;
            }
            else {
                return false;
            }
        }
        
        if (crow + 1 != toRow)
        {
            return false;
        }
        if (ccol == toColumn)
        {   
            if (bard.at(toRow).at(ccol) == nullptr)
            {
                return true;
            }
            else {
                /*if (bard.at(toRow).at(ccol)->getColor() == getColor())
                {   
                    return false;
                }
                else {
                    return true;
                }*/
               return false;
                
            }
            
        }
        else if (ccol + 1 == toColumn || ccol - 1 == toColumn)
        {
            if (bard.at(toRow).at(toColumn) == nullptr)
            {
                return false;
            }
            else {
                
                    if (bard.at(toRow).at(ccol)->getColor() == getColor())
                    {
                        return false;
                    }
                    else {
                        return true;
                    }
                
                
            }
            
        }
        else {
            return false;
        }
        
        
    }
    else if (getColor() == White){
        if ((crow == getBoard().getNumRows() - 2) && crow - 2 == toRow && ccol == toColumn)
        {   
            if (bard.at(toRow).at(ccol) == nullptr && bard.at(toRow + 1).at(ccol) == nullptr )
            {
                return true;
            }
            else {
                return false;
            }
        }
        //std::cout<<"here2\n";
        if (crow - 1 != toRow)
        {
            return false;
        }
        if (ccol == toColumn)
        {
            if (bard.at(toRow).at(ccol) == nullptr)
            {
                return true;
            }
            else {
                /*if (bard.at(toRow).at(ccol)->getColor() == getColor())
                {
                    return false;
                }
                else {
                    return true;
                }*/
               return false;
                
            }
            
        }
        else if (ccol + 1 == toColumn || ccol - 1 == toColumn)
        {   
            //std::cout<<"here3\n";
            if (bard.at(toRow).at(toColumn) == nullptr)
            {
                return false;
            }
            else {
                //std::cout<<"here4\n";
                if (bard.at(toRow).at(toColumn)->getColor() == getColor())
                {
                    //std::cout<<"here5\n";
                    return false;
                }
                else {
                   // std::cout<<"here6\n";
                    return true;
                }
                
            }
            
        }
        else {
            return false;
        }
        
    }
    return true;
}

const char* PawnPiece::toString(){
    if (getColor() == 0)
    {
        return "\u265F";
    }
    else
    {
        return "\u2659";
    }
        
        
}
    
    
    
