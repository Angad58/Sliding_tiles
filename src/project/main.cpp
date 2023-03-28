#include <iostream>

#include "../include/Board_Tile.h"
#include "Sliding_solver.h"

using namespace std;
int main()
{

    string input, start, finish;
    string goal;
    cout << "Enter Initial Configuration(as String): " << endl;
    cin >> input;
    Board_Tile B(input);
    cout << "Enter Goal Configuration, Enter D for default goal config(123456780): " << endl;
    cin >> input;
    if (input == "D")
    {
        goal = "123456780";
    }
    else
    {
        cin >> goal;
    }
    Board_Tile G(goal);
    start = B.getConfig();
    finish = G.getConfig();
    Sliding_Solver *S = new Sliding_Solver(start, finish);
    S->Solve_Puzzle();

    return 0;
}