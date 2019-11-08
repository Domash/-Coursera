//
//  character_grouping.cpp
//  coursera
//
//  Created by Денис Домашевич on 13/2/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>

template <typename RandomIt>
std::pair <RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
                                              RandomIt range_end, char prefix) {
  std::pair <RandomIt, RandomIt> result;
  std::string s = ""; s += prefix;
  result.first = lower_bound(range_begin, range_end, std::string(1, prefix));
  result.second = lower_bound(range_begin, range_end, std::string(1, static_cast<char>(prefix + 1)));
  return result;
}

template <typename RandomIt>
std::pair <RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
                                              RandomIt range_end, const std::string& prefix) {
  std::pair <RandomIt, RandomIt> result;
  result.first = lower_bound(range_begin, range_end, prefix);
  result.second = upper_bound(range_begin, range_end, prefix + static_cast<char>(228));
  return result;
}

int main() {

  const std::vector<std::string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

  const auto m_result =
      FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "mo");
  for (auto it = m_result.first; it != m_result.second; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  const auto p_result =
      FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "mt");
  std::cout << (p_result.first - std::begin(sorted_strings)) << " " <<
      (p_result.second - std::begin(sorted_strings)) << std::endl;

  const auto z_result =
      FindStartsWith(std::begin(sorted_strings), std::end(sorted_strings), "na");
  std::cout << (z_result.first - std::begin(sorted_strings)) << " " <<
      (z_result.second - std::begin(sorted_strings)) << std::endl;

  return 0;
}
