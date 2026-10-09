#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cmath>
#include "dynamic_array.h"

int DynamicArray::countAdditionElement(int a, int b) {
    if (a + b > MAX_VALUE) {
        return MIN_VALUE + (a + b - MAX_VALUE - 1);
    }
    return a + b;
}

int DynamicArray::countSubtractionNumber(int a, int b) {
    if (a - b < MIN_VALUE) {
        return MAX_VALUE - (MIN_VALUE - (a - b) - 1);
    }
    return a - b;
}

void DynamicArray::isValueInRange(int value) {
    if (value < MIN_VALUE || value > MAX_VALUE) {
        throw std::invalid_argument("Invalid argument");
    } 
}

void DynamicArray::isIndexValid(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index");
    } 
}

DynamicArray::DynamicArray(int array_size) {
    if (array_size < 0) {
        array_size = 0;
    }
    size = array_size;
    capacity = array_size;
    data = new int[capacity]{}; 
}

DynamicArray::DynamicArray(const DynamicArray& array_to_copy) {
    size = array_to_copy.size;
    capacity = array_to_copy.capacity;
    data = new int[capacity]{};

    for (int i = 0; i < size; ++i) {
        data[i] = array_to_copy.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::set(int index, int value) {
    isValueInRange(value);
    isIndexValid(index);
    data[index] = value;
}

int DynamicArray::get(int index) {
    isIndexValid(index);
    return data[index];
}

void DynamicArray::pushBack(int value) {
    isValueInRange(value);

    if (size >= capacity) {
        int new_capacity = (capacity == 0) ? 1 : capacity * 2;
        int* new_data = new int[new_capacity]{}; 
        
        std::memcpy(new_data, data, size * sizeof(int));
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size] = value;
    size++;
}

void DynamicArray::print() {
    std::cout << "Array: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
}

void DynamicArray::add(DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        int other_value = 0;
        if (i < other.size) {
            other_value = other.data[i];
        }
        data[i] = countAdditionElement(data[i], other_value);
    }
}

void DynamicArray::subtract(DynamicArray& other) {
    for (int i = 0; i < size; ++i) {
        int other_value = 0;
        if (i < other.size) {
            other_value = other.data[i];
        }
        data[i] = countSubtractionNumber(data[i], other_value);
    }
}
