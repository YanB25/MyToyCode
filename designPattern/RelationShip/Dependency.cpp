class A;
class B {
public:
    void func1() { 
        B* b = new B();
    }

    void func2(const B& b) {
        //statements
    }

    void func3() {
        B::func();
    }
};
