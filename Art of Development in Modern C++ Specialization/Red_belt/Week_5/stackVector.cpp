//
//  StackVector.cpp
//  coursera
//
//  Created by Денис Домашевич on 10/15/18.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <array>

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) {
        if(a_size > this -> capacity) {
            throw std::invalid_argument("Error size > capacity");
        }
        this -> size = a_size;
    }
    
    T& operator [](size_t index) {
        return data[index];
    }
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    auto begin() {
        return this -> data.begin();
    }
    
    auto end() {
        return this -> data.begin() + this -> size;
    }
    
    size_t Size() {
        return this -> size;
    }
    size_t Capacity() {
        return this -> capacity;
    }
    
    T PopBack() {
        if(this -> size == 0) {
            throw std::underflow_error("Error size == 0");
        }
        this -> size--;
        return data[this -> size];
    }
    void PushBack(const T& value) {
        if(this -> size >= this -> capacity) {
            throw std::overflow_error("Error size == capacity");
        }
        data[this -> size++] = value;
    }
    
private:
    size_t size = 0;
    size_t capacity = N;
    std::array<T, N> data;
};

int main() {
    
    return 0;
    
}
