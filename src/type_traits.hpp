#include <type_traits>

template <typename T1, typename T2>
auto foo(const T2 &obj) -> decltype(std::is_same_v<T1, T2>);

template <typename T>
auto isCopyable(const T &obj) -> decltype(std::is_trivially_copyable_v<T>);
