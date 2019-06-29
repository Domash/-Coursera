#pragma once

#include "http_request.h"

#include <string_view>
#include <regex>
#include <map>

using namespace std;

class Stats {
public:
  void AddMethod(string_view method);
  void AddUri(string_view uri);
  const map<string_view, int>& GetMethodStats() const;
  const map<string_view, int>& GetUriStats() const;
};

HttpRequest ParseRequest(string_view line) {
  HttpRequest result;
  std::regex delim("\\/");

	std::vector<std::string_view> out(
      std::sregex_token_iterator(s.begin(), s.end(), delim, -1),
      std::sregex_token_iterator()
	);
  result.method = out[0];
  result.uri = out[1];
  result.protocol = out[2];
}