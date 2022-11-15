#pragma once
#include <vector>
#include <string>

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
                    Board[i].resize(9);
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

            Board[0][8].whichPiece.isAlive = false; Board[0][8].whichPiece.name = "  "; Board[0][8].whichPiece.points = 0;

            Board[0][0].whichPiece.isAlive = true; Board[0][0].whichPiece.name = "♜ "; Board[0][0].whichPiece.points = 4;
            Board[7][7] = Board[0][7] = Board[7][0] = Board[0][0];

            Board[0][1].whichPiece.isAlive = true; Board[0][1].whichPiece.name = "♘ "; Board[0][1].whichPiece.points = 3;
            Board[0][6] = Board[7][1] = Board[7][6] = Board[0][1];

            Board[7][5].whichPiece.isAlive = true; Board[7][5].whichPiece.name = "♝ "; Board[7][5].whichPiece.points = 3;
            Board[0][2] = Board[0][5] = Board[7][2] = Board[7][5];

            Board[0][3].whichPiece.isAlive = true; Board[0][3].whichPiece.name = "♛ "; Board[0][3].whichPiece.points = 8;
            Board[7][3] = Board[0][3];

            Board[0][4].whichPiece.isAlive = true; Board[0][4].whichPiece.name = "♚ "; Board[0][4].whichPiece.points = 10;
            Board[7][4] = Board[0][4];

            for (auto i = 0; i < 8; i++)
            {
                Board[1][i].whichPiece.isAlive = true;
                Board[1][i].whichPiece.name = "P ";
                Board[1][i].whichPiece.points = 1;
            }

            for (auto i = 0; i < 8; i++)
            {
                Board[6][i].whichPiece.isAlive = true;
                Board[6][i].whichPiece.name = "P ";
                Board[6][i].whichPiece.points = 1;
            }

            for (auto i = 2; i < 6; i++)
            {
                for (auto j = 0; j < 8; j++)
                {
                    Board[i][j].whichPiece.isAlive = false;
                    Board[i][j].whichPiece.name = "  ";
                    Board[i][j].whichPiece.points = 0;
                }
            }
            
        }

        void debugDisplay();

        void playPiece();
        void movePiece(int x, int y, int wx, int wy);
};
//