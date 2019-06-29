//
//  deque.cpp
//  coursera
//
//  Created by Денис Домашевич on 05/02/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <vector>

template <typename T>
class Deque {
public:
  
  Deque() {}
  ~Deque() {}

  bool Empty() const {
    return size_ == 0;
  }

  size_t Size() const {
    return size_;
  }

  T& operator[](size_t index) {
    return getTrueIndex(index);
  }

  const T& operator[](size_t index) const {
    return getTrueIndex(index);
  }

  T& At(size_t index) {
    if(index >= size_) {
      throw std::out_of_range("Index is too big");
    }
    return getTrueIndex(index);
  }

  const T& At(size_t index) const {
    if(index >= size_) {
      throw std::out_of_range("Index is too big");
    }
    return getTrueIndex(index);
  }

  T& Front() {
     return getTrueIndex(0);
  }

  const T& Front() const {
    return getTrueIndex(0);
  }

  T& Back() {
    return getTrueIndex(size_ - 1);
  }

  const T& Back() const {
    return getTrueIndex(size_ - 1);
  }

  void PushFront(const T& value) {
    front_.push_back(value);
    size_++;
  }

  void PushBack(const T& value) {
    back_.push_back(value);
    size_++;
  }

private:
  
  size_t size_ = 0;
  std::vector<T> back_;
  std::vector<T> front_;

  T& getTrueIndex(size_t index) {
    const size_t front_size = front_.size();
    if(index < front_size) {
      return front_[front_size - index - 1];
    } else {
      return back_[index - front_size];
    }
  }

  const T& getTrueIndex(size_t index) const {
    const size_t front_size = front_.size();
    if(index < front_size) {
      return front_[front_size - index - 1];
    } else {
      return back_[index - front_size];
    }
  }

};

int main() {

  Deque<int> x;
  
  x.PushBack(1);
  x.PushBack(1);
  
  std::cout << x[0] << std::endl;

}