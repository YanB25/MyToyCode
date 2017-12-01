// Interface:
class Interface_Readable {
public:
    virtual void read() = 0;
};

class Interface_ReadableAndWritable : public Readable {
public:
    virtual void write() = 0;
};

// Class
class Person {

};

class Student : Person {

};
