#include <iostream>
#include <stdexcept>
#include <new>      
#include "dynamic_array.h"

int main() {
    try {
        std::cout << "1. TEST CONSTRUCT\n";
        {
            std::cout << "Create array with size = 5\n";
            DynamicArray arr(5);
            arr.print();
        }
        {
            std::cout << "Create array with size = -5\n";
            DynamicArray arr(-5);
            arr.print();
        }

        DynamicArray arr(3); 
        arr.set(0, 10); 
        arr.set(1, 20);
        arr.set(2, 30);

        std::cout << "\n2. TEST SET\n";
        try {
            std::cout << "try SET 50\n";
            arr.set(1, 50);
            arr.print();
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        
        try {
            std::cout << "Try SET 150\n";
            arr.set(1, 150);
        } catch (const std::invalid_argument& e) {
            std::cout << "Exception :" << e.what() << "\n";
        }

        std::cout << "\n3. TEST GET\n";
        try {
            std::cout << "read 0\n";
            std::cout << "Value: " << arr.get(0) << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error:  " << e.what() << "\n";
        }

        try {
            std::cout << "read 10\n";
            std::cout << "Value:  " << arr.get(10) << "\n";
        } catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
        }

        std::cout << "\n4. TEST PUSHBACK\n";
        try {
            std::cout << "add -90\n";
            arr.pushBack(-90);
            arr.print();
        } catch (const std::exception& e) {
            std::cout << "Err: " << e.what() << "\n";
        }

        try {
            std::cout << "add -150\n";
            arr.pushBack(-105);
        } catch (const std::invalid_argument& e) {
            std::cout << "Err: " << e.what() << "\n";
        }

        DynamicArray arr_a(2);
        arr_a.set(0, 80);
        arr_a.set(1, -80);

        DynamicArray arr_b(2);
        arr_b.set(0, 10);  
        arr_b.set(1, 30);  

        DynamicArray arr_c(2);
        arr_c.set(0, 30);  
        arr_c.set(1, -30);

        std::cout << "\n5. TEST ADD\n";
        {
            std::cout << "A + B\n";
            DynamicArray temp(arr_a);
            std::cout << "Before: "; temp.print();
            temp.add(arr_b);
            std::cout << "After: "; temp.print();
        }
        {
            std::cout << "A + C\n";
            DynamicArray temp(arr_a);
            std::cout << "Before: "; temp.print();
            temp.add(arr_c);
            std::cout << "After (got overflow): "; temp.print();
        }

        std::cout << "\n6. TEST SUBTRACT\n";
        {
            std::cout << "A - B (Success)\n";
            DynamicArray temp(arr_a);
            std::cout << "Before: "; temp.print();
            temp.subtract(arr_b);
            std::cout << "After: "; temp.print();
        }
        {
            std::cout << "Underflow Test (Fail/Overflow)\n";
            DynamicArray low_arr(1);
            low_arr.set(0, -90);
            DynamicArray sub_arr(1);
            sub_arr.set(0, 20); 
            
            std::cout << "Before: "; low_arr.print();
            low_arr.subtract(sub_arr);
            std::cout << "After (got underflow): "; low_arr.print();
        }

        std::cout << "\n7. TEST MEMORY ALLOCATION FAIL\n";
        std::cout << "Trying to allocate a massive array to trigger bad_alloc...\n";
        
        DynamicArray huge_array(2000000000); 
        huge_array.pushBack(0);
        std::cout << huge_array.get(1000000);

    } catch (const std::bad_alloc&) {
        std::cerr << "Couldn't allocate memory\n";
        return 1; 
    }
    return 0;
}
