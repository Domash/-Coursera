//
//  arithmetic expression_v_2.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/29/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <string>

bool get_operation_priority(const std::string& op) {
  return (op == "+" || op == "-") ? 0 : 1;
}

int main() {

  std::string expr;
  std::cin >> expr;

  int queries;
  std::cin >> queries;

  std::string prev = "", op, number, last_op = "*";
  for(int i = 0; i < queries; ++i) {
    std::cin >> op >> number;
    if(get_operation_priority(last_op) < get_operation_priority(op))
      prev += "(", expr += ")";
    expr += " " + op + " " + number;
    last_op = op;
  }

  std::cout << prev << expr << std::endl;

  return 0;
}
