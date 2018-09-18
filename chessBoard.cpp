#include "chessBoard.h"

void chessBoard::setBoard(char value[8][8]) //sets class array
{
    for(int row=0; row<7; row++)
    {
        for(int column= 0; column<7; column++)
        {
            board[row][column] = value[row][column];
        }
    }
}

bool chessBoard::scanSpace(int row, int column, char& piece) // scans a space in the array to check if it is not a '.' and finds what it is
{
    if(board[row][column] != '.')
    {
       piece = board[row][column];
       return 1;
    }
    else
    {
        return 0;
    }
}

bool chessBoard::scanMoves(char piece, int row, int column)//scans the moves of each different piece
{  
    if(piece == 'a' ||  piece == 'A') //Pawn
    {
        if(piece == 'a') //white pawn
        {
            std::cout<<"a: "<<piece<<std::endl;
            
            char scan1 = board[row-1][column+1];//scans its moves
            char scan2 = board[row-1][column-1];
            
            if(scan1 == 'K' || scan2 == 'K')// checks to see if there is a king in them
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else // black pawn
        {
            std::cout<<"A: "<<piece<<std::endl;
            
            char scan1 = board[row+1][column+1];
            char scan2 = board[row+1][column-1];
            
            if(scan1 == 'k' || scan2 == 'k')
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else if(piece == 'n' ||  piece == 'N') //Knight
    {
        if(piece == 'n') // white knight
        {
            std::cout<<"n: "<<piece<<std::endl;
            
            char scan1 = board[row-1][column-2];//scans its moves
            char scan2 = board[row-2][column-1];
            char scan3 = board[row+1][column+2];
            char scan4 = board[row+2][column+1];
            char scan5 = board[row-1][column+2];
            char scan6 = board[row-2][column+1];
            char scan7 = board[row+1][column-2];
            char scan8 = board[row+2][column-1];
            
            if(scan1 == 'K' || scan2 == 'K' || scan3 == 'K' || scan4 == 'K' || scan5 == 'K' || scan6 == 'K' || scan7 == 'K' || scan8 == 'K')
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
        else // black knight
        {
            std::cout<<"N: "<<piece<<std::endl;
            
            char scan1 = board[row-1][column-2];//scans its moves
            char scan2 = board[row-2][column-1];
            char scan3 = board[row+1][column+2];
            char scan4 = board[row+2][column+1];
            char scan5 = board[row-1][column+2];
            char scan6 = board[row-2][column+1];
            char scan7 = board[row+1][column-2];
            char scan8 = board[row+2][column-1];
            
            if(scan1 == 'k' || scan2 == 'k' || scan3 == 'k' || scan4 == 'k' || scan5 == 'k' || scan6 == 'k' || scan7 == 'k' || scan8 == 'k')
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    else if(piece == 'b' ||  piece == 'B')  //Bishop
    {
        if(piece == 'b') //white bishop
        {
            int count1 = 1;
            char scanDownRight;
            do // do while to check spaces in one direction untill it hits a piece
            {
                scanDownRight = board[row+count1][column+count1];
                count1++;
            }while(scanDownRight == '.');
            
            int count2 = 1;
            char scanDownLeft;
            do
            {
                scanDownLeft = board[row+count2][column-count2];
                count2++;
            }while(scanDownLeft == '.');
            
            int count3 = 1;
            char scanUpLeft; 
            do
            {
                scanUpLeft = board[row-count3][column-count3];
                count3++;
            }while(scanUpLeft == '.');
            
            int count4 = 1;
            char scanUpRight;
            do
            {
                scanUpRight = board[row-count4][column+count4];
                count4++;
            }while(scanUpLeft == '.');
            
            if(scanDownRight == 'K' || scanDownLeft == 'K' || scanUpLeft == 'K' || scanUpRight == 'K') //checks for a king
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else // black bishop
        {
            int count1 = 1;
            char scanDownRight;
            do
            {
                scanDownRight = board[row+count1][column+count1]; // do while to check spaces in one direction untill it hits a piece
                count1++;
            }while(scanDownRight == '.');
            
            int count2 = 1;
            char scanDownLeft;
            do
            {
                scanDownLeft = board[row+count2][column-count2];
                count2++;
            }while(scanDownLeft == '.');
            
            int count3 = 1;
            char scanUpLeft;
            do
            {
                scanUpLeft = board[row-count3][column-count3];
                count3++;
            }while(scanUpLeft == '.');
            
            int count4 = 1;
            char scanUpRight;
            do
            {
                scanUpRight = board[row-count4][column+count4];
                count4++;
            }while(scanUpLeft == '.');
            
            if(scanDownRight == 'k' || scanDownLeft == 'k' || scanUpLeft == 'k' || scanUpRight == 'k')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    else if(piece == 'r' ||  piece == 'R')  //Rook
    {
        if(piece == 'r') // white rook
        {
            int count1 = 1;
            char scanUp;
            do
            {
                scanUp = board[row-count1][column]; // do while to check spaces in one direction untill it hits a piece
                count1++;
            }while(scanUp == '.');
            
            int count2 = 1;
            char scanDown;
            do
            {
                scanDown = board[row+count2][column];
                count2++;
            }while(scanDown == '.');
            
            int count3 = 1;
            char scanRight;
            do
            {
                scanRight = board[row][column+count3];
                count3++;
            }while(scanRight == '.');
            
            int count4 = 1;
            char scanLeft;
            do
            {
                scanLeft = board[row][column+count4];
                count4++;
            }while(scanLeft == '.');
            
            if(scanUp == 'K' || scanDown == 'K' || scanRight == 'K' || scanLeft == 'K')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else // black rook
        {
            int count1 = 1;
            char scanUp;
            do
            {
                scanUp = board[row-count1][column]; // do while to check spaces in one direction untill it hits a piece
                count1++;
            }while(scanUp == '.');
            
            int count2 = 1;
            char scanDown;
            do
            {
                scanDown = board[row+count2][column];
                count2++;
            }while(scanDown == '.');
            
            int count3 = 1;
            char scanRight;
            do
            {
                scanRight = board[row][column+count3];
                count3++;
            }while(scanRight == '.');
            
            int count4 = 1;
            char scanLeft;
            do
            {
                scanLeft = board[row][column+count4];
                count4++;
            }while(scanLeft == '.');
            
            if(scanUp == 'k' || scanDown == 'k' || scanRight == 'k' || scanLeft == 'k')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    else if(piece == 'q' ||  piece == 'Q')  //Queen
    {
        if(piece == 'q') //white queen
        {
            int count1 = 1;
            char scanUp;
            do // do while to check spaces in one direction untill it hits a piece
            {
                scanUp = board[row-count1][column];
                count1++;
            }while(scanUp == '.');
            
            int count2 = 1;
            char scanDown;
            do
            {
                scanDown = board[row+count2][column];
                count2++;
            }while(scanDown == '.');
            
            int count3 = 1;
            char scanRight;
            do
            {
                scanRight = board[row][column+count3];
                count3++;
            }while(scanRight == '.');
            
            int count4 = 1;
            char scanLeft;
            do
            {
                scanLeft = board[row][column+count4];
                count4++;
            }while(scanLeft == '.');
            
            int count5 = 1;
            char scanDownRight;
            do
            {
                scanDownRight = board[row+count5][column+count5];
                count5++;
            }while(scanDownRight == '.');
            
            int count6 = 1;
            char scanDownLeft;
            do
            {
                scanDownLeft = board[row+count6][column-count6];
                count6++;
            }while(scanDownLeft == '.');
            
            int count7 = 1;
            char scanUpLeft;
            do
            {
                scanUpLeft = board[row-count7][column-count7];
                count7++;
            }while(scanUpLeft == '.');
            
            int count8 = 1;
            char scanUpRight;
            do
            {
                scanUpRight = board[row-count8][column+count8];
                count8++;
            }while(scanUpLeft == '.');
            
            if(scanUp == 'K' || scanDown == 'K' || scanRight == 'K' || scanLeft == 'K' || scanDownRight == 'K' || scanDownLeft == 'K' || scanUpLeft == 'K' || scanUpRight == 'K')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else // black queen
        {
            int count1 = 1;
            char scanUp;
            do // do while to check spaces in one direction untill it hits a piece
            {
                scanUp = board[row-count1][column];
                count1++;
            }while(scanUp == '.');
            
            int count2 = 1;
            char scanDown;
            do
            {
                scanDown = board[row+count2][column];
                count2++;
            }while(scanDown == '.');
            
            int count3 = 1;
            char scanRight;
            do
            {
                scanRight = board[row][column+count3];
                count3++;
            }while(scanRight == '.');
            
            int count4 = 1;
            char scanLeft;
            do
            {
                scanLeft = board[row][column+count4];
                count4++;
            }while(scanLeft == '.');
            
            int count5 = 1;
            char scanDownRight;
            do
            {
                scanDownRight = board[row+count5][column+count5];
                count5++;
            }while(scanDownRight == '.');
            
            int count6 = 1;
            char scanDownLeft;
            do
            {
                scanDownLeft = board[row+count6][column-count6];
                count6++;
            }while(scanDownLeft == '.');
            
            int count7 = 1;
            char scanUpLeft;
            do
            {
                scanUpLeft = board[row-count7][column-count7];
                count7++;
            }while(scanUpLeft == '.');
            
            int count8 = 1;
            char scanUpRight;
            do
            {
                scanUpRight = board[row-count8][column+count8];
                count8++;
            }while(scanUpLeft == '.');
            
            if(scanUp == 'k' || scanDown == 'k' || scanRight == 'k' || scanLeft == 'k' || scanDownRight == 'k' || scanDownLeft == 'k' || scanUpLeft == 'k' || scanUpRight == 'k')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    
    else if(piece == 'k' ||  piece == 'K') //King
    {
        if(piece == 'k') //white king
        {
            char scan1 = board[row+1][column]; // checks moves
            char scan2 = board[row-1][column];
            char scan3 = board[row][column+1];
            char scan4 = board[row][column-1];
            char scan5 = board[row+1][column+1];
            char scan6 = board[row-1][column-1];
            char scan7 = board[row+1][column-1];
            char scan8 = board[row-1][column+1];
            
            if(scan1 == 'K' || scan2 == 'K' || scan3 == 'K' || scan4 == 'K' || scan5 == 'K' || scan6 == 'K' || scan7 == 'K' || scan8 == 'K') // sees if one is a king
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
        else //black king
        {
            char scan1 = board[row+1][column];
            char scan2 = board[row-1][column];
            char scan3 = board[row][column+1];
            char scan4 = board[row][column-1];
            char scan5 = board[row+1][column+1];
            char scan6 = board[row-1][column-1];
            char scan7 = board[row+1][column-1];
            char scan8 = board[row-1][column+1];
            
            if(scan1 == 'k' || scan2 == 'k' || scan3 == 'k' || scan4 == 'k' || scan5 == 'k' || scan6 == 'k' || scan7 == 'k' || scan8 == 'k')
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
    } 
}
