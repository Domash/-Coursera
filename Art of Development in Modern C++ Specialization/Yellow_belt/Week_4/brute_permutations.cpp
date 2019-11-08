//
//  brute_permutations.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/24/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main() {

  int n;
  std::cin >> n;

  std::vector<int> v;
  for(int i = n; i >= 1; --i) {
    v.emplace_back(i * -1);
  }

  do {
    for(const auto& it : v) {
      std::cout << it * -1 << ' ';
    }
    std::cout << std::endl;
  } while(std::next_permutation(v.begin(), v.end()));

}
