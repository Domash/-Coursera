//
//  inheritance_animals.cpp
//  coursera
//
//  Created by Денис Домашевич on 1/27/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <cstring>

class Animal {
public:
  Animal(std::string Name_) : Name(Name_) {}
  const std::string Name;
};

class Dog : public Animal {
public:
  Dog(std::string Name_) : Animal(Name_) {}

  void Bark() {
    std::cout << Name << " barks: woof!" << std::endl;
  }
};



int main() {

  Dog Ray("Ray");

  Ray.Bark();

  return 0;
}
