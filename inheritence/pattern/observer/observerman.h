#ifndef OBSERVERMAN
#define OBSERVERMAN

#include "iostream"
#include "observer.h"
#include "observable.h"

/**
 * @brief The ObserverMan class - Клас спостережуваного об'єкта
 */
class ObserverMan : public Observer
{
public:

    /**
     * @brief ObserverMan
     */
    ObserverMan(std::string name)
    {
        this->name = name;
        Observable::getInstance()->registerObserver(this);
    }

    /**
     * @brief notify
     * @param observable
     */
    void notify(const Observable &observable) override
    {
        std::cout << "notify " << "[" + name + "]" << " that Data changed - "
                  << observable.getData() << std::endl;
    }



private:
    std::string name;

    // Observer interface
public:
    std::string getName() override
    {
        return name;
    }
};

#endif // OBSERVERMAN

