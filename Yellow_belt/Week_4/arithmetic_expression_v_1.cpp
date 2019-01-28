//
//  arithmetic expression_v_1.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/29/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <string>

int main() {

  std::string expr;
  std::cin >> expr;

  int queries;
  std::cin >> queries;

  std::string prev = "", op, number;
  for(int i = 0; i < queries; ++i) {
    prev += "(";
    std::cin >> op >> number;
    expr += ") " + op + " " + number;
  }

  std::cout << prev << expr << std::endl;

  return 0;
}
