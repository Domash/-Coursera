//
//  in_square.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/25/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

template <typename T>
T Sqr(T element);

template <typename T, typename U>
std::map<T, U> Sqr(std::map<T, U> map);

template <typename T, typename U>
std::pair<T, U> Sqr(std::pair<T, U> pair);

template <typename T>
std::vector<T> Sqr(std::vector<T> vector);


int main() {

  std::vector<int> v = {1, 2, 3};
  std::cout << "vector:";
  for (int x : Sqr(v)) {
    std::cout << ' ' << x;
  }
  std::cout << std::endl;

  std::map<int, std::pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  std::cout << "map of pairs:" << std::endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
  }

  return 0;
}

template <typename T>
T Sqr(T element) {
  return element * element;
}

template <typename T>
std::vector<T> Sqr(std::vector<T> vector) {
  for(auto& it : vector) {
    it = Sqr(it);
  }
  return vector;
}

template <typename T, typename U>
std::map<T, U> Sqr(std::map<T, U> map) {
  for(auto& it : map) {
    it.second = Sqr(it.second);
  }
  return map;
}

template <typename T, typename U>
std::pair<T, U> Sqr(std::pair<T, U> pair) {
  pair = std::make_pair(Sqr(pair.first), Sqr(pair.second));
  return pair;
}
