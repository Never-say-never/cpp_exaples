#ifndef OBSERVERMANAGER_H
#define OBSERVERMANAGER_H

#include <QThread>
#include <QMutex>
#include "observable.h"
#include "observerman.h"

class ObserverManager
{
public:
    ObserverManager();

    static void startObserving();

private:
    int sleepTime;
};

#endif // OBSERVERMANAGER_H
