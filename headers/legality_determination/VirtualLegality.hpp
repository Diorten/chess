#pragma once
#include "../Board.hpp"

class VirtualLegality
{
public:

    virtual bool legalityChecker(std::vector < std::vector <Field>> &board, int x, int y) = 0;

    virtual ~VirtualLegality() {};
};