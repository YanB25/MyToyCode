#include <iostream>
using namespace std;

class Account {
public:
    Account() : money(0) {}
    Account(double m) : money(m) {}
    void MoneyIn(double m) { money += m; cout << "money is " << money << endl; }
    void MoneyOut(double m) { money -= m; cout << "money is " << money << endl;}
private:
    double money;
};

class Command {
public:
    Command(Account& account) : account_(account) {}
    virtual void excute(double) = 0;
    virtual ~Command(){}
protected:
    Account& account_;
};

class PutInMoneyCommand : public Command {
public:
    using Command::Command;
    virtual void excute(double m) { account_.MoneyIn(m); }
};

class PutOutMoneyCommand : public Command {
public:
    using Command::Command;
    virtual void excute(double m) { account_.MoneyOut(m); }
};

class Invoker {
public:
    void setCommand(Command* c) { command_ = c; }
    Command* getCommand() { return command_; }
    void call(double m) { command_->excute(m); }
private:
    Command* command_;
};

int main() {
    Account account(100);
    Command* moneyIn = new PutInMoneyCommand(account);
    Command* moneyOut = new PutOutMoneyCommand(account);
    Invoker* invoker = new Invoker();

    invoker->setCommand(moneyIn);
    invoker->call(20);
    
    delete invoker->getCommand();
    invoker->setCommand(moneyOut);
    invoker->call(14);

    delete invoker->getCommand();
    delete invoker;
    return 0;
}
