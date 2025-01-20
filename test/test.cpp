#include <iostream>
#include <string>

struct Print
{
    template <typename T>
    Print(T t)
    {
        std::cout << t << std::endl;
    }
};

int main()
{
    Print p(10);
}