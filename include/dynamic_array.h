#pragma once
#include <iostream>

class DynamicArray {
private: 
    int* data;
    int size;
    int capacity;

    const int MIN_VALUE = -100;
    const int MAX_VALUE = 100;
    int countAdditionElement(int a, int b);
    int countSubtractionNumber(int a, int b);
    void isValueInRange(int value);
    void isIndexValid(int index);
public:
    DynamicArray(int array_size);
    DynamicArray(const DynamicArray& array_to_copy);
    ~DynamicArray();
    void set(int index, int value);
    int get(int index);
    void pushBack(int value);
    void print();
    void add(DynamicArray& other);
    void subtract(DynamicArray& other);
};
