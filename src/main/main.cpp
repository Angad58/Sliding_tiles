#include <iostream>
#include "Sliding_Solver.h"

using namespace std;
int main()
{

    string input, start, goal;
    cout << "Enter Initial Configuration(as String): " << endl;
    cin >> input;
    Board_Tile B(input);
    B.setParent(nullptr);
    
    cout<<"Enter D for default Goal configuration of 123456780 or \nEnter goal Configuration(as String): "<<endl;
    cin>>input;
    if(input=="D"||input=="d")
    {
        goal = "123456780";
    }
    else
    {
        goal = input;
    }
    Board_Tile G(goal);
    cout<<"Initial Configuration: "<<endl;
    B.printConfig();
    cout<<"Goal Configuration: "<<endl;
    G.printConfig();
    start = B.getConfig();
    Sliding_Solver *S = new Sliding_Solver(start, goal);
    S->Solve_Puzzle();
    cout<<endl;
    return 0;
}
