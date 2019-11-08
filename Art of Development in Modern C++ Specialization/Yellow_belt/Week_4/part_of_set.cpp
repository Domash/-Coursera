//
//  part_of_vector.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/25/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <set>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
  std::vector <T> result;
  for(const auto& it : elements) {
    if(it > border) result.emplace_back(it);
  }
  return result;
}

int main() {

  for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;

  return 0;

}
