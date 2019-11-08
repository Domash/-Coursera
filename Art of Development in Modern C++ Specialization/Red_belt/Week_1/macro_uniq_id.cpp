//
//  macro_uniq_id.cpp
//  coursera
//
//  Created by Денис Домашевич on 05/03/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <map>

//#include "airline_ticket.h"
#include "Comp_gen/airline_ticket.h"

bool operator < (const Date& lhs, const Date& rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator == (const Date& lhs, const Date& rhs) {
  return std::tie(lhs.year, lhs.month, lhs.day) == std::tie(rhs.year, rhs.month, rhs.day);
}

bool operator < (const Time& lhs, const Time& rhs) {
  return std::tie(lhs.hours, lhs.minutes) < std::tie(rhs.hours, rhs.minutes);
}

bool operator == (const Time& lhs, const Time& rhs) {
  return std::tie(lhs.hours, lhs.minutes) == std::tie(rhs.hours, rhs.minutes);
}

std::ostream& operator << (std::ostream& os, const Date& d) {
  return os << d.year << '-' << d.month << '-' << d.day;
}

std::ostream& operator << (std::ostream& os, const Time& t) {
  return os << t.hours << ':' << t.minutes;
}

Time& operator >> (const std::istringstream& in, Time& val) {
  Time result;
  std::string curr = "";
  int a[2]; int p = 0;
  for(const auto& c : in.str()) {
    if(c >= '0' && c <= '9') {
      curr += c;
    } else {
      a[p] = std::stoi(curr);
      p++;
      curr = "";
    }
  }
  a[p] = std::stoi(curr);
  val.hours = a[0];
  val.minutes = a[1];
  return val;
}

Date& operator >> (const std::istringstream& in, Date& val) {
  Date result;
  std::string curr = "";
  int a[3]; int p = 0;
  for(const auto& c : in.str()) {
    if(c >= '0' && c <= '9') {
      curr += c;
    } else {
      a[p] = std::stoi(curr);
      p++;
      curr = "";
    }
  }
  a[p] = std::stoi(curr);
  val.year = a[0];
  val.month = a[1];
  val.day = a[2];
  return val;
}

#define GET_VARIABLE_NAME(Variable) (#Variable) 

#define UPDATE_FIELD(ticket, field, values){\
  if(values.find(GET_VARIABLE_NAME(field)) != values.end()) { \
    std::istringstream is(values.find(GET_VARIABLE_NAME(field))->second); \
    is >> ticket.field; \
  }\
}



void TestUpdate() {
  
  AirlineTicket t;
  t.price = 0;

  const std::map<std::string, std::string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
    {"price", "231231"},
    {"to", "bellll"}
  };

  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);
  UPDATE_FIELD(t, to, updates1);
  

  std::cout << t.departure_date.year << ' '
            << t.departure_date.month << ' '
            << t.departure_date.day << ' '
            << t.departure_time.hours << ' '
            << t.departure_time.minutes << ' '
            << t.price << ' '
            << t.to << ' ';
}


int main() {

  TestUpdate();
  
  return 0;
}