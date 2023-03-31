#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

#include <bits/stdc++.h>
#include "Board.h"
using namespace std;

class Sliding_Solver
{
public:
    Sliding_Solver(string start, string goal);
    int Solve_Puzzle();
private:
    priority_queue<Board_Tile, vector<Board_Tile>, greater<Board_Tile>> tileQueue;
    string start;
    string goal;
};
#endif