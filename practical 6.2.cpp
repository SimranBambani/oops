#include <iostream>
using namespace std;
class Coordinate_Points {
    int x, y;
public:
    Coordinate_Points(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void Get_Data() {
        cout << "Enter x and y coordinates: ";
        cin >> x >> y;
    }
    void Update_Coordinates(int dx, int dy) {
        x += dx;
        y += dy;
    }
    void Display_Data()  {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
    void Update_From(Coordinate_Points* other) {
        if (other != nullptr) {
            x = other->x;
            y = other->y;
        }
    }
};
int main() {
    Coordinate_Points* p1 = new Coordinate_Points();
    p1->Get_Data();
    int dx, dy;
    cout << "Enter shift in x and y: ";
    cin >> dx >> dy;
    p1->Update_Coordinates(dx, dy);
    p1->Display_Data();
    Coordinate_Points* p2 = new Coordinate_Points();
    cout << "Enter new point to update from:\n";
    p2->Get_Data();
    p1->Update_From(p2);
    cout << "After updating from second point: ";
    p1->Display_Data();
    delete p1;
    delete p2;
    return 0;
}
