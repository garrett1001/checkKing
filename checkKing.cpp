#include <iostream>
#include <string>
#include "chessBoard.h"

using namespace std;

int main()
{
    chessBoard board1;
    char piece;
    int run = 0;
    char board[8][8];
    int game = 1;
  
    do //do while loop for main funtion
    {
        bool emty = true;
    
        for(int row=0; row<8; row++)
        {
            for(int column=0; column<8; column++)
            {
                cin >> board[row][column]; //gets imput and stores it in an array
                
                if(board[row][column] != '.') // checks to see if array is only '.'
                {
                    emty = false;
                }
            }
        }
        
        if(emty == false) //if the array is empty
        {
            board1.setBoard(board); //sets chessBoard
       
            bool whiteKingFound = false;
            bool blackKingFound = false;
        
            for(int row=0; row<8; row++) //iterates through the array
            {
                for(int column= 0; column<8; column++)
                {
                    if(board1.scanSpace(row, column, piece))// checks to see if space is not a '.' and finds what the piece is
                    {
                        if(board1.scanMoves(piece, row, column))// scan thes moves of the piece and checks if there is a king
                        {
                            if(piece == 'a' || piece == 'n' || piece == 'b' || piece == 'r' || piece == 'q' || piece == 'k')//finds a black king
                            {
                                  blackKingFound = true;
                            } 
                    
                            if(piece == 'A' || piece == 'N' || piece == 'B' || piece == 'R' || piece == 'Q' || piece == 'K')//finds a white king
                            {
                                  whiteKingFound = true;
                            }
                        }
                    }
                }
            }
        
            if(blackKingFound == true)// if it has found a black king in check
            {
                cout<<"Game #"<<game<<": black king is in check"<<endl;
                game++;// adds to game count
            }
            else if(whiteKingFound == true)// if it has found a white king in check
            {
                cout<<"Game #"<<game<<": white king is in check"<<endl;
                game++;
            }
            else  // if it has found no king in check
            {
                cout<<"Game #"<<game<<": no king is in check"<<endl;
                game++;
            }
        }
        else // if array is only '.' ends game
        {
            run++;
        }
    }while(run == 0);
  //2 for loops for row/column scanspace
  //check if scanspace is true in loop
  //if true scanmove
    //
  //if false incriment
  
    return 0;
}
