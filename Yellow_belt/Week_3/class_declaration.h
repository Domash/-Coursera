//
//  class_declaration.h
//  coursera
//
//  Created by Денис Домашевич on 1/25/19.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#pragma once

class Rectangle {
public:
  Rectangle(int width, int height);

  int GetArea() const;
  int GetPerimeter() const;

  int GetWidth() const;
  int GetHeight() const;
private:
  int width;
  int height;
};
