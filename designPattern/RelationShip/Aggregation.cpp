// almost the same as Association
// contains a
#include <string>
using namespace std;

class Player {
public:
    void getMoney(int m);
private:
    string name_;
    int money_;
};


class Team {
public:
    
private:
    vector<Player*> players_;
};
