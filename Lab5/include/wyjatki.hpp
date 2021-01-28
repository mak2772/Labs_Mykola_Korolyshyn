#ifndef EX_HPP
#define EX_HPP
#include <iostream>
#include <exception>

using namespace std;
class Exception
{
private:
    string msg;
public:
    Exception(string error): msg(error) {}
    const char *what()
    {
        return msg.c_str();
    }
};

#endif
