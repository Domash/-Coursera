#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <set>

int main() {

  int queries;
  std::cin >> queries;

  std::map<int, std::set<int>> data;

  while(queries--) {
    std::string query;
    std::cin >> query;
    int start, finish;
    std::cin >> start >> finish;
    if(query == "ADD") {
      data[start].insert(finish);
      data[finish].insert(start);
    } else {
      int result = std::abs(start - finish);
      if(data.count(start) >= 1) {
        const std::set<int>& stations = data.at(start);
        const auto position = stations.lower_bound(finish);
        if(position != stations.end()) {
          result = std::min(result, std::abs(finish - *position));
        }
        if(position != stations.begin()) {
          result = std::min(result, std::abs(finish - *std::prev(position)));
        }
      }
      std::cout << result << std::endl;
    }
  }

  return 0;
}