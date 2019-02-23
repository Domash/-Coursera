//
//  code_refactoring.cpp
//  coursera
//
//  Created by Денис Домашевич on 02/23/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

class Person {
public:
  Person(const std::string& name) {
    Name = name;
  }
  virtual void Walk(const std::string& destination){}

public:
  std::string Name;
};

class Student : public Person {
public:
  Student(const std::string& name, const std::string& favouriteSong) : Person(name) {
    FavouriteSong = favouriteSong;
  }

  void Learn() const {
    std::cout << "Student: " << Name << " learns" << std::endl;
  }

  void SingSong() const {
    std::cout << "Student: " << Name << " sings a song: " << FavouriteSong << std::endl;
  }

  void Walk(const std::string& destination) override {
    std::cout << "Student: " << Name << " walks to: " << destination << std::endl;
    std::cout << "Student: " << Name << " sings a song: " << FavouriteSong << std::endl;
  }

public:
  std::string FavouriteSong;
};

class Teacher : public Person {
public:
  Teacher(const std::string& name, const std::string& subject) : Person(name) {
    Subject = subject;
  }

  void Teach() const {
    std::cout << "Teacher: " << Name << " teaches: " << Subject << std::endl;
  }

  void Walk(const std::string& destination) override {
    std::cout << "Student: " << Name << " walks to: " << destination << std::endl;
  }

public:
  std::string Subject;
};

class Policeman : public Person {
public:
  Policeman(const std::string& name) : Person(name) {}

  template <typename Type>
  void Check(Type t) {
    std::string personType = "Unknow";

    if(std::is_same<Type, Student>::value) personType   = "Student";
    if(std::is_same<Type, Teacher>::value) personType   = "Teacher";
    if(std::is_same<Type, Policeman>::value) personType = "Policeman";

    std::cout << "Policeman: " << Name << " checks "
              << personType << ". " << personType << "'s name is " << t.Name << std::endl;
  }

  void Walk(const std::string& destination) override {
    std::cout << "Policeman: " << Name << " walks to: " << destination << std::endl;
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
