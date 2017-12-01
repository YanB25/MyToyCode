#include "Mediator.hpp"
void Mediator::RegisterHandler(User* u) {
    users.push_back(u);
}

void Mediator::ChatHandler(const int& to, const string& msg) {
    bool hasFind = false;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == to) {
            hasFind = true;
            (*it)->GetMessage(msg);
        }
    }
    if (!hasFind) {
        cout << "Are you kidding ? There is no such a guy!" << endl;
    }
}

pair<int, string> Mediator::TradeHandler(const int& to, const int& pay, const string& dressName) {
    bool hasFind = false;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == to) {
            hasFind = true;
            return (*it)->SellBeautifulDress(pay, dressName);
        }
    }
    if (!hasFind) {
        cout << "There is no Such a guy!" << endl;
    }
    return {-1, "no guy"};
}

Mediator* Mediator::Ins = nullptr;

void Mediator::DressInfoHandler(const int& to) {
    bool hasFind = false;
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getId() == to) {
            hasFind = true;
            (*it)->ShowMyCuteDresses();
        }
    }
    if (!hasFind) {
        cout << "There is no Such a guy!" << endl;
    }
}


