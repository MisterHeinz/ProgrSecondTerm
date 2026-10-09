// main.cpp
#include <iostream>
#include "dynamic_array.h"

void printSeparator(const char* title) {
    std::cout << "\n===== " << title << " =====\n";
}

int main() {
    printSeparator("1. Конструктор, print");
    DynamicArray a(4);
    a.print();                          // [ 0, 0, 0, 0 ]

    printSeparator("2. set: корректные значения");
    std::cout << "set(0, 10)  -> " << a.set(0, 10)  << "\n";
    std::cout << "set(1, -20) -> " << a.set(1, -20) << "\n";
    std::cout << "set(2, 100) -> " << a.set(2, 100) << "\n";
    std::cout << "set(3, -100)-> " << a.set(3, -100)<< "\n";
    a.print();                          // [ 10, -20, 100, -100 ]

    printSeparator("3. set: ошибочные вызовы");
    std::cout << "set(4, 5)   -> " << a.set(4, 5)   << "\n";  // индекс вне границ
    std::cout << "set(-1, 5)  -> " << a.set(-1, 5)  << "\n";  // индекс вне границ
    std::cout << "set(0, 101) -> " << a.set(0, 101) << "\n";  // значение вне диапазона
    std::cout << "set(0, -101)-> " << a.set(0, -101)<< "\n";  // значение вне диапазона
    a.print();                          

    printSeparator("5. pushBack");
    a.print();                          // [ 10, -20, 100, -100 ]
    std::cout << "pushBack(7)   -> " << a.pushBack(7)   << "\n";
    std::cout << "pushBack(-50) -> " << a.pushBack(-50) << "\n";
    std::cout << "pushBack(200) -> " << a.pushBack(200) << " (вне диапазона)\n";
    std::cout << "pushBack(-200)-> " << a.pushBack(-200)<< " (вне диапазона)\n";
    a.print();                          // [ 10, -20, 100, -100, 7, -50 ]

    printSeparator("6. Конструктор копирования");
    DynamicArray b = a;
    std::cout << "b (копия a): ";
    b.print();
    b.set(0, 55);                       
    std::cout << "a: ";
    a.print();
    std::cout << "b: ";
    b.print();

    printSeparator("7. add");
    DynamicArray x(3);
    DynamicArray y(3);
    x.set(0, 1);  x.set(1, 2);  x.set(2, 3);
    y.set(0, 10); y.set(1, 20); y.set(2, 30);
    std::cout << "x: "; x.print();
    std::cout << "y: "; y.print();
    x.add(y);
    std::cout << "x.add(y): "; x.print();   // [ 11, 22, 33 ]

    DynamicArray small(2);
    DynamicArray big(5);
    small.set(0, 1);  small.set(1, 2);
    big.set(0, 10); big.set(1, 20); big.set(2, 30);
    big.set(3, 40); big.set(4, 50);
    std::cout << "small: "; small.print();
    std::cout << "big:   "; big.print();
    small.add(big);
    std::cout << "small.add(big): "; small.print();  // [ 11, 22 ], размер не изменился

    DynamicArray p(5);
    DynamicArray q(2);
    p.set(0, 1); p.set(1, 2); p.set(2, 3); p.set(3, 4); p.set(4, 5);
    q.set(0, 100); q.set(1, 100);
    std::cout << "p: "; p.print();
    std::cout << "q: "; q.print();
    p.add(q);
    std::cout << "p.add(q): "; p.print();  // [ 101, 102, 3, 4, 5 ]

    printSeparator("8. subtract");
    DynamicArray m(4);
    DynamicArray n(2);
    m.set(0, 50); m.set(1, 40); m.set(2, 30); m.set(3, 20);
    n.set(0, 5);  n.set(1, 10);
    std::cout << "m: "; m.print();
    std::cout << "n: "; n.print();
    m.subtract(n);
    std::cout << "m.subtract(n): "; m.print(); // [ 45, 30, 30, 20 ]

    printSeparator("9. Нулевой размер и отрицательный размер");
    DynamicArray empty(0);
    empty.print();                       // [ ]
    std::cout << "empty.pushBack(5) -> " << empty.pushBack(5) << "\n";
    empty.print();                       // [ 5 ]

    DynamicArray neg(-3);                // должен стать размером 0
    neg.print();                         // [ ]

    printSeparator("10. Самоприменение add/subtract");
    DynamicArray s(3);
    s.set(0, 1); s.set(1, 2); s.set(2, 3);
    std::cout << "s: "; s.print();
    s.add(s);                            // [ 2, 4, 6 ]
    std::cout << "s.add(s): "; s.print();
    s.subtract(s);                       // [ 0, 0, 0 ]
    std::cout << "s.subtract(s): "; s.print();

    std::cout << "\nВсе проверки завершены.\n";
    return 0;
}