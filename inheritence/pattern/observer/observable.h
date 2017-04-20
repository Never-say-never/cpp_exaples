#ifndef OBSERVABLE
#define OBSERVABLE

#include <QVector>
#include "observer.h"
#include "iostream"

/**
 * @brief The Observable class - Клас спостерігача
 */
class Observable
{
public:

    ~Observable() {}

    /**
     * @brief getInstance
     * @return
     */
    static Observable *getInstance()
    {
        if(!instance)
        {
            instance = new Observable();
        }

        return instance;
    }

    /**
     * @brief dataCahnge
     * @param data
     */
    void dataCahnge(int data)
    {
        this->data = data;
        std::cout << "DATA WAS CHANGED: " << this->data << std::endl;

        this->notifyObservers();
    }

    /**
     * @brief registerObserver
     * @param obs
     */
    void registerObserver(Observer *obs)
    {
        if(obs == NULL)
        {
            std::cout << "obs == NULL" << std::endl;
            return;
        }

        this->observerList.append(obs);

        std::cout << "add to listeners" << "[" << this->observerList.size() << "] - " << obs->getName() << std::endl;
    }

    /**
     * @brief getData
     * @return
     */
    int getData() const
    {
        return data;
    }

private:
    int data;

    static Observable *instance;
    QVector<Observer*> observerList;

    Observable() {}

    /**
     * @brief notifyObservers
     */
    void notifyObservers()
    {
        for(auto& item : this->observerList)
        {
            item->notify(*this);
        }
    }

};

#endif // OBSERVABLE

