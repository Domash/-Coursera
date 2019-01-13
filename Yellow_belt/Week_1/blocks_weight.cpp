//
//  blocks_weight.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/13/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>

int main() {

  long long n, m;
  std::cin >> n >> m;

  long long result = 0;
  for(size_t i = 0; i < n; ++i) {
    long long w, h, d;
    std::cin >> w >> h >> d;
    result += w * h * d * m;
  }

  std::cout << result << std::endl;

  return 0;

}
