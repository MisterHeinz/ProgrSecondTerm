#include "dynamic_array.h"

int main() {
    std::cout << std::endl << "TASK 3"  << std::endl;

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

    std::cout << std::endl << "TASK 4"  << std::endl;

    DynamicArray<int> c(3);
    c[0] = 5; c[1] = -5; c[2] = 0;
    std::cout << "c = " << c << "\n";
    int first_c = c[0];
    std::cout << "c[0] = " << first_c << "\n";
    c[0] = c[1];
    std::cout << "c after c[0] = c[1]: " << c << "\n";

    try {
        int bad = c[5];
        std::cout << bad << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "operator[]: out_of_range -> " << e.what() << "\n";
    }

    try {
        c[0] = 1000;
    } catch (const std::invalid_argument& e) {
        std::cerr << "operator[] set: invalid_argument -> " << e.what() << "\n";
    }

    DynamicArray<int> c2 = c;
    std::cout << "DynamicArray c2 == c: " << c2 << "\n";
    bool same = (c == c2);
    std::cout << "c == c2: " << same << "\n";

    c2[0] = 42;
    std::cout << "change c2: " << c2 << "\n";
    bool diff = (c != c2);
    std::cout << "c != c2: " << diff << "\n";

    DynamicArray<int> g = a;
    DynamicArray<int> h(2);
    h[0] = 5;
    h[1] = 10;

    std::cout << "DynamicArray g: " << g << "\n";
    std::cout << "DynamicArray h: " << h << "\n";

    g += h;
    std::cout << "g += h: " << g << "\n";

    g -= h;
    std::cout << "g -= h: " << g << "\n";

    g += 50;
    std::cout << "g += 50: " << g << "\n";

    g -= 50;
    std::cout << "g -= 50: " << g << "\n";

    int* first = g.begin();
    int* last  = g.end();
    std::cout << "first value = " << *first << "\n";           
    std::cout << "size via iter = " << (last - first) << "\n";

    const DynamicArray<int>& cg = g;
    const int* cb = cg.begin();
    const int* ce = cg.end();
    std::cout << "const begin value = " << *cb << "\n";
    std::cout << "const size via iter = " << (ce - cb) << "\n";
    std::cout << "const cg[0] = " << cg[0] << "\n";

    std::cout << std::endl << "TASK 5"  << std::endl;

    DynamicArray<int> p(3);
    p[0] = 1; p[1] = 2; p[2] = 3;
    DynamicArray<int> q(1);
    q = p;
    std::cout << "array p: " << p << "\n";
    std::cout << "array q = p: " << q << "\n";
    std::cout << "q == p: " << (q == p) << "\n";

    q = q;
    std::cout << "q after q = q: " << q << "\n";

    DynamicArray<int> r(1);
    r = q = p;
    std::cout << "r = q = p: " << r << "\n";

    DynamicArray<int> src(3);
    src[0] = 10; src[1] = 20; src[2] = 30;
    std::cout << "array src: " << src << "\n";
    DynamicArray<int> dst(std::move(src));
    std::cout << "dst = move(src): " << dst << "\n";
    std::cout << "src after move: " << src << "\n";

    src.pushBack(7);
    std::cout << "src after pushBack(7): " << src << "\n";

    DynamicArray<int> m1(2);
    m1[0] = 100; m1[1] = 50;
    std::cout << "array m1: " << m1 << "\n";
    DynamicArray<int> m2(1);
    m2 = std::move(m1);
    std::cout << "m2 = move(m1): " << m2 << "\n";
    std::cout << "m1 after move: " << m1 << "\n";

    m2 = std::move(m2);
    std::cout << "m2 after m2 = move(m2): " << m2 << "\n";
    m1.pushBack(42);
    std::cout << "m1 after pushBack(42): " << m1 << "\n";

    return 0;
}