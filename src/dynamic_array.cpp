#include <iostream>
#include <cstring>
#include "dynamic_array.h"

bool DynamicArray::isValueInRange(int value){
    if(value < MIN_VALUE || value > MAX_VALUE){
        std::cout << "[set] Значение " << value << " не входит в диапазон [" << MIN_VALUE << " , " << MAX_VALUE << "]\n";
        return false;
    } 
    return true;
}

bool DynamicArray::isIndexValid(int index){
    if (index < 0 || index >= size) {
        std::cout << "[get] Индекс " << index << " выходит за границы массива\n";
        return false;
    } 
    return true;
}

DynamicArray::DynamicArray(int array_size) {
    if (array_size < 0) {
            array_size = 0;
    }
    size = array_size;
    capacity = array_size;
    data = new int[capacity]{};
}

DynamicArray::DynamicArray(const DynamicArray& array_to_copy){
    size = array_to_copy.size;
    capacity = array_to_copy.capacity;
    data = new int[capacity]{};

    for(int i = 0; i < size; ++i){
        data[i] = array_to_copy.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

bool DynamicArray::set(int index, int value) {
    if (!isValueInRange(value) || !isIndexValid(index)) {
        return false;
    }

    data[index] = value;
    return true;
}

int DynamicArray::get(int index) {
    if(!isIndexValid(index)) {
        return MAX_VALUE+1;
    }
    return data[index];
}

bool DynamicArray::pushBack(int value){
    if (!isValueInRange(value)) {
        return false;
    }

    if(size >= capacity){
        int new_capacity = (capacity == 0) ? 1 : capacity*2;
        int* new_data = new int[new_capacity]{};
        std::memcpy(new_data, data, size * sizeof(int));
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    data[size]= value;
    size++;
    return true;
}

void DynamicArray::print() {
    std::cout << "Массив: [ ";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
}

void DynamicArray::add(DynamicArray& other){
    for (int i = 0; i < size; ++i) {
        int other_value = 0;
        if (i < other.size) {
            other_value = other.data[i];
        }
        data[i] += other_value;
    }
}

void DynamicArray::subtract(DynamicArray& other){
    for (int i = 0; i < size; ++i) {
        int other_value = 0;
        if (i < other.size) {
            other_value = other.data[i];
        }
        data[i] -= other_value;
    }
}