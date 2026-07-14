//Create a C++ program that has a function to convert temperature in Kelvin to Fahrenheit

#include <iostream>
double KelvtoFar(double kelvin) ;
    double kelvin;
    double far;

    double KelvtoFar(double kelvin) {
    double far =  (kelvin - 273.15) * 9 / 5 + 32;
        return far;
}

int main() {

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;

        far = KelvtoFar(kelvin);
    std::cout << "Temperature in Fahrenheit: " << far << std::endl;

    return 0;
}
