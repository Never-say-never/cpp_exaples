#include "observermanager.h"
#include <QMutex>

ObserverManager::ObserverManager()
{

}

/**
 * @brief ObserverManager::startObserving
 */
void ObserverManager::startObserving()
{
    ObserverMan *man1 = new ObserverMan("maniak");
    ObserverMan *man2 = new ObserverMan("_boss_");

    Observable::getInstance()->dataCahnge(190);

    delete man1;
    delete man2;
}
