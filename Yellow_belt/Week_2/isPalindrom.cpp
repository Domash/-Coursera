//
//  isPalindrom.cpp
//  coursera
//
//  Created by Денис Домашевич on 2/2/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//


#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
  int len = str.size();
  for(int i = 0; i < len; ++i) {
    if(str[i] != str[len - i - 1]) return false;
  }
  return true;
}

bool TruePalindrom(const string& str) {
  int len = str.size();
  for(int i = 0; i < len; ++i) {
    if(str[i] != str[len - i - 1]) return false;
  }
  return true;
}

string Generator(int len) {
  string res = "";
  for(int i = 0; i < len; ++i) {
    if(rand() % 4 == 0) {
      res += ' ';
    } else {
      res += 'a' + rand() % 3;
    }
  }
  return res;
}

void TEST() {
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j < i * 4 + 22; ++j) {
      string curr = Generator(i);
      sort(curr.begin(), curr.end());
      do {
        AssertEqual(IsPalindrom(curr), TruePalindrom(curr));
      } while(next_permutation(curr.begin(), curr.end()));
    }
  }
}


int main() {

  TestRunner runner;
  runner.RunTest(TEST, "TEST");

  return 0;
}
