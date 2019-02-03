//
//  program_decomposition.cpp
//  coursera
//
//  Created by Денис Домашевич on 2/3/19.
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
    q.stops.resize(stop_count);
    for (std::string& stop : q.stops) {
      std::cin >> stop;
    }
  } else if(operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if(operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if(operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  std::vector <std::string> buses_;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if(r.buses_.size() == 0) {
    os << "No stop";
  } else {
    for(const auto& bus : r.buses_) {
      os << bus << " ";
    }
  }

  return os;
}

struct StopsForBusResponse {
  std::string bad;
  std::vector <std::string> names;
  std::map <std::string, std::vector <std::string>> buses_;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
  if(r.buses_.size() == 0) {
    os << "No bus";
  } else {
    for(const auto& name : r.names) {
      os << "Stop " << name << ": ";
      if(r.buses_.at(name).size() == 1) {
        os << "no interchange";
      } else {
        for(const auto& it : r.buses_.at(name)) {
          if(it != r.bad) {
            os << it << " ";
          }
        }
      }
      os << "\n";
    }
  }

  return os;
}

struct AllBusesResponse {
  AllBusesResponse(std::map<std::string, std::vector<std::string>> s) {
    buses_to_stops = s;
  }
  std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
  if(r.buses_to_stops.empty()) {
    os << "No buses";
  } else {
    for(const auto& bus_item : r.buses_to_stops) {
      os << "Bus " << bus_item.first << ": ";
      for(const auto& stop : bus_item.second) {
        os << stop << " ";
      }
      os << "\n";
    }
  }

  return os;
}

class BusManager {
public:
  void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    buses_to_stops[bus].clear();
    for(const auto& stop : stops) {
      buses_to_stops[bus].push_back(stop);
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const std::string& stop) const {
    BusesForStopResponse r;
    if(stops_to_buses.count(stop)) {
      for(const auto& bus : stops_to_buses.at(stop)) {
        r.buses_.push_back(bus);
      }
    }
    return r;
  }

  StopsForBusResponse GetStopsForBus(const std::string& bus) const {
    StopsForBusResponse r;
    r.bad = bus;
    if(buses_to_stops.count(bus) != 0) {
      for(const auto& stop : buses_to_stops.at(bus)) {
        r.names.push_back(stop);
        for(const auto& other_bus : stops_to_buses.at(stop)) {
          r.buses_[stop].push_back(other_bus);
        }
      }
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse r(buses_to_stops);
    return r;
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
