#include <unordered_map>
#include <iostream>
#include <tuple>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>

struct Hostel {
  Hostel(){}

  void add(long long time, int client_id, int room_count) {
    idd[client_id]++;
    if(idd[client_id] == 1) more_one++;
    clients.push({time, client_id, room_count});
    total_cnt += room_count;
  }

  bool isToday(long long time_t, long long current_time) {
    return time_t <= (current_time - 86400);
  }

  void pop(long long ttt) {
    while(true) {
      if(clients.size() == 0) break;
      if(isToday(std::get<0>(clients.front()), ttt)) {
        total_cnt -= std::get<2>(clients.front());
        idd[std::get<1>(clients.front())]--;
        if(idd[std::get<1>(clients.front())] == 0) {
          more_one--;
        }
        clients.pop();
      } else break;
    }
  }

  std::unordered_map<int, int> idd;
  std::queue<std::tuple<long long, int, int>> clients;
  int total_cnt = 0;
  int more_one = 0;
};

long long current_time = 0;
std::map<std::string, Hostel> hostels;

int clients_query(const std::string& hostel) {
  if(hostels.count(hostel) == 0) {
    return 0;
  }
  Hostel curr_hostel = hostels[hostel];
  curr_hostel.pop(current_time);
  return curr_hostel.more_one;
}

int room_query(std::string& hostel) {
  if(hostels.count(hostel) == 0) {
    return 0;
  }
  Hostel curr_hostel = hostels[hostel];
  curr_hostel.pop(current_time);
  return curr_hostel.total_cnt;
}

int main() {

  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  while(n--) {
    std::string query;
    std::cin >> query;
    if(query == "CLIENTS") {
      std::string hostel; 
      std::cin >> hostel;
      std::cout << clients_query(hostel) << "\n";
    } else if(query == "ROOMS") {
      std::string hostel; 
      std::cin >> hostel;
      std::cout << room_query(hostel) << "\n";
    } else if(query == "BOOK") {
      long long time;
      std::string hostel;
      int id, count;
      std::cin >> time >> hostel >> id >> count;
      hostels[hostel].add(time, id, count);
      current_time = time;
    }
  }

  return 0;
}