#pragma once
#include <iostream>

class DynamicArray{
private: 
    int* data;
    int size;
    int capacity;

    const int MIN_VALUE = -100;
    const int MAX_VALUE = 100;
    bool isValueInRange(int value);
    bool isIndexValid(int index);
public:
    DynamicArray(int array_size);
    DynamicArray(const DynamicArray& array_to_copy);
    ~DynamicArray();
    bool set(int index, int value);
    int get(int index);
    bool pushBack(int value);
    void print();
    void add(DynamicArray& other);
    void subtract(DynamicArray& other);
};

