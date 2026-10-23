#pragma once
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <utility>

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
    void isValueInRange(const T& value) const;
    void isIndexValid(int index) const;
public:
    class Reference {
    private:
        DynamicArray<T>* array;
        int index;
    public:
        Reference(DynamicArray<T>* arr, int i) : array(arr), index(i) {}

        Reference& operator=(const T& value) {
            array->set(index, value);
            return *this;
        }

        Reference& operator=(const Reference& other) {
            array->set(index, static_cast<T>(other));
            return *this;
        }

        operator T() const { 
            return array->get(index); 
        }
    };

    DynamicArray(int array_size);
    DynamicArray(const DynamicArray& array_to_copy);
    DynamicArray(DynamicArray&& other) noexcept;
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);       
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    void set(int index, const T& value);
    T get(int index) const;
    void pushBack(const T& value);
    void print();
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);

    Reference operator[](int index);
    const T&  operator[](int index) const; 

    bool operator==(const DynamicArray& other) const;
    bool operator!=(const DynamicArray& other) const;

    DynamicArray& operator+=(const DynamicArray& other); 
    DynamicArray& operator-=(const DynamicArray& other);
    DynamicArray& operator+=(const T& scalar);           
    DynamicArray& operator-=(const T& scalar);

    T* begin() { 
        return data; 
    }
    T* end() { 
        return data + size; 
    }
    const T* begin() const { 
        return data; 
    }
    const T* end() const { 
        return data + size; 
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& arr);
    template <typename U>
    friend double distance(const DynamicArray<U>& a, const DynamicArray<U>& b);
};

#include "dynamic_array.tpp"
