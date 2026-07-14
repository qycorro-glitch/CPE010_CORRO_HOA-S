#include <iostream>
#include <cmath>

double d1, e1, d2, e2;
double distance ;


int main() {
    std::cout << "Enter coordinates x1: ";
    std::cin >> d1;
    std::cout << "Enter coordinates y1: ";
    std::cin >> e1;
    std::cout << "Enter coordinates x1: ";
    std::cin >> d2;
    std::cout << "Enter coordinates y2: ";
    std::cin >> e2;
    distance = sqrt(pow( d2- d1, 2) + pow(e2 - e1, 2));
    std::cout << "Distance is = " << distance << std::endl;

    return 0;
}