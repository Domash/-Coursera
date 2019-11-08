//
//  item_reference.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/16/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

template <class V, class U>
V& GetRefStrict(std::map<U, V> &m, U key) {
  if(m.find(key) == m.end()) {
    throw std::runtime_error("Invalid Key");
  }
  return m[key];
}

int main() {

  std::map<int, std::string> m = {{0, "value"}};
  std::string& item = GetRefStrict(m, 0);
  item = "newvalue";
  std::cout << m[0] << std::endl;

  return 0;

}
