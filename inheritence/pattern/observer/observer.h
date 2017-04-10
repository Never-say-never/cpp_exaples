#ifndef OBSERVER
#define OBSERVER

class Observable;
class Observer
{
public:
    virtual void notify(const Observable &observable) = 0;
    virtual ~Observer() {}
};

#endif // OBSERVER

