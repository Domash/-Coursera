#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "airline_ticket.h"

bool operator < (const Time& lhs, const Time& rhs) {
  if(lhs.hours == rhs.hours) return lhs.minutes < rhs.minutes;
  return lhs.hours < rhs.hours;
}
int year, month, day;
bool operator < (const Date& lhs, const Date& rhs) {
  if(lhs.year != rhs.year) return lhs.year < rhs.year;
  if(lhs.month != rhs.month) return lhs.month < rhs.month;
  return lhs.day < rhs.day;
}

#define SORT_BY(field) \
  [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
     return lhs.field < rhs.field; \
  }                                                        

void TestSortBy() {
  std::vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  std::sort(begin(tixs), end(tixs), SORT_BY(price));
  for(const auto& it : tixs) {
    std::cout << it.from << std::endl;
  }
}

int main() {

  TestSortBy();

}