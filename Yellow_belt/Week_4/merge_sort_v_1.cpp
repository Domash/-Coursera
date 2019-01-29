//
//  merge_sort_v_1.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/29/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

template <typename RandomIterator>
void MergeSort(RandomIterator range_begin, RandomIterator range_end) {
  if(std::next(range_begin) == range_end) return;
  std::vector <typename RandomIterator::value_type> array(range_begin, range_end);

  int mid = array.size() / 2;
  MergeSort(array.begin(), array.begin() + mid);
  MergeSort(array.begin() + mid, array.end());

  std::merge(array.begin(), array.begin() + mid, array.begin() + mid, array.end(), range_begin);
}

int main() {

  std::vector <int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
