#include <iostream>
#include <string>

const int maxCap = 100;
char stack[maxCap];
int top = -1;

void push(char data);
char pop();
void Top();
bool isEmpty();
bool isFull();
bool isBalanced(std::string expression);
void displayStack();

int main() {

    std::string expression;
    char choice;

    do {
        std::cout << "Enter expression: ";
        std::getline(std::cin, expression);

        if (isBalanced(expression))
            std::cout << "\nExpression is Balanced." << std::endl;
        else
            std::cout << "\nExpression is NOT Balanced." << std::endl;

        std::cout << "\nDo you want to check another expression? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore();  
    } while (choice == 'Y' || choice == 'y');

    std::cout << "\nProgram Ended." << std::endl;

    return 0;
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == maxCap - 1;
}

// Push
void push(char data) {
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    stack[++top] = data;

    std::cout << "\nPush: " << data << std::endl;
    displayStack();
}

// Pop
char pop() {
    if (isEmpty()) {
        return '\0';
    }

    char temp = stack[top--];

    std::cout << "\nPop: " << temp << std::endl;
    displayStack();

    return temp;
}

// Display Top
void Top() {
    if (isEmpty()) {
        std::cout << "Top: Stack is Empty" << std::endl;
        return;
    }

    std::cout << "Top Element: " << stack[top] << std::endl;
}

// Display Stack
void displayStack() {

    if (isEmpty()) {
        std::cout << "Stack: Empty" << std::endl;
        return;
    }

    std::cout << "Stack: ";

    for (int i = top; i >= 0; i--) {
        std::cout << stack[i] << " ";
    }

    std::cout << std::endl;

    Top();
}

// Balanced Symbols
bool isBalanced(std::string expression) {

    top = -1;

    for (int i = 0; i < expression.length(); i++) {

        char ch = expression[i];

        // Opening Symbols
        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        }

        // Closing Symbols
        else if (ch == ')' || ch == ']' || ch == '}') {

            if (isEmpty()) {
                return false;
            }

            char open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }
        }
    }

    return isEmpty();
}