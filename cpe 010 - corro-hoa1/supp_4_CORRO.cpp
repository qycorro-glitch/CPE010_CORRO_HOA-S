#include <iostream>
#include <cmath>

class Triangle {
private:
    double totalAngle, fangle, sangle, tangle;
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C,
             double sA, double sB, double sC);

    bool validateTriangle();
    double perimeter();
    double area();
    void triangleType();
};

Triangle::Triangle(double A, double B, double C,
                   double sA, double sB, double sC) {
    fangle = A;
    sangle = B;
    tangle = C;

    sideA = sA;
    sideB = sB;
    sideC = sC;

    totalAngle = A + B + C;
}

bool Triangle::validateTriangle() {
    return totalAngle == 180;
}

double Triangle::perimeter() {
    return sideA + sideB + sideC;
}

double Triangle::area() {
    double s = perimeter() / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triangleType() {
    if (fangle == 90 || sangle == 90 || tangle == 90)
        std::cout << "Right Triangle\n";
    else if (fangle > 90 || sangle > 90 || tangle > 90)
        std::cout << "Obtuse Triangle\n";
    else
        std::cout << "Acute Triangle\n";
}

int main() {
    double A, B, C;
    double side1, side2, side3;

    std::cout << "Enter three angles: ";
    std::cin >> A >> B >> C;

    std::cout << "Enter three sides: ";
    std::cin >> side1 >> side2 >> side3;

    Triangle set1(A, B, C, side1, side2, side3);

    if (set1.validateTriangle()) {
        std::cout << "The shape triangle is valid.\n";
        std::cout << "Perimeter: " << set1.perimeter() << std::endl;
        std::cout << "Area: " << set1.area() << std::endl;
        std::cout << "Type: ";
        set1.triangleType();
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}
