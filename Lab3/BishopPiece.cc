#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include <iostream>


using Student::BishopPiece;
using Student::ChessBoard;

BishopPiece::BishopPiece(ChessBoard &board, Color col, int startRow, int startColumn, Type type)
    : ChessPiece(board, col, startRow, startColumn, type) { }


bool BishopPiece::canMoveToLocation(int toRow, int toColumn){
    std::cout<<"here\n";
    int crow = getRow();
    int ccol = getColumn();
    //std::cout << "nishop move" <<std::endl;
    //std::cout << crow <<" "<<ccol<<std::endl;
    std::vector<std::vector<ChessPiece*>>& bard = getBoard().getBoardVec();

    //IMPLEMENT THISS
    if (crow - toRow == ccol - toColumn)
    {
        std::cout<<"here2\n";
        int lim = crow - toRow;
        if (lim < 0)
        {
            for (int i = 1; i <= abs(lim); i++)
            {
                std::cout<<"here3\n";
                if ((crow + i) == toRow && (ccol + i) == toColumn)
                {   
                    std::cout<<"here4\n";
                   if (bard.at(toRow).at(toColumn) == nullptr)
                    {
                        return true;
                    }
                    else {
                        std::cout<<"her5\n";
                        if ((bard.at(toRow).at(toColumn))->getColor() == getColor())
                        {
                            std::cout<<"here6\n";
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                if (bard.at(crow + i).at(ccol + i) != nullptr)
                {
                    return false;
                }
                
            }
            
        }
        else if (lim > 0)
        {
            for (int i = 1; i <= abs(lim); i++)
            {
                if ((crow - i) == toRow && (ccol - i) == toColumn)
                {   
                    if (bard.at(toRow).at(toColumn) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(toRow).at(toColumn))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                if (bard.at(crow - i).at(ccol - i) != nullptr)
                {
                    return false;
                }
                
            }
        }
        else {
            return false;
        }
        
        
    }

    else if (crow - toRow == -(ccol - toColumn))
    {
        int lim = crow - toRow;
        if (lim < 0)
        {
            for (int i = 1; i <= abs(lim); i++)
            {
                if ((crow + i) == toRow && (ccol - i) == toColumn)
                {   
                   if (bard.at(toRow).at(toColumn) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(toRow).at(toColumn))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                if (bard.at(crow + i).at(ccol - i) != nullptr)
                {
                    return false;
                }
                
            }
            
        }
        else if (lim > 0)
        {
            for (int i = 1; i <= abs(lim); i++)
            {
                if ((crow - i) == toRow && (ccol + i) == toColumn)
                {   
                   if (bard.at(toRow).at(toColumn) == nullptr)
                    {
                        return true;
                    }
                    else {
                        if ((bard.at(toRow).at(toColumn))->getColor() == getColor())
                        {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                    
                }
                if (bard.at(crow - i).at(ccol + i) != nullptr)
                {
                    return false;
                }
                
            }
        }
        else {
            return false;
        }
        
        
    }
  return false;  
}

const char* BishopPiece::toString(){
    if (getColor() == 0)
    {
        return "\u265D";
    }
    else
    {
        return "\u2657";
    }
        
        
}
    
    
    
