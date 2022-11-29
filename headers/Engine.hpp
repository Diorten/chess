#pragma once
#include "Board.hpp"

class Engine
{
private:
    GameBoard gameBoard;

    int playerScore;
    int timeLeft;
    int secondScore;
    bool false_move;

    std::vector < std::vector <Field>> &eBoard;
    GameState gameState;

public:
    Engine(std::vector < std::vector <Field>> &board_) : eBoard(board_) {
        false_move = false;
        gameState = Running;
    };

    GameState checkStateOfGame() const;

    bool ifThereIsFigure (int y, int x) const;
    void addPoints(bool who, int points);
    void debugDisplay();
    void playGame();
    void movePiece(int x, int y, int wx, int wy);
    bool checkIfExists(int x, int y) const;

    bool checkLegality(int x, int y, int wx, int wy) const;
};