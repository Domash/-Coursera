#include <unordered_map>
#include <iostream>
#include <string>
#include <queue>
#include <map>

struct Info {
  int client_id;
  int room_count;
  long long time;
  std::string hotel_name;
};

long long current_time = 0;

std::map<std::string, int> rooms_in_hotels;
std::map<std::string, std::map<int, int>> amount_of_rooms_by_id;

std::queue <Info> queries_queue;

void clients_query(const std::string& hotel) {
  if(amount_of_rooms_by_id.count(hotel) == 0) {
    std::cout << 0 << "\n"; return;
  }
  std::cout << amount_of_rooms_by_id[hotel].size() << "\n";
}

void rooms_query(const std::string& hotel) {
  if(rooms_in_hotels.count(hotel) == 0) {
    std::cout << 0 << "\n"; return;
  }
  std::cout << rooms_in_hotels[hotel] << "\n";
}

bool is_not_today(long long time) {
  return time <= (current_time - 86400);
}

void make_fit() {
  while(queries_queue.size()) {
    Info curr = queries_queue.front();
    if(is_not_today(curr.time)) {
      rooms_in_hotels[curr.hotel_name] -= curr.room_count;
      amount_of_rooms_by_id[curr.hotel_name][curr.client_id] -= curr.room_count;
      if(amount_of_rooms_by_id[curr.hotel_name][curr.client_id] == 0) {
        amount_of_rooms_by_id[curr.hotel_name].erase(curr.client_id);
      }
      queries_queue.pop();
    } else {
      break;
    }
  }
}

void add(int id, int count, long long time, std::string hotel) {
  Info curr; 
  curr.client_id = id; curr.time = time;
  curr.room_count = count; curr.hotel_name = hotel;
  queries_queue.push(curr);
  current_time = time;
  rooms_in_hotels[hotel] += count;
  amount_of_rooms_by_id[hotel][id] += count; 
}

int main() {
  
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  while(n--) {
    std::string query_type;
    std::cin >> query_type;
    if(query_type == "CLIENTS") {
      std::string hotel; 
      std::cin >> hotel;
      make_fit();
      clients_query(hotel);
    } else if(query_type == "ROOMS") {
      std::string hotel; 
      std::cin >> hotel;
      make_fit();
      rooms_query(hotel);
    } else if(query_type == "BOOK") {
      int id, count;
      long long time;
      std::string hotel;
      std::cin >> time >> hotel >> id >> count;
      add(id, count, time, hotel);
    }
  }
  
  return 0;
}