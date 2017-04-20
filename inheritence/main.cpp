#include <QCoreApplication>
#include <vector>

#include <iostream>
#include <stdio.h>
using namespace std;
#include <subbase.h>
#include <staticinstance.h>
#include "pattern/observer/observermanager.h"
#include "pattern/factory/demo_manager.h"



class ProtectedClass
{
protected:
    void callMe()
    {
        std::cout << "Call me bro, protected" << std::endl;
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

/**
 * @brief runObservtest
 */
void runObservtest()
{
    ObserverManager::startObserving();
}

/**
 * @brief runFloattest
 */
void runFloattest()
{
    float t = 0.1 + 0.2;
    printf("%.17f\n", t);
}

/**
 * @brief rvalLvalOverloading
 */
void rvalLvalOverloading()
{
    SubBase *obj = new SubBase;
    obj->runMyJob();
    obj->toString();
    std::cout << "hash: " << obj->getHash() << std::endl;

    StaticInstance::getObject().valCall();
    obj->valCall();

    delete obj;
}

/**
 * @brief listWithAbstractObjects
 */
void listWithAbstractObjects()
{
    // cretae on stack
    // but https://en.wikipedia.org/wiki/Dangling_pointer
    // c++14 smart pointers as solution
    SubBase obj;
    Base *p = &obj;

    // cretae on heap
    Base *l = new SubBase;
    Base *m = new SubBase;

    std::vector<Base*> vector;
    vector.push_back(p);
    vector.push_back(l);
    vector.push_back(m);

    for(int ix = 0; ix < vector.size(); ++ix)
    {
        vector.at(ix)->valCall();
    }

    delete l;
    delete m;
}

/**
 * @brief runProtectedCall
 */
void runProtectedCall()
{
    PROTECTED_CALL(ICallYou, callMe);
}

void space_ship_demo()
{
    FactoryManager f;
    f.runDemo();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); 
    //listWithAbstractObjects();
    //runFloattest();
    //runProtectedCall();
    //runObservtest();

    space_ship_demo();

    return a.exec();
}



