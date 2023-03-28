#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Board_Tile.h"
using namespace std;

#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

class Sliding_Solver
{
public:
    Sliding_Solver(string start, string goal);
    void Solve_Puzzle();
private:
    std::priority_queue<Board_Tile*> tileQueue;
};

#endif
