// has a
class Heart {
public:
    void beat() {}
};

class Person {
public:
    void BloodCirculation() { heart_.beat(); }
private:
    Heart heart_;
};

int main() {
    // case 1:
    Heart heart(); //not make sense

    //case 2:
    Person p;
    p.BloodCirculation(); //ok
};
