//
//  part_of_vector.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/24/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

void PrintVectorPart(const std::vector <int>& numbers) {
  auto iterator = std::find_if(numbers.begin(), numbers.end(), [](int number) {
    return number < 0;
  });

  for(auto it = iterator; it != numbers.begin();) {
    std::cout << *(--it) << ' ';
  }

}

int main() {

  PrintVectorPart({6, 1, 8, -5, 4});
  PrintVectorPart({-6, 1, 8, -5, 4});
  PrintVectorPart({6, 1, 8, 5, 4});

  return 0;

}
