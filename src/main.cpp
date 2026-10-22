#include "dynamic_array.h"

int main() {
    DynamicArray<int> a(3);
    a.set(0, 100); a.set(1, -100); a.set(2, 10);

    DynamicArray<int> b(3);
    b.set(0, 100); b.set(1, 100); b.set(2, 20);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    DynamicArray<int> a_plus = a;
    a_plus.add(b);
    std::cout << "a + b = " << a_plus << "\n";

    DynamicArray<int> a_minus = a;
    a_minus.subtract(b);
    std::cout << "a - b = " << a_minus << "\n";

    std::cout << "distance = " << distance(a, b) << "\n";

    DynamicArray<double> d1(1), d2(1);
    d1.set(0, 100.5);
    d2.set(0, 100.0);
    d1.add(d2);
    std::cout << "double = " << d1 << "\n";

    try {
        DynamicArray<std::string> s1(1), s2(1);
        s1.add(s2);
    } catch (const std::bad_typeid& e) {
        std::cerr << "add: bad_typeid -> " << e.what() << "\n";
    }
    try {
        DynamicArray<std::string> s1(1), s2(1);
        distance(s1, s2);
    } catch (const std::bad_typeid& e) {
        std::cerr << "distance: bad_typeid -> " << e.what() << "\n";
    }

    try {
        DynamicArray<int> x(2), y(3);
        distance(x, y);
    } catch (const std::invalid_argument& e) {
        std::cerr << "distance: invalid_argument -> " << e.what() << "\n";
    }

    return 0;
}