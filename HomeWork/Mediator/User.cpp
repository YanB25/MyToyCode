#include "User.hpp"
#include "Mediator.hpp"
int User::Count = 0;
User::User(const string& n, const int& m, const vector<pair<string, int>>& d) : name(n), money(m) {
    id = Count++;
    for (auto item : d) {
        dresses.emplace_back(item.first, item.second);
    }
}
void User::BuyBeautifulDress(const int& id, const int& pay, const string& name) {
    if (pay > money) {
        cout << this->name << " : " << "Forget to Check Wallet!" << endl;
        return;
    }
    auto p = Mediator::getInstance()->TradeHandler(id, pay, name); 
    if (p.first == -1) {
        if (p.second == "No money") {
            cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
        } else if (p.second == "no dress") {
            cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
        } else if (p.second != "no guy"){
            cout << "ERROR " << p.first << " " << p.second << endl;
        }
    } else {
        dresses.emplace_back(p.second, p.first); 
        money -= pay;
        cout << this->name << " : " << "So happy to get new Dress!" << endl;
        cout << ">>> and they are " << p.first << " " << p.second << endl; //TODO
    }
}

void User::GetDressInfo(const int& i) {
    cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
    Mediator::getInstance()->DressInfoHandler(i);
}

pair<int, string> User::SellBeautifulDress(const int& pay, const string& dname) {
    bool hasFind = false;
    for (int i = 0; i < dresses.size(); ++i) {
        if (dresses[i].getName() == dname) {
            hasFind = true;
            if (pay < dresses[i].getPrice()) {
                cout << this->name << " : " << "No money then no talking" << endl;
                return {-1, "No money"};
            } else {
                cout << this->name << " : " << "What a good taste you have !" << endl;
            dresses.erase(dresses.begin() + i);
                money += pay;
                return pair<int, string>(pay, dname);
            }
        }
    }
    if (!hasFind) {
        cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
    }
    return pair<int, string>(-1, "no dress");
}

void User::ShowMyCuteDresses() {
    cout << this->name << " : ok,these are all I have : "<<endl;
    for (int i = 0; i < dresses.size(); ++i) {
        cout << dresses[i].getName() << "-" << dresses[i].getPrice() << endl; //TODO
        //cout << dresses[i].getName() << "-" << "10" << endl; 
    }
}

void User::SendMessage(const int& to, const string& msg) {
    Mediator::getInstance()->ChatHandler(to, msg);
}

void User::GetMessage(const string& msg) {
    cout << this->name <<" : I got a Msg - " << msg << endl;
}
