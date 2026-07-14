
#include <iostream>


void sum(int fn, int ln);

int main() {
    sum(6, 11);

    return 0;
}

void sum(int fn, int ln) {
    int total = fn + ln;
    std::cout << "void output: " << total << std::endl;
}
