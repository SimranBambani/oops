#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual float Area() = 0;
    virtual ~Shape() {}
};
class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float Area() {
        return length * width;
    }

    ~Rectangle() {}
};
class Circle : public Shape {
    float radius;
public:
    Circle(float r) : radius(r) {}

    float Area()  {
        return 3.14f * radius * radius;
    }

    ~Circle() {}
};
void Display_Area(Shape* shapes[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "Area of shape[" << i << "]: " << shapes[i]->Area() << endl;
    }
}
int main() {
    int max_shapes = 5;
    Shape* shapes[max_shapes];
    int shape_count = 0;
    shapes[shape_count++] = new Rectangle(10, 5);
    shapes[shape_count++] = new Circle(7);
    shapes[shape_count++] = new Rectangle(3, 8);
    shapes[shape_count++] = new Circle(4.2);
    Display_Area(shapes, shape_count);
    for (int i = 0; i < shape_count; i++) {
        delete shapes[i];
    }
    return 0;
}
