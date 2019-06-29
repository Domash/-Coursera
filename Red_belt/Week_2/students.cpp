#include <iostream>
#include <string>
#include <map>

struct Student {
  std::string first_name;
  std::string last_name;
  std::map<std::string, double> marks;
  double rating;

  bool operator < (const Student& other) const {
    return GetName() < other.GetName();
  }

  bool Less(const Student& other) const {
    return rating > other.rating;
  }

  std::string GetName() const {
    return first_name + " " + last_name;
  }
};

bool Compare(const Student& first, const Student& second) {
  return first.Less(second);
}

int main() {


}