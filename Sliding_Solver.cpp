#include "Sliding_Solver.h"

Sliding_Solver::Sliding_Solver(string s, string g) : start(s), goal(g)
{
    
}

int Sliding_Solver::Solve_Puzzle()
{
    set<string> visitedStates;
    // cout<<"Here 9"<<endl;
    priority_queue<Board_Tile, vector<Board_Tile>, greater<Board_Tile>> tileQueue;
    // cout<<"Here 10"<<endl;
    Board_Tile* initialConfig = new Board_Tile(start);
    // cout<<"Here 11"<<endl;
    initialConfig->setParent(nullptr);
    // cout<<"Here 11.5"<<endl;
    initialConfig->calculateKey();
    // cout<<"Here 12"<<endl;
    tileQueue.push(*initialConfig);
    // cout<<"Here 13"<<endl;
    visitedStates.insert(initialConfig->getConfig());
    while (!tileQueue.empty()) {
    
    // cout<<"Here 14"<<endl;
      Board_Tile* CurrentBoard = new Board_Tile(tileQueue.top());
      //CurrentBoard->printConfig();
      // cout<<"Parent:"<<endl;
      // CurrentBoard->getParent()->printConfig();
        // cout<<"Here 15"<<endl;
      tileQueue.pop();
        // cout<<"Here 16"<<endl;

      if (CurrentBoard->isGoal()) {
        // cout<<"Here 17"<<endl;
        CurrentBoard->printConfig();
        vector<char> moves = CurrentBoard->traceBack();
        // cout<<"Here 18"<<endl;
        for(unsigned int i = 0; i < moves.size(); i++)
        {
            cout<<moves[i];
        }
        // cout<<"\nHere 20"<<endl;
        return 0;
      }
     vector<Board_Tile*> nextconfigs = CurrentBoard->nextConfigs();
        // cout<<"Here 21"<<endl;


    for (int i = 0; i < nextconfigs.size(); i++) {
        //  cout<<"Here 22"<<endl;
        Board_Tile* child = nextconfigs[i];
        if (visitedStates.find(child->getConfig()) == visitedStates.end()) {
            //  cout<<"Here 23.1"<<endl;
        tileQueue.push(*child);
        // cout<<"Pushing "<<endl;
        // child->printConfig();
        // cout<<"Parent of the pushed child"<<endl;
        // child->getParent()->printConfig();
        // cout<<endl<<"In PQ"<<endl;
        // cout<<"Here 23.2"<<endl;
        visitedStates.insert(child->getConfig());
      } else {
        //  cout<<"Here 23.5"<<endl;
            // child->printConfig();
        delete child;
       
      }
    }
}
  cout<<"No Solution"<<endl;
  return 0;
}