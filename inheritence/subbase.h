#ifndef SUBBASE_H
#define SUBBASE_H

#include <absbase.h>
#include <string>

class SubBase : public AbsBase
{
public:
    SubBase();

    std::string data;

    void runMyJob();
    void reverseData();

    void toString() override;
    size_t getHash() override;

    // AbsBase interface
protected:
    std::string gerDataReversCopy();

private:
    void reversString(std::string &str);
    void reversString(char *str);
};

#endif // SUBBASE_H
