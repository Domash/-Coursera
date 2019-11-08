//
//  table.cpp
//  coursera
//
//  Created by Денис Домашевич on 05/02/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <vector>

template <typename T>
class Table {
public:
  Table(std::size_t rows, std::size_t columns) {
    Resize(rows, columns);
  }
  ~Table() {}

  std::vector<T>& operator [](std::size_t index) {
    return table_[index];
  }

  const std::vector<T>& operator [](std::size_t index) const {
    return table_[index];
  }

  void Resize(std::size_t rows, std::size_t columns) {
    rows_ = rows;
    columns_ = columns;
    table_.resize(rows);
    for(auto& row : table_) {
      row.resize(columns);
    }
  }

  std::pair<std::size_t, std::size_t> Size() const {
    return std::make_pair(rows_, columns_);
  }

private:
  std::size_t rows_;
  std::size_t columns_;
  std::vector<std::vector<T>> table_;
}; 

int main() {

  return 0;
}

