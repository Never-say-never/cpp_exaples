#ifndef SINGLTONEMANAGER
#define SINGLTONEMANAGER

#include <base.h>
#include <staticinstance.h>

class SingletonManager
{
public:

    enum Type
    {
        STATIC_INSTANCE,
        NEW_INSTANCE
    };

    SingletonManager()
    {

    }

    Base *getInstance(Type t)
    {
        switch (t) {
        case Type::STATIC_INSTANCE:
            return StaticInstance::getInstance();
            break;
        case Type::NEW_INSTANCE:
            return nullptr;
            break;
        default:
            break;
        }
    }

    ~SingletonManager()
    {

    }
};

#endif // SINGLTONEMANAGER

