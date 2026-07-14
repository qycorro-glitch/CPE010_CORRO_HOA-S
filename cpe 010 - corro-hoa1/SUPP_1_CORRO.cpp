// . Create a C++ program to swap the two numbers in different variables
#include <iostream>

int main() {
    int a,b,temp;
    std::cout << " Enter first number: ";
    std::cin >> a;
    std::cout << " Enter second number: ";
    std::cin >> b;

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nAfter swapping the first number and second number, the result is: \n";
    std::cout << "First number = " << a << "\nSecond number = " << b << std::endl;

}

