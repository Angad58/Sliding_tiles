#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(string s, string g) : start(s), goal(g)
{
    
}

int Sliding_Solver::Solve_Puzzle()
{
    set<string> visitedStates;  
    Board_Tile* initialConfig = new Board_Tile(start);
    Board_Tile FinalConfig(goal);
    initialConfig->setParent(nullptr);
    initialConfig->calculateKey(FinalConfig);
    tileQueue.push(initialConfig);

    visitedStates.insert(initialConfig->getConfig());
    
    while (!tileQueue.empty()) {
    
      Board_Tile* CurrentBoard = tileQueue.top();
      tileQueue.pop();

      if (CurrentBoard->isGoal(FinalConfig.getConfig())) {
        vector<char> moves = CurrentBoard->traceBack();
        cout<<"Number of moves made to reach goal: "<<CurrentBoard->numMoves()<<endl;
        cout<<"These are the moves to reach the goal configuration: ";
        for(unsigned int i = 0; i < moves.size(); i++)
        {
            cout<<moves[i];
        }
        return 0;
      }
     vector<Board_Tile*> nextconfigs = CurrentBoard->nextConfigs(FinalConfig);


    for (unsigned int i = 0; i < nextconfigs.size(); i++) {
        Board_Tile* child = nextconfigs[i];
        if (visitedStates.find(child->getConfig()) == visitedStates.end()) {
        tileQueue.push(child);
        visitedStates.insert(child->getConfig());
      } else {
        delete child;
      }
    }
}
  cout<<"No Solution because of odd number of swapped pairs"<<endl;
  return 0;
}
