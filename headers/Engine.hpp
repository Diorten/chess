#pragma once
#include "Board.hpp"

class Engine
{
private:
    GameBoard gameBoard;

    int playerScore;
    int timeLeft;
    int secondScore;

    std::vector < std::vector <Field>> &eBoard;
    GameState gameState;

public:
    Engine(std::vector < std::vector <Field>> &board_) : eBoard(board_) {
        gameState = Running;
    };

    GameState checkStateOfGame() const;

    void debugDisplay() const;
    void playPiece();
    void movePiece(int x, int y, int wx, int wy);
};