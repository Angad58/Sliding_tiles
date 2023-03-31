#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(string s, string g) : start(s), goal(g)
{
    
}

int Sliding_Solver::Solve_Puzzle()
{
    set<string> visitedStates;

    priority_queue<Board_Tile, vector<Board_Tile>, greater<Board_Tile>> tileQueue;
    
    Board_Tile* initialConfig = new Board_Tile(start);
    Board_Tile FinalConfig(goal);
    initialConfig->setParent(nullptr);
    initialConfig->calculateKey(FinalConfig);
    tileQueue.push(*initialConfig);

    visitedStates.insert(initialConfig->getConfig());
    
    while (!tileQueue.empty()) {
    
      Board_Tile* CurrentBoard = new Board_Tile(tileQueue.top());
      tileQueue.pop();

      if (CurrentBoard->isGoal(FinalConfig.getConfig())) {
        CurrentBoard->printConfig();
        vector<char> moves = CurrentBoard->traceBack();
        for(unsigned int i = 0; i < moves.size(); i++)
        {
            cout<<moves[i];
        }
        return 0;
      }
     vector<Board_Tile*> nextconfigs = CurrentBoard->nextConfigs(FinalConfig);


    for (int i = 0; i < nextconfigs.size(); i++) {
        Board_Tile* child = nextconfigs[i];
        if (visitedStates.find(child->getConfig()) == visitedStates.end()) {
        tileQueue.push(*child);
        visitedStates.insert(child->getConfig());
      } else {
        delete child;
       
      }
    }
}
  cout<<"No Solution"<<endl;
  return 0;
}