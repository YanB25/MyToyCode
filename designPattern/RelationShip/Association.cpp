#include <string>
using namespace std;

class Television;

class RemoteControl {
private:
    Television* tv;
};

class Television {
public:
    void switchOn();
    void switchOff();
private:
    string name_;
    bool isOn_;
};
