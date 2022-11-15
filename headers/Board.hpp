#pragma once
#include <vector>
#include <string>
#include "Engine.hpp"

struct Piece
{
    bool isAlive;
    std::string name;
    int points;
};

struct Field
{
    Piece whichPiece;
    std::string name;
};

class GameBoard
{
    private:
        Piece Pawn;
        Piece Knight;
        Piece Bishop;
        Piece Queen;
        Piece King;

        std::vector <std::vector <Field>> Board;
    
    public:
        GameBoard() {
            Board.resize(8);
            for (int i = 0; i < 8; i++)
                {
                    Board[i].resize(8);
                }
            char a = 'A';
            for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                        {
                            std::string s (1, a);   
                            std::string z = std::to_string(j + 1);
                            std::string temp = s + z;            
                            Board[i][j].name = temp;
                        }
                    a += 1;
                }
        }
};