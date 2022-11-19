#include "VirtualLegality.hpp"
#include "../Board.hpp"

class KingLegality : public VirtualLegality
{
    std::vector < std::vector <Field>> &boardKL;

public:

    explicit KingLegality(std::vector < std::vector <Field>> &board_) : boardKL(board_) {};

    bool legalityChecker(std::vector < std::vector <Field>> &board, int x, int y) override;
};