//
//  rational.cpp
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

class Rational {
public:

  Rational() {
    numerator_ = 0;
    denominator_ = 1;
  }
  Rational(int numerator, int denominator) {
    int neg = ((numerator < 0) + (denominator < 0)) % 2;
    numerator = abs(numerator);
    denominator = abs(denominator);
    if(neg) numerator *= -1;

    int GCD = gcd(numerator, denominator);
    numerator /= GCD; denominator /= GCD;

    numerator_ = numerator;
    denominator_ = denominator;
  }

  int Numerator() const {
    return numerator_;
  }

  int Denominator() const {
    return denominator_;
  }

  int gcd (int a, int b) {
  	while (b) {
  		a %= b;
  		swap (a, b);
  	}
  	return a;
  }
private:
  int numerator_, denominator_;
};

void TEST() {
  Rational *r = new Rational();
  AssertEqual(r -> Numerator(), 0);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(-1, -1);
  AssertEqual(r -> Numerator(), 1);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(-1, 1);
  AssertEqual(r -> Numerator(), -1);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(1, -1);
  AssertEqual(r -> Numerator(), -1);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(2, 10);
  AssertEqual(r -> Numerator(), 1);
  AssertEqual(r -> Denominator(), 5);

  r = new Rational(100, 111);
  AssertEqual(r -> Numerator(), 100);
  AssertEqual(r -> Denominator(), 111);

  r = new Rational(0, -1);
  AssertEqual(r -> Numerator(), 0);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(0, 111111);
  AssertEqual(r -> Numerator(), 0);
  AssertEqual(r -> Denominator(), 1);

  r = new Rational(2, 3);
  AssertEqual(r -> Numerator(), 2);
  AssertEqual(r -> Denominator(), 3);

  r = new Rational(4, 6);
  AssertEqual(r -> Numerator(), 2);
  AssertEqual(r -> Denominator(), 3);

}

int main() {
  TestRunner runner;
  runner.RunTest(TEST, "TEST");

  return 0;
}









//eqw
