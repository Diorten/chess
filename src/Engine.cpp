
#include "../headers/Engine.hpp"
#include <iostream>

#define RESET "\033[0m"
#define WHITE "\033[0;30m\033[47m"
#define BLACK "\033[37m"
#define _king 1
#define _queen 2

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

bool Engine::ifThereIsFigure (int y, int x) const
{
    if (eBoard[y][x].whichPiece.isAlive == true)
    {
        return true;
    }
    std::cout << "Tutaj nie ma figury!";
    return false;
}


void Engine::movePiece(int moveToY, int moveFromY, int moveToX, int moveFromX)
{
    if (checkIfExists(moveToY, moveToX))
    {
        if (ifThereIsFigure(moveFromY, moveFromX))
        {
            eBoard[moveToY][moveToX].whichPiece = eBoard[moveFromY][moveFromX].whichPiece;
            eBoard[moveFromY][moveFromX].whichPiece.isAlive = false;
            eBoard[moveFromY][moveFromX].whichPiece.piecesNames = Blank;
            eBoard[moveFromY][moveFromX].whichPiece.points = 0;
        }
    }
}

void Engine::playGame()
{
    int moveToY, moveToX, moveFromY, moveFromX;
    std::cout << "Podaj rząd figury do przesunięcia: ";
    std::cin >> moveFromY;
    std::cout << "Podaj kolumnę figury do przesunięcia: ";
    std::cin >> moveFromX;
    std::cout << "Podaj rząd gdzie ustawić figurę: ";
    std::cin >> moveToY;
    std::cout << "Podaj kolumnę gdzie ustawić figurę";
    std::cin >> moveToX;

    if (checkLegality(moveToX, moveToY, moveFromX, moveFromY) == true)
    {
        movePiece(moveToY, moveFromY, moveToX, moveFromX);
    }
    //system("clear");
    debugDisplay();
}

bool Engine::checkIfExists(int y, int x) const
{
    if ((y >= 0 && y < 8) && (x >= 0 && x < 8))
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

bool Engine::checkLegality(int x, int y, int wx, int wy)
{
    if (eBoard[wy][wx].whichPiece.isAlive == true)
    { 
        switch (eBoard[wy][wx].whichPiece.piecesNames)
        {
            case King:
            //if (eBoard[y][x].whichPiece.isBlack == false)
                if (checkCastling(wy, wx, y, x) == true)
                {
                    return false;
                }
                else if ((((x - wx) >=-1 && (x - wx) <= 1)) && ((y - wy) >= -1 && (y - wy) <= 1))
                {
                    return true;
                }
                break;
            case Queen:
                if (
                    ((x - wx) == (y - wy))||
                    ((wx - x) == (wy - y))||
                    ((wx - x) == (y - wy))||
                    (wx == x)||
                    (wy == y)
                )
                {
                    if (scanForMove(wy, wx, y, x))
                    {
                        return true;
                    }
                }
                break;
            case Knight:
                if ((((wx - x) * (wy - y)) == 2) || ((wx - x) * (wy - y)) == -2)
                {
                    return true;
                }
                break;
            case Bishop:
                if (((x - wx) == (y - wy))||
                    ((wx - x) == (wy - y))||
                    ((wx - x) == (y - wy)))
                {
                    if (scanForMove(wy, wx, y, x) == true)
                    {
                        return true;
                    }
                }
                break;
            case Rook:
                if ((wx == x) || (wy == y))
                {
                    if (scanForMove(wy, wx, y, x) == true)
                    {
                        return true;
                    }
                } 
                break;
            case Pawn:
                if (eBoard[wy][wx].whichPiece.black == false)
                {
                    if ((wx == x) && (wy == y-1))
                    {
                        if (scanForMove(wy, wx, y, x) == true)
                        {
                            return true;
                        }
                    }
                    else if (eBoard[wy][wx].whichPiece.alredyMoved == false)
                    {
                        if ((wx == x) && (wy == y - 2))
                        {
                            if (scanForMove(wy, wx, y, x) == true)
                            {
                                return true;
                            }
                        }
                    }
                }
                else
                {
                    if ((wx == x) && (wy == y + 1))
                    {
                        if (scanForMove(wy, wx, y, x) == true)
                        {
                            return true;
                        }
                    }
                    else if (eBoard[wy][wx].whichPiece.alredyMoved == false)
                    {
                        if ((wx == x) && (wy == y + 2))
                        {
                            if (scanForMove(wy, wx, y, x) == true)
                            {
                                return true;
                            }
                        }
                    }
                }
                break;
            case Blank:
                return false;
                break;
            default:
                break;
        }
    }
    return false;
}


bool Engine::checkCastling(int kingY, int kingX, int kingMoveY, int kingMoveX)
{
    if (eBoard[kingY][kingX].whichPiece.black == false)
    {
        if (eBoard[kingY][kingX].whichPiece.alredyMoved == false)
        {
            if (kingMoveX == 5)
            {
                if (eBoard[0][7].whichPiece.alredyMoved == false)
                {
                    makeCastlingTrue(0, 4, kingMoveY, kingMoveX, 0, 7, kingY, kingX);
                    return true;
                }
            }
            else if (kingMoveX == 1)
            {
                if (eBoard[0][0].whichPiece.alredyMoved == false)
                {
                    makeCastlingTrue(0, 2, kingMoveY, kingMoveX, 0, 0, kingY, kingX);
                    return true;
                }
            }
        }
    }
    else if (eBoard[kingY][kingX].whichPiece.black == true)
    {
        if (eBoard[kingY][kingX].whichPiece.alredyMoved == false)
        {
            if (kingMoveX == 5)
            {
                if (eBoard[7][7].whichPiece.alredyMoved == false)
                {
                    makeCastlingTrue(7, 4, kingMoveY, kingMoveX, 7, 7, kingY, kingX);
                    return true;
                }
            }
            else if (kingMoveX == 1)
            {
                if (eBoard[7][0].whichPiece.alredyMoved == false)
                {
                    makeCastlingTrue(7, 2, kingMoveY, kingMoveX, 7, 0, kingY, kingX);
                    return true;
                }
            }          
        }
    }
    return false;
}

void Engine::makeCastlingTrue(int rookY, int rookX, int kingY, int kingX, int wrookY, int wrookX, int wkingY, int wkingX)
{
    movePiece(rookY, wrookY, rookX, wrookX);
    movePiece(kingY, wkingY, kingX, wkingX);
}

bool Engine::scanForMove(int fromY, int fromX, int toY, int toX)
{
    switch (eBoard[fromY][fromX].whichPiece.piecesNames)
    {
        case Rook:
            if ((fromX - toX) < 0)
            {
                while (fromX < toX)
                {
                    if (eBoard[fromY][fromX + 1].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromX++;
                }
                return true;
            }
            else if ((fromX - toX) > 0)
            {
                while (fromX > toX)
                {
                    if (eBoard[fromY][fromX - 1].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromX--;
                }
                return true;
            }
            else if ((fromY - toY) < 0)
            {
                while (fromY < toY)
                {
                    if (eBoard[fromY + 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromY++;
                }
                return true;
            }
            else if ((fromY - toY) > 0)
            {
                while (fromY > toY)
                {
                    if (eBoard[fromY - 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                   fromY--;
                }
                return true;
            }
            break;
        case Bishop:
            if (((fromY - toY) < 0) && ((fromX - toX) < 0))
            {
                for (int i = fromY + 1; i < toY; i++)
                {
                    for (int j = fromX + 1; j < toX; j++)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) < 0) && ((fromX - toX) > 0))
            {
                for (int i = fromY + 1; i < toY; i++)
                {
                    for (int j = fromX - 1; j > toX; j--)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) > 0) && ((fromX - toX) > 0))
            {
                for (int i = fromY - 1; i > toY; i--)
                {
                    for (int j = fromX - 1; j > toX; j--)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) > 0) && ((fromX - toX) < 0))
            {
                for (int i = fromY - 1; i > toY; i--)
                {
                    for (int j = fromX + 1; j < toX; j++)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case Pawn:
            if ((fromY - toY) < 0)
            {
                while (fromY < toY)
                {
                    if (eBoard[fromY + 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromY++;
                }
                return true;
            }
            else if ((fromY - toY) > 0)
            {
                while (fromY > toY)
                {
                    if (eBoard[fromY - 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromY--;
                }
                return true;
            }
            break;
        case Queen:
            if (((fromX - toX) < 0) && ((fromY - toY) == 0))
            {
                while (fromX < toX)
                {
                    if (eBoard[fromY][fromX + 1].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromX++;
                }
                return true;
            }
            else if (((fromX - toX) > 0) && ((fromY - toY) == 0))
            {
                while (fromX > toX)
                {
                    if (eBoard[fromY][fromX - 1].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromX--;
                }
                return true;
            }
            else if (((fromY - toY) < 0) && ((fromX - toX) == 0))
            {
                while (fromY < toY)
                {
                    if (eBoard[fromY + 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromY++;
                }
                return true;
            }
            else if (((fromY - toY) > 0) && ((fromX - toX) == 0))
            {
                while (fromY > toY)
                {
                    if (eBoard[fromY - 1][fromX].whichPiece.isAlive == true)
                    {
                        return false;
                    }
                    fromY--;
                }
                return true;
            }
            else if (((fromY - toY) < 0) && ((fromX - toX) < 0))
            {
                for (int i = fromY + 1; i < toY; i++)
                {
                    for (int j = fromX + 1; j < toX; j++)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) < 0) && ((fromX - toX) > 0))
            {
                for (int i = fromY + 1; i < toY; i++)
                {
                    for (int j = fromX - 1; j > toX; j--)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) > 0) && ((fromX - toX) > 0))
            {
                for (int i = fromY - 1; i > toY; i--)
                {
                    for (int j = fromX - 1; j > toX; j--)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            else if (((fromY - toY) > 0) && ((fromX - toX) < 0))
            {
                for (int i = fromY - 1; i > toY; i--)
                {
                    for (int j = fromX + 1; j < toX; j++)
                    {
                        if (eBoard[i][j].whichPiece.isAlive == true)
                        {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case King:
        //no nic tu nie ma do sprawdzania kurwa xD
            break;
        case Blank:
        //tutaj tez
            break;
        case Knight:
        //no i tutaj to juz wgl 
            break;
    }
    return false;
}

bool Engine::checkPromotion(int wasY, int wasX, int willY, int willX)
{
    return false;
}