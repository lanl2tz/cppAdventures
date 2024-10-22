/**
 * A functor type in C++ implemented using std::function<outType(inType)>.
 * Note: this is not the same typeclass as in Haskell! Just an instantiation.
 * To make a proper typeclass in C++, we need concept from C++ 20, which is
 * not of our concern here in this repository.
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
    auto fmap(const std::function<T2(T1)> &func) const
    {
        Functor<T2> functor;
        for (const T1 &data : this->dataContainer)
        {
            functor.push(func(data));
        }
        return functor;
    }

    template <typename T2>
    static auto fmap(const std::function<T2(T1)> &func, const Functor<T1> &f)
    {
        return f.fmap(func);
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
    Functor<int>::fmap<std::string>((std::function<std::string(int)>)[](const int &a) { return std::to_string(a); }, myFunctor).printContainer();
}

void test()
{
    testFunctor({1, 2, 3, 4, 5});
}