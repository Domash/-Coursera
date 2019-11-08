//
//  find_nearest_element.cpp.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/29/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <set>

std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border) {
  std::set<int>::const_iterator iterator = numbers.lower_bound(border);
  if(iterator == numbers.begin()) return iterator;
  if(iterator == numbers.end()) return std::prev(iterator);

  std::set<int>::const_iterator prev_iterator = std::prev(iterator);
  if(std::abs(*prev_iterator - border) <= std::abs(*iterator - border)) {
    return prev_iterator;
  } else {
    return iterator;
  }
}

int main() {
  std::set<int> numbers = {1, 4, 6};

  std::cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << std::endl;

  std::set<int> empty_set;

  std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;
}
