#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(string s, string g) : start(s), goal(g)
{
    vector<Board_Tile> nextconfigs;
    Board_Tile B(s);
    nextconfigs = B.nextConfigs();
    for (int i = 0; i < nextconfigs.size(); i++)
    {
        nextconfigs[i].Manhattan_Distance(Board_Tile(g));
        
    }
}

void Sliding_Solver::Solve_Puzzle()
{
    
}