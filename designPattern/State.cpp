#include <iostream>
using namespace std;
class LightBase;

class State {
public:
    virtual void handler(LightBase& light) = 0;
    virtual ~State() {}
};

class LightBase {
public:
    virtual void setState(State* ) = 0;
    virtual State* getState() const = 0;
    virtual ~LightBase() {}
};

class On : public State {
public:
    virtual void handler(LightBase& light); 
    ~On() {}
};

class Off : public State {
public:
    virtual void handler(LightBase& light);
    ~Off() {}
};
void Off::handler(LightBase& light) {
    cout << "the state switch to OFF" << endl;
    delete light.getState();
    light.setState(new On());
};

void On::handler(LightBase& light) {
    cout << "the state switch to ON" << endl;
    delete light.getState();
    light.setState(new Off());
}

class Light : public LightBase {
public:
    Light() : state_(new On()) {}
    Light(State* state) : state_(state) {}
    ~Light() { delete state_; }
    virtual void setState(State* state) { state_ = state; }
    virtual State* getState() const { return state_; }

    void press(){ state_->handler(*this); }
private:
    State* state_;
};


int main() {
    Light light;
    for (int i = 0; i < 10; ++i) {
        light.press();
    }
    return 0;
}
