/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Shapes in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <cmath>

using namespace std;

// Shape base class
class Shape {
protected:
    double width;
    double height;

public:
    Shape(double w, double h) : width(w), height(h) {}
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void display() {
        cout << "Shape: ";
    }
};

// Rectangle class
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}
    double area() override {
        return width * height;
    }
    double perimeter() override {
        return 2 * (width + height);
    }
    void display() override {
        Shape::display();
        cout << "Rectangle" << endl;
    }
};

// Triangle class
class Triangle : public Shape {
public:
    Triangle(double b, double h) : Shape(b, h) {}
    double area() override {
        return 0.5 * width * height;
    }
    double perimeter() override {
        // Assuming it's a right-angled triangle
        return width + height + sqrt(width * width + height * height);
    }
    void display() override {
        Shape::display();
        cout << "Triangle" << endl;
    }
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape(0, 0), radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
    double perimeter() override {
        return 2 * M_PI * radius;
    }
    void display() override {
        Shape::display();
        cout << "Circle" << endl;
    }
};

// Square class
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : Shape(s, s), side(s) {}
    double area() override {
        return side * side;
    }
    double perimeter() override {
        return 4 * side;
    }
    void display() override {
        Shape::display();
        cout << "Square" << endl;
    }
};

int main() {
    // Prompt user for shape choice and dimensions
    int choice;
    double dimension1, dimension2;

    cout << "Select a shape to calculate area and perimeter:" << endl;
    cout << "1. Rectangle" << endl;
    cout << "2. Triangle" << endl;
    cout << "3. Circle" << endl;
    cout << "4. Square" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    Shape* shape = nullptr;

    switch (choice) {
    case 1:
        cout << "Enter width and height of the rectangle: ";
        cin >> dimension1 >> dimension2;
        shape = new Rectangle(dimension1, dimension2);
        break;
    case 2:
        cout << "Enter base and height of the triangle: ";
        cin >> dimension1 >> dimension2;
        shape = new Triangle(dimension1, dimension2);
        break;
    case 3:
        cout << "Enter radius of the circle: ";
        cin >> dimension1;
        shape = new Circle(dimension1);
        break;
    case 4:
        cout << "Enter side length of the square: ";
        cin >> dimension1;
        shape = new Square(dimension1);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return 1;
    }

    // Calculate and display area and perimeter
    shape->display();
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;

    delete shape;

    return 0;
}
