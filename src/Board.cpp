#include "../headers/Board.hpp"
#include <iostream>

#define RESET "\033[0m"
#define WHITE "\033[0;30m\033[47m"
#define BLACK "\033[37m"

void GameBoard::debugDisplay()
{
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
                std::cout << WHITE << "  " << Board[a][i].whichPiece.name << "  " << RESET;
            }
            else 
            {
                std::cout << BLACK << "  " << Board[a][i].whichPiece.name << "  " << RESET;
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
                std::cout << BLACK << "  " << Board[a][i].whichPiece.name << "  " << RESET;
            }
            else 
            {
                std::cout << WHITE << "  " << Board[a][i].whichPiece.name << "  " << RESET;
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


void GameBoard::movePiece(int x, int y, int wx, int wy)
{
    Board[x][y] = Board[wx][wy];
    Board[wx][wy] = Board[0][8];
}

void GameBoard::playPiece()
{
    while(1)
    {
    int wasY, wasX, newY, newX;
    std::cin >> wasX >> wasY >> newX >> newY;

    movePiece(newY, newX, wasY, wasX);

    system("clear");
    debugDisplay();
    }
}