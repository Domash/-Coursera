//
//  sum_reverse_sort.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/24/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>

#include "sum_reverse_sort.h"

int Sum(int x, int y) {
  return x + y;
}

std::string Reverse(std::string s) {
  std::reverse(s.begin(), s.end());
  return s;
}

void Sort(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
}

int main() {

  return 0;
}
