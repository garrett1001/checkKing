#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_
#include <iostream>

class chessBoard
{
    private:
    
    char board[8][8];
    
    public:
    
    void setBoard(char value[8][8]);
    bool scanSpace(int row, int column, char& piece);
    bool scanMoves(char piece, int row, int column);
       
};

#endif
