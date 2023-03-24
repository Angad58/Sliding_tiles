#include "Board.h"

Board_Tile::Board_Tile(const string &s) : config(s)
{
}
int Board_Tile::Manhattan_Distance(const Board_Tile &goalconfig)
{
    return 0;
}

string Board_Tile::getConfig()
{
    return this->config;
}

void Board_Tile::setConfig(string s)
{
    this->config = s;
}
