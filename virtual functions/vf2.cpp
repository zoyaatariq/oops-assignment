
#include <iostream>
using namespace std;

class Distance {
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int f, float i) : feet(f), inches(i) {}
    Distance(float fl) {
        feet = int(fl);
        inches = (fl - feet) * 12;
    }
    void display() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    friend Distance operator*(float m, const Distance& d);
};

Distance operator*(float m, const Distance& d) {
    float total_inches = (d.feet * 12 + d.inches) * m;
    int f = int(total_inches / 12);
    float i = total_inches - f * 12;
    return Distance(f, i);
}

int main() {
    Distance dist1(5, 8.5);
    Distance dist2;

    dist2 = 7.5 * dist1;
    dist2.display();

    dist2 = 2.0 * dist1;
    dist2.display();

    dist2 = 0.5 * dist1;
    dist2.display();

    return 0;
}

