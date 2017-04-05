#include <QCoreApplication>
#include <QVector>

#include <iostream>

/**
 * @brief The Base Interface
 */
class Base
{
public:
    size_t hash;

    virtual void toString() = 0;
    virtual size_t getHash() = 0;
};

/**
 * @brief The SubBase class
 */
class SubBase : public Base
{
public:
    SubBase()
    {
        hash = (size_t) this;
    }

    void toString()
    {
        std::cout << "SubBase {address: " << hash << "}" << std::endl;
    }

    size_t getHash()
    {
        return hash;
    }
};

class NextBase : public SubBase
{
public:
    NextBase()
    {
        hash = (size_t) this;
    }

    size_t getHash()
    {
        return hash;
    }

    void toString()
    {
        std::cout << "hui" << std::endl;
    }
};

/**
 * @brief The Singleton class
 */
class Manager : public Base
{
public:

    static Manager& getInstance()
    {
        static Manager instance;
        return instance;
    }

    void toString()
    {
        std::cout << "Manager {address: " << hash << "}" << std::endl;
    }

    size_t getHash()
    {
        return hash;
    }

private:
    Manager()
    {
        hash = (size_t) this;
    }
};

class Primal
{
public:
    virtual void doSomeThing()
    {
        std::cout << "Primal do" << std::endl;
    }

    virtual ~Primal(){}
};

class Shit : public Primal
{
public:
    /**
     * @brief virtual in sub classes is not necessary, it using like a message
     * for every one, that method was overridden, now in c++ 11
     * we have override marker
     */
    virtual void doSomeThing() override
    {
        std::cout << "Shit do" << std::endl;
    }
};

class MyShit : public Shit
{
public:

    int* myArray;

    void doSomeThing() override
    {
        std::cout << "MyShit do" << std::endl;
    }

    MyShit()
    {
        //memory heavy object
        myArray = new int[1000];
    }

    ~MyShit()
    {
        // must be free
        delete [] myArray;
    }
};


int main(int argc, char *argv[])
{
    Manager::getInstance().toString();

    // cretae on stack
    // but https://en.wikipedia.org/wiki/Dangling_pointer
    // c++14 smart pointers as solution
    Primal obj;
    Primal *p = &obj;

    // cretae on heap
    Primal *l = new Shit;
    Primal *m = new MyShit;

    QVector<Primal*> vector;
    vector.append(p);
    vector.append(l);
    vector.append(m);

    for(int ix = 0; ix < vector.size(); ++ix)
    {
        vector.at(ix)->doSomeThing();
    }

    delete l;
    delete m;

    QCoreApplication a(argc, argv);
    return a.exec();
}



