#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nodes.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main()
{
    // LINEAR SEARCH - ARRAY

    int dataset[max_size];

    srand(time(0));

    for (int i = 0; i < max_size; i++)
    {
        dataset[i] = rand();
    }

    for (int i = 0; i < max_size; i++)
    {
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;

    int dataFind;

    std::cout << "Enter number to search: ";
    std::cin >> dataFind;

    linearSearch(dataset, max_size, dataFind);


    // LINEAR SEARCH - LINKED LIST

    // Linked list: J I M L O R D
    Node<char>* name1 = new_node('J');
    Node<char>* name2 = new_node('I');
    Node<char>* name3 = new_node('M');
    Node<char>* name4 = new_node('L');
    Node<char>* name5 = new_node('O');
    Node<char>* name6 = new_node('R');
    Node<char>* name7 = new_node('D');

    // Link the nodes together
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;
    name7->next = nullptr;

    std::cout << "Linear Search for Linked List result: ";
    linearSearchLL(name1, 'D');

    std::cout << "Linear Search for Linked List result: ";
    linearSearchLL(name1, 'X');



    // BINARY SEARCH - ARRAY


    int data[] = {10, 20, 30, 40, 50};

    int findData;

    std::cout << "\nBinary Search for Array" << std::endl;
    std::cout << "Enter number to search: ";
    std::cin >> findData;

    binarySearch(data, 5, findData);


  
    // BINARY SEARCH - LINKED LIST
  
    // Ordered linked list: 10 20 30 40 50
    Node<int>* num1 = new_node(10);
    Node<int>* num2 = new_node(20);
    Node<int>* num3 = new_node(30);
    Node<int>* num4 = new_node(40);
    Node<int>* num5 = new_node(50);

    // Link the nodes together
    num1->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;
    num5->next = nullptr;

    // Display linked list
    std::cout << "\nBinary Search for Linked List: ";

    Node<int>* current = num1;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;

    int findDataLL;

    std::cout << "Enter number to search: ";
    std::cin >> findDataLL;

    binarySearchLL(num1, findDataLL);

    return 0;
}