#include <iostream>
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
        goal = input;
    }
    Board_Tile G(goal);
    // start = B.getConfig();
    // finish = G.getConfig();
    // Sliding_Solver *S = new Sliding_Solver(start, finish);
    // S->Solve_Puzzle();
    G.printConfig();
    return 0;
}
