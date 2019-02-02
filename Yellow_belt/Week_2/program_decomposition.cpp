//
//  program_decomposition.cpp
//  coursera
//
//  Created by Денис Домашевич on 2/2/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <map>

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  std::string bus;
  std::string stop;
  std::vector <std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
  std::string operation_code;
  is >> operation_code;

  if(operation_code == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;

  } else if(operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
  } else if(operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
  } else if(operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {

};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {

  return os;
}

struct StopsForBusResponse {

};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {

  return os;
}

struct AllBusesResponse {

};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {

}

class BusManager {
public:
  void AddBus(const std::string& bus, const std::vector<std::string>& stops) {

  }

  BusesForStopResponse GetBusesForStop(const std::string& stop) const {

  }

  StopsForBusResponse GetStopsForBus(const std::string& bus) const {

  }

  AllBusesResponse GetAllBuses() const {
    std::vector <std::string> buses;
    for(const auto& bus_item : buses_to_stops) {
      buses.push_back(bus_item.second);
    }
    return AllBusesResponse(buses);
  }

private:
  std::map<std::string, std::vector<std::string>> buses_to_stops, stops_to_buses;
};

int main() {

  int query_count;
  Query q;

  std::cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    std::cin >> q;
    switch (q.type) {
      case QueryType::NewBus:
        bm.AddBus(q.bus, q.stops);
        break;
      case QueryType::BusesForStop:
        std::cout << bm.GetBusesForStop(q.stop) << std::endl;
        break;
      case QueryType::StopsForBus:
        std::cout << bm.GetStopsForBus(q.bus) << std::endl;
        break;
      case QueryType::AllBuses:
        std::cout << bm.GetAllBuses() << std::endl;
        break;
    }
  }

  return 0;
}
