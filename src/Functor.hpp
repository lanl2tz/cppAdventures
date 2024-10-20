/**
 * Functor type in C++.
 */

#include <vector>
#include <functional>
#include <iostream>

template <typename T1>
class Functor
{
private:
    std::vector<T1> dataContainer;

public:
    auto push(const T1 &data)
    {
        this->dataContainer.push_back(data);
    }

    template <typename T2>
    auto fmap(const std::function<T2(T1)> &func)
    {
        Functor<T2> functor;
        for (const T1 &data : this->dataContainer)
        {
            functor.push(func(data));
        }
        return functor;
    }

    void printContainer() const
    {
        for (auto &data : this->dataContainer)
        {
            std::cout << data << ", ";
        }
        std::cout << std::endl;
    }
};

// Example Functor Test
void testFunctor(const std::vector<int> list)
{
    Functor<int> myFunctor;
    for (const int &data : list)
    {
        myFunctor.push(data);
    }
    myFunctor.fmap<std::string>((std::function<std::string(int)>)[](const int &a) { return std::to_string(a); }).printContainer();
}

void test()
{
    testFunctor({1, 2, 3, 4, 5});
}