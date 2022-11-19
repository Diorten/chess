#pragma once
#include <vector>
#include <string>
#include <map>

class Map
{
public:
    const char* magicPieceName(PiecesNames pN)
    {
        const std::map<PiecesNames, const char*> pieceNameType
            {
                {PiecesNames::Blank, "   "},
                {PiecesNames::Pawn, "P "},
                {PiecesNames::Rook, "R "},
                {PiecesNames::Bishop, "B "},
                {PiecesNames::Knight, "N "},
                {PiecesNames::Queen, "Q "},
                {PiecesNames::King, "K "}
            };
        auto it = pieceNameType.find(pN);
        return it == pieceNameType.end() ? "Out of range Type" : it->second;
    };

};

enum PiecesNames
{
    King, Queen, Knight, Bishop, Rook, Pawn, Blank
};

enum GameState
{
    Won, Lost, Running
};

struct Piece
{
    bool isAlive;
    PiecesNames piecesNames;
    int points;
};

struct Field
{
    Piece whichPiece;
    std::string name;
};

class GameBoard
{
public:
    std::vector <std::vector <Field>> Board;
    
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

        Board[0][8].whichPiece.isAlive = false; Board[0][8].whichPiece.piecesNames = Blank; Board[0][8].whichPiece.points = 0;

        Board[0][0].whichPiece.isAlive = true; Board[0][0].whichPiece.piecesNames = Rook; Board[0][0].whichPiece.points = 4;
        Board[7][7].whichPiece = Board[0][7].whichPiece = Board[7][0].whichPiece = Board[0][0].whichPiece;

        Board[0][1].whichPiece.isAlive = true; Board[0][1].whichPiece.piecesNames = Knight; Board[0][1].whichPiece.points = 3;
        Board[0][6].whichPiece = Board[7][1].whichPiece = Board[7][6].whichPiece = Board[0][1].whichPiece;

        Board[7][5].whichPiece.isAlive = true; Board[7][5].whichPiece.piecesNames = Bishop; Board[7][5].whichPiece.points = 3;
        Board[0][2].whichPiece = Board[0][5].whichPiece = Board[7][2].whichPiece = Board[7][5].whichPiece;

        Board[0][3].whichPiece.isAlive = true; Board[0][3].whichPiece.piecesNames = Queen; Board[0][3].whichPiece.points = 8;
        Board[7][3].whichPiece = Board[0][3].whichPiece;

        Board[0][4].whichPiece.isAlive = true; Board[0][4].whichPiece.piecesNames = King; Board[0][4].whichPiece.points = 10;
        Board[7][4].whichPiece = Board[0][4].whichPiece;

        for (auto i = 0; i < 8; i++)
        {
            Board[1][i].whichPiece.isAlive = true;
            Board[1][i].whichPiece.piecesNames = Pawn;
            Board[1][i].whichPiece.points = 1;
        }

        for (auto i = 0; i < 8; i++)
        {
            Board[6][i].whichPiece.isAlive = true;
            Board[6][i].whichPiece.piecesNames = Pawn;
            Board[6][i].whichPiece.points = 1;
        }

        for (auto i = 2; i < 6; i++)
        {
            for (auto j = 0; j < 8; j++)
            {
                Board[i][j].whichPiece.isAlive = false;
                Board[i][j].whichPiece.piecesNames = Blank;
                Board[i][j].whichPiece.points = 0;
            }
        }      
    }
};

//