#include <type_traits>

template <typename T1, typename T2>
auto foo(const T2 &obj) -> decltype(std::is_same_v<T1, T2>);

template <typename T>
auto isCopyable(const T &obj) -> decltype(std::is_trivially_copyable_v<T>);

enum class GeometryType
{
    A,
    B,
    C
};

struct BondOrientation
{
};

struct BondOrientationA : BondOrientation
{
};

struct BondOrientationB : BondOrientation
{
};

template <GeometryType T>
struct Geometry
{
};

template <>
struct Geometry<GeometryType::A>
{
    static const GeometryType type = GeometryType::A;
    /* data */
};

template <>
struct Geometry<GeometryType::B>
{
    /* data */
};

template <>
struct Geometry<GeometryType::C>
{
    /* data */
};
