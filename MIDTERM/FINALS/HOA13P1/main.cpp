
#include <iostream>
#include <thread>
#include <mutex>
int globalVariable = 0;
std::mutex mtx;

// Function that adds an integer to the global variable
void add(int value)
{
    std::lock_guard<std::mutex> lock(mtx);
    globalVariable += value;
}

int main()
{
    // Create three threads
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // Display the initial/current value
    std::cout << "Initial Display: " << globalVariable << std::endl;

    // Wait for Thread 1
    T1.join();
    std::cout << "After T1.join(): " << globalVariable << std::endl;

    // Wait for Thread 2
    T2.join();
    std::cout << "After T2.join(): " << globalVariable << std::endl;

    // Wait for Thread 3
    T3.join();
    std::cout << "After T3.join(): " << globalVariable << std::endl;

    return 0;
}
