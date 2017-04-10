#include <QCoreApplication>
#include <vector>

#include <iostream>
#include <stdio.h>

#include <subbase.h>
#include <staticinstance.h>
#include "pattern/observer/observermanager.h"

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

void runProtectedCall()
{
    PROTECTED_CALL(ICallYou, callMe);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*SubBase *obj = new SubBase;
    obj->runMyJob();
    obj->toString();
    std::cout << "hash: " << obj->getHash() << std::endl;

    StaticInstance::getObject().valCall();
    obj->valCall();

    delete obj;*/

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

    //runFloattest();
    runProtectedCall();

    runObservtest();

    return a.exec();
}



