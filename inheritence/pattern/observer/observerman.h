#ifndef OBSERVERMAN
#define OBSERVERMAN

#include "iostream"
#include "observer.h"
#include "observable.h"

using namespace std;

/**
 * @brief The ObserverMan class - Клас спостережуваного об'єкта
 */
class ObserverMan : public Observer
{
public:

    /**
     * @brief ObserverMan
     */
    ObserverMan(string name)
    {
        Observable::getInstance()->registerObserver(this);
        this->name = name;
    }

    /**
     * @brief notify
     * @param observable
     */
    void notify(const Observable &observable) override
    {
        std::cout << "[" + name + "]" << " Data changed - "
                  << observable.getData() << std::endl;
    }

private:
    std::string name;
};

#endif // OBSERVERMAN

