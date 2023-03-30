#include <iostream>
#include "Sliding_Solver.h"

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
    priority_queue<Board_Tile, vector<Board_Tile>, greater<Board_Tile>> tileQueue;
    Board_Tile G(goal);
    B.nextConfigs();
    for(int i=0;i<B.nextConfigs().size();i++)
    {
        B.nextConfigs()[i].Manhattan_Distance(G);
        tileQueue.push(B.nextConfigs()[i]);
        
    }
    for(int i=0;i<B.nextConfigs().size();i++)
    {
        Board_Tile temp = tileQueue.top();
        cout << temp.getConfig() << endl;
        tileQueue.pop();
    }
    // start = B.getConfig();
    // finish = G.getConfig();
    // Sliding_Solver *S = new Sliding_Solver(start, finish);
    // S->Solve_Puzzle();
    G.printConfig();
    return 0;
}
