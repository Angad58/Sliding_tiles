#include "Board.h"
Board_Tile::Board_Tile(const string &s) : config(s)
{
}
vector<Board_Tile> Board_Tile::nextConfigs()
{
 vector<Board_Tile> nextconfigs;
    for (int i = 0; i < 9; i++)
    {
        if (this->config[i] == '0')
        {
            if (i / 3 == 0)
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'D');
                nextconfigs.push_back(newconfig);
            }
            else if (i / 3 == 1)
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'U');
                nextconfigs.push_back(newconfig);
                newconfig = Board_Tile(this->config);
                newconfig.move(i, 'D');
                nextconfigs.push_back(newconfig);
            }
            else
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'U');
                nextconfigs.push_back(newconfig);
            }
            if (i % 3 == 0)
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'R');
                nextconfigs.push_back(newconfig);
            }
            else if (i % 3 == 1)
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'L');
                nextconfigs.push_back(newconfig);
                newconfig = Board_Tile(this->config);
                newconfig.move(i, 'R');
                nextconfigs.push_back(newconfig);
            }
            else
            {
                Board_Tile newconfig = Board_Tile(this->config);
                newconfig.move(i, 'L');
                nextconfigs.push_back(newconfig);
            }
        }
    }
    return nextconfigs;
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
    if(m =='U'){
        if(t/3 == 1||t/3 == 2){
            swap(config[t],config[t-3]);
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='D'){
        if(t/3 == 0||t/3 == 1){
            swap(config[t],config[t+3]);
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='L'){
        if(t%3 == 1||t%3 == 2){
            swap(config[t],config[t-1]);
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='R'){
        if(t%3 == 0||t%3 == 1){
            swap(config[t],config[t+1]);
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    return config;
}

string Board_Tile::getConfig()
{
    return this->config;
}

void Board_Tile::setConfig(string s)
{
    this->config = s;
}

void Board_Tile::printConfig()
{
    cout << "+-----------------+" << endl;
    cout << "|  "<<config.at(0)<<"  |  "<<config.at(1)<<"  |  "<<config.at(2)<<"  |" << endl;
    cout << "|-----+-----+-----|" << endl;
    cout << "|  "<<config.at(3)<<"  |  "<<config.at(4)<<"  |  "<<config.at(5)<<"  |" << endl;
    cout << "|-----+-----+-----|" << endl;
    cout << "|  "<<config.at(6)<<"  |  "<<config.at(7)<<"  |  "<<config.at(8)<<"  |" << endl;
    cout << "+-----------------+" << endl;
}
bool Board_Tile::isGoal(const Board_Tile &c){
    
    if(this->config == c.config){
        return true;
    }
    else{
        return false;
    }
}