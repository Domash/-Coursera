#pragma "once"

#include <iostream>
#include <cstring>
#include <cmath>

template <typename T>
class SimpleVector {
public:
  SimpleVector() {};
  explicit SimpleVector(size_t size) {
    size_ = size;
    log_ = calc_log(size);
    capacity_ = (1 << log_);
    data_ = new T[capacity_];
  }
  ~SimpleVector() {
    log_ = -1;
    size_ = 0;
    capacity_ = 0;
    delete[] data_;
  }

  T& operator[](size_t index) {
    return data_[index];
  }

  T* begin() {
    return data_;
  }

  T* end() {
    return data_ + size_;
  }

  size_t Size() const {
    return size_;
  }

  size_t Capacity() const {
    return capacity_;
  }

  void PushBack(const T& value) {
    if(size_ == capacity_) {
      reallocate();
    }
    data_[size_++] = value;
  }

private:
  T* data_ = nullptr;
  size_t log_ = -1;
  size_t size_ = 0;
  size_t capacity_ = 0;

  void reallocate() {
    log_++;
    capacity_ = (1 << log_);
    T* new_data = new T[capacity_];
    for(size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
  }

  size_t calc_log(size_t size) {
    size_t Log = ceil(log(static_cast<double>(size)) / log(static_cast<double>(2)));
    return Log;
  }

};