//
//  bad_macros.cpp
//  coursera
//
//  Created by Денис Домашевич on 05/03/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <sstream> 

#define PRINT_VALUES(out, x, y) out << (x) << "\n" << (y) << std::endl 

int main() {

  std::ostringstream output;

  if (true) {
    PRINT_VALUES(output, 5, "red belt");
  } else {
    std::cout << 2 << std::endl;
  }

  std::cout << output.str() << std::endl;

  return 0;
}