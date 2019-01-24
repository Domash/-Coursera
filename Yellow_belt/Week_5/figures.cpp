//
//  figures.cpp
//  coursera
//
//  Created by Денис Домашевич on 10/9/18.
//  Copyright © 2018 Денис Домашевич. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cmath>

class Figure {
public:
    virtual std::string Name() = 0;
    virtual long double Perimetr() = 0;
    virtual long double Area() = 0;
};

class Rect : public Figure {
public:
    Rect(long double width, long double height)
        : _width(width), _height(height) {}

    std::string Name() {
        return std::string("RECT");
    }

    long double Perimetr() {
        return 2 * (_width + _height);
    }

    long double Area() {
        return _width * _height;
    }

private:
    long double _width, _height;
};

class Circle : public Figure {
public:
    Circle(long double radius)
        : _radius(radius) {}

    std::string Name() {
        return std::string("CIRCLE");
    }

    long double Perimetr() {
        return 2 * M_PI * _radius;
    }

    long double Area() {
        return M_PI * _radius * _radius;
    }

private:
    long double _radius;
};

class Triangle : public Figure {
public:
    Triangle(long double a, long double b, long double c)
        :_a(a), _b(b), _c(c) {}

    std::string Name() {
        return std::string("TRIANGLE");
    }

    long double Perimetr() {
        return _a + _b + _c;
    }

    long double Area() {
        long double p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }

private:
    long double _a, _b, _c;
};

std::shared_ptr<Figure> CreateFigure(std::istringstream& is){
    std::string figure_type;
    is >> figure_type;

    if(figure_type == "RECT") {
        long double width, height;
        is >> width >> height;
        return std::shared_ptr<Figure>(new Rect(width, height));
    }
    if(figure_type == "CIRCLE") {
        long double radius;
        is >> radius;
        return std::shared_ptr<Figure>(new Circle(radius));
    }
    if(figure_type == "TRIANGLE") {
        long double a, b, c;
        is >> a >> b >> c;
        return std::shared_ptr<Figure>(new Triangle(a, b, c));
    }

    return nullptr;
}

int main(int argc, const char * argv[]) {

    std::vector <std::shared_ptr<Figure>> figures;
    for(std::string line; std::getline(std::cin, line);) {
        std::istringstream is(line);

        std::string command;
        is >> command;

        if(command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if(command == "PRINT") {
            for(const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                << current_figure -> Name() << ' '
                << current_figure -> Perimetr() << ' '
                << current_figure -> Area() << ' ' << std::endl;
            }
        } else if(command == "EXIT") {
            break;
        }
    }

    return 0;
}
