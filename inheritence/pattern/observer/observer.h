#ifndef OBSERVER
#define OBSERVER

#include <string>

class Observable;
class Observer
{
public:
    virtual void notify(const Observable &observable) = 0;
    virtual std::string getName() = 0;
    virtual ~Observer() {}
};

#endif // OBSERVER

