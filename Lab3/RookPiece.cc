#include "RookPiece.hh"
#include "ChessBoard.hh"
#include <iostream>


using Student::RookPiece;
using Student::ChessBoard;

RookPiece::RookPiece(ChessBoard &board, Color col, int startRow, int startColumn, Type type)
    : ChessPiece(board, col, startRow, startColumn, type) { }


bool RookPiece::canMoveToLocation(int toRow, int toColumn){
    int crow = getRow();
    int ccol = getColumn();
    //std::cout << crow <<" "<<ccol<<std::endl;
    std::vector<std::vector<ChessPiece*>>& bard = getBoard().getBoardVec();

    if (crow != toRow && ccol != toColumn)
    {
        return false;
    }
    else if (crow == toRow && ccol == toColumn)
    {
        //std::cout << "here\n";
        return false;
    }
    else if (crow == toRow)
    {   
        if (ccol > toColumn)
        {
            for (int i = ccol-1; i >= toColumn; i--)
            {   
                if (i == toColumn )
                {   
                    if (bard.at(crow).at(i) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(crow).at(i))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                
                if (bard.at(crow).at(i) != nullptr)
                {
                    return false;
                }
                
            }
        } 

        else if (ccol < toColumn)
        {
            for (int i = ccol+1; i <= toColumn; i++)
            {   
                if (i == toColumn )
                {   
                    if (bard.at(crow).at(i) == nullptr)
                    {
                        return true;
                    }
                    else{
                        if ((bard.at(crow).at(i))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                
                if (bard.at(crow).at(i) != nullptr)
                {
                    return false;
                }
                
            }
        } 
    }
    else if (ccol == toColumn)
    {   
        if (crow > toRow)
        {
            for (int i = crow-1; i >= toRow; i--)
            {   
                if (i == toRow )
                {   
                    if (bard.at(i).at(ccol) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(i).at(ccol))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                
                if (bard.at(i).at(ccol) != nullptr)
                {
                    return false;
                }
                
            }
        } 

        else if (crow < toRow)
        {
            for (int i = crow+1; i <= toRow; i++)
            {   
                if (i == toRow )
                {   
                    if (bard.at(i).at(ccol) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(i).at(ccol))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                
                if (bard.at(i).at(ccol) != nullptr)
                {
                    return false;
                }
                
            }
            //return true;
        } 
    }
    return true;
}



const char* RookPiece::toString(){
    if (getColor() == 0)
    {
        return "\u265C";
    }
    else
    {
        return "\u2656";
    }
        
        
}
    
    
    
