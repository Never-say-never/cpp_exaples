#include <QCoreApplication>
#include <vector>

#include <iostream>
#include <stdio.h>

#include <subbase.h>
#include <staticinstance.h>

/*
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
*/
class ProtectedClass
{
protected:
    void callMe()
    {
        std::cout << "call me bitch" << std::endl;
    }
};

#define PROTECTED_CALL(className, method) class ICallYou : public ProtectedClass \
{ \
public:\
    void call()\
     {\
        this->method();\
    }\
};\
className c;\
c.call();\

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //PROTECTED_CALL(ICallYou, callMe);

    SubBase *obj = new SubBase;
    obj->runMyJob();
    obj->toString();
    std::cout << "hash: " << obj->getHash() << std::endl;

    StaticInstance::getObject().valCall();
    obj->valCall();

    delete obj;

    // cretae on stack
    // but https://en.wikipedia.org/wiki/Dangling_pointer
    // c++14 smart pointers as solution
    /*Primal obj;
    Primal *p = &obj;

    // cretae on heap
    Primal *l = new Shit;
    Primal *m = new MyShit;

    std::vector<Primal*> vector;
    vector.push_back(p);
    vector.push_back(l);
    vector.push_back(m);

    for(int ix = 0; ix < vector.size(); ++ix)
    {
        vector.at(ix)->doSomeThing();
    }

    delete l;
    delete m;*/

    /*float t = 0.1 + 0.2;
    printf("%.17f\n", t);*/


    return a.exec();
}



