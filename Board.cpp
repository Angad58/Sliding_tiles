#include "Board.h"
Board_Tile::Board_Tile(const string &s) : config(s)
{
   
}
Board_Tile::Board_Tile(const Board_Tile &b)
{
    //cout<<"Copy Constructor"<<endl;
    this->config = b.config;
    this->parent = b.parent;
    this->moveMade = b.moveMade;
}
vector<Board_Tile*> Board_Tile::nextConfigs()
{
 vector<Board_Tile*> nextconfigs;
    for (int i = 0; i < 9; i++)
    {
        if (this->config[i] == '0')
        {
            if (i / 3 == 0)
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'D');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
            else if (i / 3 == 1)
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'U');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
                newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'D');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
            else
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'U');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
            if (i % 3 == 0)
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'R');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
            else if (i % 3 == 1)
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'L');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
                newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'R');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
            else
            {
                Board_Tile* newconfig = new Board_Tile(this->config);
                newconfig->move(i, 'L');
                newconfig->setParent(this);
                nextconfigs.push_back(newconfig);
            }
        }
    }
    for(int i=0;i<nextconfigs.size();i++){
        nextconfigs[i]->calculateKey();
    }
    // for(int i=0;i<nextconfigs.size();i++){
    //     cout<<"Next Config:"<<endl;
    //     nextconfigs[i]->printConfig();
    //     cout<<"Parent Config:"<<endl;
    //     nextconfigs[i]->getParent()->printConfig();
    //     cout<<"Move made from parent: "<<nextconfigs[i]->moveMade<<endl;
    // }
    return nextconfigs;
}
int Board_Tile::Manhattan_Distance()
{
    string goal = "123456780";
   int distance = 0;
    for (int i = 0; i < 9; i++)
    {
        if (this->config[i] != '0')
        {
            for (int j = 0; j < 9; j++)
            {
                if (this->config[i] == goal[j])
                {
                distance += std::abs(i / 3 - j / 3) + std::abs(i % 3 - j % 3);
                }
            }
        }
    }
    return distance;
}
void Board_Tile::setMove(char M){
    this->moveMade = M;
}
string Board_Tile::move(int t,char m)
{
    if(m =='U'){
        if(t/3 == 1||t/3 == 2){
            swap(config[t],config[t-3]);
            this->setMove(m);
            //cout<<"Move maid: "<<this->moveMade<<endl;
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='D'){
        if(t/3 == 0||t/3 == 1){
            swap(config[t],config[t+3]);
            this->setMove(m);
           // cout<<"Move maid: "<<this->moveMade<<endl;
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='L'){
        if(t%3 == 1||t%3 == 2){
            swap(config[t],config[t-1]);
            this->setMove(m);
           // cout<<"Move maid: "<<this->moveMade<<endl;
        }
        else{
            cout << "Invalid Move" << endl;
            return "";
        }
    }
    if(m =='R'){
        if(t%3 == 0||t%3 == 1){
            swap(config[t],config[t+1]);
            this->setMove(m);
            //cout<<"Move maid: "<<this->moveMade<<endl;
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
    if(this==nullptr){
        cout<<"NULL"<<endl;
    }
    else{
    cout << "+-----------------+" << endl;
    cout << "|  "<<config.at(0)<<"  |  "<<config.at(1)<<"  |  "<<config.at(2)<<"  |" << endl;
    cout << "|-----+-----+-----|" << endl;
    cout << "|  "<<config.at(3)<<"  |  "<<config.at(4)<<"  |  "<<config.at(5)<<"  |" << endl;
    cout << "|-----+-----+-----|" << endl;
    cout << "|  "<<config.at(6)<<"  |  "<<config.at(7)<<"  |  "<<config.at(8)<<"  |" << endl;
    cout << "+-----------------+" << endl;
    }
}
bool Board_Tile::isGoal(){
    
    if(this->config == "123456780"){
        return true;
    }
    else{
        return false;
    }
}

int Board_Tile::numMoves()
{
    
    int numMoves = 0;
    Board_Tile *Board = this;
    while (Board->parent != nullptr) {
      numMoves++;
      Board = Board->parent;
    }

    return numMoves;
}

void Board_Tile::setParent(Board_Tile *p)
{
    this->parent = p;
}

vector<char> Board_Tile::traceBack()
{
    //cout<<"start"<<endl;
    vector<char> moves;
    int numMoves = 0;
    //cout<<"s1"<<endl;
    Board_Tile *Board = new Board_Tile(this->getConfig());
    Board = this;
   // cout<<"s2"<<endl;
    while (Board->parent != nullptr) {
       // cout<<"s3 start while"<<endl;
      moves.push_back(Board->moveMade);
      numMoves++;
     // cout<<"Move = "<<Board->moveMade<<endl;
      //  cout<<"s4"<<endl;
      Board = Board->parent;
      //  cout<<"s5 end while"<<endl;
    }
    //cout<<"s6"<<endl;
    reverse(moves.begin(), moves.end());
   // cout<<"s7"<<endl;
    // for(int i=0;i<moves.size();i++){
    //     cout<<moves[i]<<endl;
    // }
    cout<<"Number of moves: "<<numMoves<<endl;
    return moves;
}

void Board_Tile::calculateKey()
{
    this->key = numMoves() + Manhattan_Distance();
}

Board_Tile* Board_Tile::getParent()
{
    return this->parent;
}
string Board_Tile::output(Board_Tile* p){
    string output = "";
    output = p->getParent()->getConfig();
    return output;
}
bool operator>(const Board_Tile &lhs, const Board_Tile &rhs)
{
    if (lhs.key > rhs.key)
        return true;
    else
    return false;
}
