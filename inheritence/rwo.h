#ifndef RWO
#define RWO

/**
 * @brief In the context of the C++ programming language, the return value optimization
 * (RVO) is a compiler optimization that involves eliminating the temporary object
 * created to hold a function's return value. The RVO is particularly notable for
 * being allowed to change the observable behaviour of the resulting program by the
 * C++ standard.
 */
class Obj
{
public:
    size_t address;

    Obj()
    {
        address = (size_t) this;
        std::cout << "address:" << address << std::endl;
    }

    Obj(const Obj&)
    {
        std::cout << "Copy me kurrwa.\n";
    }
};
#endif // RWO

/*

Obj test(Obj o)
{
    std::cout << "address:" << (size_t) &o << std::endl;
    return o;
}

Obj rlyRVO()
{
    Obj ob;
    return ob;
}

int main() {
    Obj o = Obj();

    Obj rvo = rlyRVO();
    std::cout << "address:" << (size_t) &rvo << std::endl;

    return 0;
}

address:140737279079424
address:140737279079440
address:140737279079440

//////////////////////////////////////////////////////////// and
int main() {
    Obj o = Obj();

    Obj rvo = test(o);
    std::cout << "address:" << (size_t) &rvo << std::endl;

    return 0;
}

address:140734937561024
Copy me kurrwa.
address:140734937561056
Copy me kurrwa.
address:140734937561040

*/
