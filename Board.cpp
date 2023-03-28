#include "Board.h"
Board_Tile::Board_Tile(const string &s) : config(s)
{
}
vector<Board_Tile> Board_Tile::nextConfigs()
{

}
int Board_Tile::Manhattan_Distance(const Board_Tile &goalconfig)
{
   int distance = 0;
    for (int i = 0; i < 9; i++)
    {
        if (this->config[i] != '0')
        {
            for (int j = 0; j < 9; j++)
            {
                if (this->config[i] == goalconfig.config[j])
                {
                distance += std::abs(i / 3 - j / 3) + std::abs(i % 3 - j % 3);
                }
            }
        }
    }
    return distance;
}

string Board_Tile::move(int t,char m)
{
    if(m =='U')
    if(m =='D')
    if(m =='L')
    if(m =='R')
    return "";
}

string Board_Tile::getConfig()
{
    return this->config;
}

void Board_Tile::setConfig(string s)
{
    this->config = s;
}
