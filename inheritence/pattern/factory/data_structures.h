#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <iostream>
#include <stdio.h>
#include <QString>

using namespace std;

struct Point
{
    Point() : x(10), y(10) {}

    QString toString()
    {
        return QString::number(x).append(" : ").append(QString::number(y));
    }

    size_t x;
    size_t y;
};

#endif // DATA_STRUCTURES

