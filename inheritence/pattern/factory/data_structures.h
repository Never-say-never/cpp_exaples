#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#include <iostream>
#include <stdio.h>
using namespace std;

struct Point
{
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void print()
    {
        cout << "x:" << this->x << "; y:" << this->y << endl;
    }

    int x;
    int y;
};

#endif // DATA_STRUCTURES

