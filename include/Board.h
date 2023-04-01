#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Board_Tile
{
public:
    /*Constructor, intializes the config of board object with the passed string */
    Board_Tile(const string &s);
    /*Copy Constructor */
    Board_Tile(const Board_Tile &B);
    /*Returns a vector of all possible next configurations of the board object after 1 move*/
    vector<Board_Tile*> nextConfigs(const Board_Tile &g);

    /*Returns the number of moves made from the inital configuration to the current configuration*/
    int numMoves();

    /*Returns the Manhattan distance between the current configuration and the goal configuration*/
    int Manhattan_Distance(const Board_Tile &g);

    /*Returns the configuration of the board object after the move m is made*/
    string move(int t,char m);

    /*Returns the configuration of the board object*/
    string getConfig();

    /*Sets the configuration of the board object*/
    void setConfig(string s);
    /*Prints the configuration in a sliding tiles format*/
    void printConfig();
    /*Returns true if the current configuration is the goal configuration passed as parameter*/
    bool isGoal(const Board_Tile &b); 
    void setParent(Board_Tile* p);
    vector<char> traceBack();
    void calculateKey(const Board_Tile &g);
    Board_Tile* getParent();
   friend bool operator>(const Board_Tile &lhs, const Board_Tile &rhs);
   void setMove(char m);
private:
    string config;
    int key;
    Board_Tile *parent;
    char moveMade;
    
};
#endif
