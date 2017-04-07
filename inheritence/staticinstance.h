#ifndef STATICINSTANCE
#define STATICINSTANCE

#include <subbase.h>

/**
 * @brief The StaticInstance class
 */
class StaticInstance : public AbsBase
{
public:

    static StaticInstance& getInstance()
    {
        static StaticInstance instance;
        return instance;
    }

    void toString() override
    {
        std::cout << "Manager {address: " << hash << "}" << std::endl;
    }

    size_t getHash() override
    {
        return hash;
    }

    static SubBase getObject()
    {
        return SubBase();
    }

private:
    StaticInstance()
    {
        hash = (size_t) this;
    }

    // AbsBase interface
protected:
    string gerDataReversCopy() override
    {
        return "ko";
    }
};

#endif // STATICINSTANCE

