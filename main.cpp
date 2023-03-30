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
          cout<<"Here 1"<<endl;

    B.setParent(nullptr);
          cout<<"Here 2"<<endl;

    goal = "123456780";

      cout<<"Here 3"<<endl;
      cout<<"Here 4"<<endl;
    start = B.getConfig();
      cout<<"Here 5"<<endl;
      cout<<"Here 6"<<endl;
    Sliding_Solver *S = new Sliding_Solver(start, goal);
      cout<<"Here 7"<<endl;
    S->Solve_Puzzle();
      cout<<"Here 8"<<endl;
    B.printConfig();
    return 0;
}
