#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

class ReadingManager {
public:
  ReadingManager() {
    pages.resize(1001, 0);
    pref.resize(1001, 0);
  }

  void Read(int user_id, int page_count) {
    if(page_by_user.count(user_id)) {
      pages[page_by_user[user_id]]--;
    }
    page_by_user[user_id] = page_count;
    pages[page_count]++;
    for(int i = 1; i < 1001; ++i) {
      pref[i] = pref[i - 1] + pages[i];
    }
  }

  double Cheer(int user_id) const {
    if(page_by_user.count(user_id) == 0) {
      return 0;
    }
    if(page_by_user.size() == 1) {
      return 1;
    }
    int pos = page_by_user.at(user_id);
    int diff = pref[pos] - pages[pos];
    
    if(diff == 0) return 0; 

    return diff * 1.0 / (pref[1000] - 1);
  }

private:
  std::vector<int> pref;
  std::vector<int> pages;
  std::map<int, int> page_by_user;
};


int main() {

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  std::cin >> query_count;

  for(int query_id = 0; query_id < query_count; ++query_id) {
    std::string query_type;
    std::cin >> query_type;
    int user_id;
    std::cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      std::cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      std::cout << std::setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}