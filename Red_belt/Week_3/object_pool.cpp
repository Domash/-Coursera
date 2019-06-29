#include "test_runner.h"

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <set>

template <class T>
class ObjectPool {
public:
  T* Allocate() {
    if(!released.empty()) {
      T* object = released.front();
      highlighted.insert(object);
      released.pop_front();
      return object;
    }
    T* object = new T;
    highlighted.insert(object);
    return object;
  }

  T* TryAllocate() {
    if(!released.empty()) {
      T* object = released.front();
      highlighted.insert(object);
      released.pop_front();
      return object;
    }
    return nullptr;
  }

  void Deallocate(T* object) {
    auto iterator = highlighted.find(object);
    if(iterator == highlighted.end()) {
      throw std::invalid_argument("Invalid pointer");
    }
    highlighted.erase(iterator);
    released.push_back(object);
  }

  ~ObjectPool() {
    for(auto& it : released) {
      delete it;
    }
    for(auto& it : highlighted) {
      delete it;
    }
  }

private:
  std::deque<T*> released;
  std::set<T*> highlighted;
};

// void TestObjectPool() {
//   ObjectPool<string> pool;

//   auto p1 = pool.Allocate();
//   auto p2 = pool.Allocate();
//   auto p3 = pool.Allocate();

//   *p1 = "first";
//   *p2 = "second";
//   *p3 = "third";

//   pool.Deallocate(p2);
//   ASSERT_EQUAL(*pool.Allocate(), "second");

//   pool.Deallocate(p3);
//   pool.Deallocate(p1);
//   ASSERT_EQUAL(*pool.Allocate(), "third");
//   ASSERT_EQUAL(*pool.Allocate(), "first");

//   pool.Deallocate(p1);
// }

int main() {
  //TestRunner tr;
  //RUN_TEST(tr, TestObjectPool);
  return 0;
}