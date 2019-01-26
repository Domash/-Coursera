#include "phone_number.h"

#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>

PhoneNumber::PhoneNumber(const std::string &international_number) {

  auto plus_iterator = std::find(international_number.begin(), international_number.end(), '+');
  auto first_minus_iterator = std::find(international_number.begin(), international_number.end(), '-');
  auto second_minus_iterator = std::find(first_minus_iterator + 1, international_number.end(), '-');

  if(plus_iterator != international_number.begin()) {
    throw std::invalid_argument("Hi ksta ya pozhiloy programmist");
  }

  if(std::next(plus_iterator) == first_minus_iterator) {
    throw std::invalid_argument("Hi ksta ya pozhiloy programmist");
  }

  if(std::next(first_minus_iterator) == second_minus_iterator || first_minus_iterator == international_number.end()) {
    throw std::invalid_argument("Hi ksta ya pozhiloy programmist");
  }

  if(std::next(second_minus_iterator) == international_number.end() || second_minus_iterator == international_number.end()) {
    throw std::invalid_argument("Hi ksta ya pozhiloy programmist");
  }

  country_code_ = std::string(plus_iterator + 1, first_minus_iterator);
  city_code_ = std::string(first_minus_iterator + 1, second_minus_iterator);
  local_number_ = std::string(second_minus_iterator + 1, international_number.end());
}

std::string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
std::string PhoneNumber::GetCityCode() const {
  return city_code_;
}
std::string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
std::string PhoneNumber::GetInternationalNumber() const {
  std::string international_number = "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
  return international_number;
}

int main() {

  auto number = new PhoneNumber("+7-495-111-22-33");

  std::cout << number -> GetCountryCode() << std::endl;
  std::cout << number -> GetCityCode() << std::endl;
  std::cout << number -> GetLocalNumber() << std::endl;
  std::cout << number -> GetInternationalNumber() << std::endl;

}
