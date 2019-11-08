//
//  code_refactoring_v_2.cpp
//  coursera
//
//  Created by Денис Домашевич on 02/27/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  Person(const std::string& name, const std::string& type) : Name(name), Type(type) {}

  virtual void Walk(const std::string& destination) const {
    std::cout << Type << ": " << Name << " walks to: " << destination << std::endl;
  }

  std::string getType() const {
    return Type;
  }

  std::string getName() const {
    return Name;
  }

protected:
  const std::string Name;
  const std::string Type;
};

class Student : public Person {
public:
  Student(const std::string& name, const std::string& favouriteSong) :
    Person(name, "Student"), FavouriteSong(favouriteSong) {}

  void Learn() const {
    std::cout << Type << ": " << Name << " learns" << std::endl;
  }

  void SingSong() const {
    std::cout << Type << ": " << Name << " sings a song: " << FavouriteSong << std::endl;
  }

  void Walk(const std::string& destination) const override {
    std::cout << Type << ": " << Name << " walks to: " << destination << std::endl;
    SingSong();
  }

public:
  const std::string FavouriteSong;
};

class Teacher : public Person {
public:
  Teacher(const std::string& name, const std::string& subject) : Person(name, "Teacher"), Subject(subject) {}

  void Teach() const {
    std::cout << Type << ": " << Name << " teaches: " << Subject << std::endl;
  }

public:
  const std::string Subject;
};

class Policeman : public Person {
public:
  Policeman(const std::string& name) : Person(name, "Policeman") {}

  void Check(const Person& person) const {
    std::cout << Type << ": " << Name << " checks " << person.getType() << ". "
              << person.getType() << "'s name is: " << person.getName() << std::endl;
  }

};

void VisitPlaces(Person& person, std::vector<std::string> places) {
  for(const auto& it : places) {
    person.Walk(it);
  }
}

int main() {

  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});

  return 0;
}
