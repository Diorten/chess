
#include "../headers/Engine.hpp"
#include <iostream>

#define RESET "\033[0m"
#define WHITE "\033[0;30m\033[47m"
#define BLACK "\033[37m"

void Engine::debugDisplay() const
{
    Map map;
    std::cout << "  A     B     C     D     E     F     G     H\n";
    int a = 0;
    for (int x = 0; x < 4; x++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << WHITE << " " << RESET;
                } 
            }
            else
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << BLACK << " " << RESET;
                }
            }
        }
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << WHITE << "  " << map.magicPieceName(eBoard[a][i].whichPiece.piecesNames) << "  " << RESET;
            }
            else 
            {
                std::cout << BLACK << "  " << map.magicPieceName(eBoard[a][i].whichPiece.piecesNames) << "  " << RESET;
            }
        }
        a += 1;
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << WHITE << " " << RESET;
                } 
            }
            else
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << BLACK << " " << RESET;
                }
            }
        }
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << BLACK << " " << RESET;
                } 
            }
            else
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << WHITE << " " << RESET;
                }
            }
        }
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                std::cout << BLACK << "  " << map.magicPieceName(eBoard[a][i].whichPiece.piecesNames) << "  " << RESET;
            }
            else 
            {
                std::cout << WHITE << "  " << map.magicPieceName(eBoard[a][i].whichPiece.piecesNames) << "  " << RESET;
            }
        }
        a += 1;
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << BLACK << " " << RESET;
                } 
            }
            else
            {
                for (int j = 0; j < 6; j++)
                {
                    std::cout << WHITE << " " << RESET;
                }
            }
        }
        std::cout << "\n";
    }
}


void Engine::movePiece(int x, int y, int wx, int wy)
{
    if (checkIfExists(x, y))
    {
        eBoard[x][y] = eBoard[wx][wy];
        eBoard[wx][wy] = eBoard[0][8];
    }
}

void Engine::playPiece()
{
    while(1)
    {
    int wasY, wasX, newY, newX;
    std::cin >> wasX >> wasY >> newX >> newY;

    if (eBoard[wasX][wasY].whichPiece.piecesNames == King)
    {
        if (checkLegality(newX, newY, wasX, wasY) == true)
        {
            movePiece(newY, newX, wasY, wasX);
        }
    }
    else
        {
            movePiece(newY, newX, wasY, wasX);
        }

    system("clear");
    debugDisplay();
    }
}

bool Engine::checkIfExists(int x, int y) const
{
    if ((x >= 0 && x < 8) && (y >= 0 && y < 8))
    {
        return true;
    }
    std::cout << "Podaj właściwe koordynaty!";
    return false;
}

void Engine::addPoints(bool who, int points)
{
    if (who == true)
    {
        playerScore += points;
        secondScore -= points;
    }
    else
    {
        playerScore -= points;
        secondScore += points;
    }
}

bool Engine::checkLegality(int x, int y, int wx, int wy) const
{
    if (eBoard[wx][wy].whichPiece.isAlive == true)
    {
        switch (eBoard[wx][wy].whichPiece.piecesNames)
        {
        case King:
            if (
                
            )
            break;
        case Queen:

        case Knight:

        case Bishop:

        case Rook:

        case Pawn:

        case Blank:

        default:
            break;
        }
    }
}