#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board_Tile
{
public:
    Board_Tile(const string &s);
    vector<Board_Tile> nextConfigs();
    int numMoves();
    int Manhattan_Distance(const Board_Tile &goalconfig);
    string getConfig();
    void setConfig(string s);

private:
    string config;
    string movesFromStart;
};