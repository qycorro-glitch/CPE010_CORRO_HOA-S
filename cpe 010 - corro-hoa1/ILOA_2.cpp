#include <iostream>

void cgreater(int a, int b);

int main() {
    int y, b;

    std::cout << "Enter a number for A: ";
    std::cin >> y;

    std::cout << "Enter a number for B: ";
    std::cin >> b;

    cgreater(y, b);

    return 0;
}

void cgreater(int a, int b) {
    if (a > b) {
        std::cout << "A is greater than B.\n";
    } else {
        std::cout << "A is not greater than B.\n";
    }
}

