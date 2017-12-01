#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Subject;

class Observer {
public:
    virtual void update(Subject& ) = 0;
};

class Subject {
public:
    virtual void attach(Observer*) = 0;
    virtual void dettach(Observer*) = 0;
    virtual void notify() = 0;
    virtual void setState(int ) = 0; 
    virtual int getState() = 0; 
protected:
    int state;
};

class ConcreteSubject : public Subject{
public:
    ConcreteSubject() { setState(0); }
    virtual void attach(Observer* o) { observers_.push_back(o); }
    virtual void dettach(Observer* o) { 
        for (auto it = observers_.begin(); it != observers_.end(); ++it) {
            if (o == *it) {
                observers_.erase(it);
            }
        }
    }
    virtual void notify() {
        for (auto it = observers_.begin(); it != observers_.end(); ++it) {
            (*it)->update(*this);
        }
    }
    virtual void setState(int s) { state = s; }
    virtual int getState() { return state; }
private:
    vector<Observer*> observers_;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(string name) : name_(name) {}
    virtual void update(Subject& sub) {
        cout << "I am " << name_ << " and I see that it's state is " << sub.getState() << endl;
    }
private:
    string name_;
};

int main() {
    ConcreteSubject sub;
    ConcreteObserver ob1("Liu HongMei");
    ConcreteObserver ob2("XiaoMing");
    
    sub.attach(&ob1);
    sub.attach(&ob2);
    sub.setState(5);
    sub.notify();

    sub.dettach(&ob1);
    sub.setState(1);
    sub.notify();

    return 0;
}
