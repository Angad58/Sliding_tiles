#include <iostream>
#include "Sliding_Solver.h"

using namespace std;
int main()
{

    string input, start;
    string goal;
    cout << "Enter Initial Configuration(as String): " << endl;
    cin >> input;
    Board_Tile B(input);
    B.setParent(nullptr);
    cout<<"Enter D for default Goal configuration of 0123456780 or \nEnter goal Configuration(as String): "<<endl;
    cin>>input;
    if(input=="D"||input=="d")
    {
        goal = "123456780";
    }
    else
    {
        goal = input;
    }
    start = B.getConfig();
    Sliding_Solver *S = new Sliding_Solver(start, goal);
    S->Solve_Puzzle();
    return 0;
}
