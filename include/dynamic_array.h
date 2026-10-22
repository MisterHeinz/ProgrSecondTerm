#pragma once
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <typeinfo>

template <typename T> class DynamicArray;
template <typename T> std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr);
template <typename T> double distance(const DynamicArray<T>& a, const DynamicArray<T>& b);

template <typename T>
class DynamicArray {
private: 
    T* data;
    int size;
    int capacity;

    static const int MIN_VALUE = -100;
    static const int MAX_VALUE = 100;
    T countAdditionElement(T a, T b);
    T countSubtractionNumber(T a, T b);
    void isValueInRange(const T& value);
    void isIndexValid(int index);
public:
    DynamicArray(int array_size);
    DynamicArray(const DynamicArray& array_to_copy);
    ~DynamicArray();
    void set(int index, const T& value);
    T get(int index);
    void pushBack(const T& value);
    void print();
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);
    template <typename U>
    friend double distance(const DynamicArray<U>& a, const DynamicArray<U>& b);
};

#include "dynamic_array.tpp"
