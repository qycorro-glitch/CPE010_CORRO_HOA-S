#include <iostream>

bool boperation(bool a, bool b);

int main() {
    bool x, y;

    std::cout << "Enter first boolean value: ";
    std::cin >> x;

    std::cout << "Enter second boolean value: ";
    std::cin >> y;

    std::cout << "\n--- Results ---\n";

    bool success = boperation(x, y);

    if (success) {
        std::cout << "\nFunction executed successfully!\n";
    }

    return 0;
}

bool boperation(bool a, bool b) {
    std::cout << std::boolalpha;

    std::cout << a << " AND " << b << " (&&) : " << (a && b) << "\n";
    std::cout << a << " OR " << b << " (||)  : " << (a || b) << "\n";
    std::cout << "NOT " << a << " (!)  : " << (!a) << "\n";
    std::cout << "NOT " << b << " (!)  : " << (!b) << "\n";

    return true;
}