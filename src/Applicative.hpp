/**
 * An instantiation of the Haskell applicative typeclass in modern C++.
 */

#include "Functor.hpp"

template <typename T1>
class Applicative : public Functor<T1>
{
public:
    // pure :: a -> f a
    static auto &pure(const T1 &a)
    {
        Applicative<T1> app;
        app.push(a);
        return app;
    }

    auto liftA2();
};