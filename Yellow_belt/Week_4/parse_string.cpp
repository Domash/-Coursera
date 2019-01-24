//
//  parse_string.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/25/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

std::vector<std::string> SplitIntoWords(const std::string& s) {
  std::vector<std::string> result;
  auto iterator_first = s.begin();
  auto iterator_last = std::find(s.begin(), s.end(), ' ');
  while(iterator_first != iterator_last) {
    result.emplace_back(std::string(iterator_first, iterator_last));
    (iterator_last == s.end()) ? iterator_first = iterator_last : iterator_first = iterator_last + 1;
    iterator_last = std::find(iterator_first, s.end(), ' ');
  }
  return result;
}

int main() {

   std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
      if (it != begin(words)) {
        std::cout << "/";
      }
      std::cout << *it;
    }
    std::cout << std::endl;

  return 0;
}
