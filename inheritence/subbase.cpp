#include "subbase.h"
#include <iostream>
#include <assert.h>

SubBase::SubBase()
{
    //this->data = "\{ type: demo \}";
    this->data = "ehal greka 4erwez reky";
    //this->data = "";
}

void SubBase::runMyJob()
{
    // some flow
    this->gerDataReversCopy();
    this->reverseData();
}

/**
 * @brief SubBase::toString
 */
void SubBase::toString()
{
    std::cout << "SubBase{ data:" << this->data << " }" << std::endl;
}

/**
 * @brief SubBase::getHash
 * @return
 */
size_t SubBase::getHash()
{
    assert(this->hash != 0);
    return this->hash + this->data.size();
}

/**
 * @brief SubBase::doJob
 */
std::string SubBase::gerDataReversCopy()
{
    char *c = new char[this->data.size()];
    int size = this->data.size();
    for(int ix = 0; ix < size; ++ix)
    {
        c[ix] = this->data.at((size - 1) - ix);
    }

    std::string copy(c);
    std::cout << "result:" << copy << std::endl;

    return copy;
}

/**
 * @brief SubBase::reversString
 * @param str
 * @return
 */
void SubBase::reversString(string &str)
{
    if(str.empty())
    {
        return;
    }

    int size = str.size() - 1;
    for(int ix = 0, iy = size; ix < iy; ++ix, --iy)
    {
        char start = str.at(iy);
        char end = str.at(ix);

        str.at(iy) = end;
        str.at(ix) = start;
    }
}

/**
 * @brief SubBase::reverseData
 */
void SubBase::reverseData()
{
    this->reversString(this->data);
    std::cout << "reverseData:" << this->data << std::endl;
}

