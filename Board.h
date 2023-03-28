#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board_Tile
{
public:
    /*Constructor, intializes the config of board object with the passed string */
    Board_Tile(const string &s);
    /*Returns a vector of all possible next configurations of the board object after 1 move*/
    vector<Board_Tile> nextConfigs();

    /*Returns the number of moves made from the inital configuration to the current configuration*/
    int numMoves();

    /*Returns the Manhattan distance between the current configuration and the goal configuration*/
    int Manhattan_Distance(const Board_Tile &goalconfig);

    /*Returns the configuration of the board object after the move m is made*/
    string move(int t,char m);

    /*Returns the configuration of the board object*/
    string getConfig();

    /*Sets the configuration of the board object*/
    void setConfig(string s);

private:
    string config;
    string movesFromStart;
};