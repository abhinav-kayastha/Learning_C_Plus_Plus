#include <iostream>
#include <string>

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int main() {
    while (true) {
        float num1 = 0;
        float num2 = 0;
        std::string choice;

        std::cout << "Enter operation type (+, -, *, /, q): ";
        std::cin >> choice;

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        if (choice == "+") {
            std::cout << "Result: " << add(num1, num2) << std::endl;
        } else if (choice == "-") {
            std::cout << "Result: " << subtract(num1, num2) << std::endl;
        } else if (choice == "*") {
            std::cout << "Result: " << multiply(num1, num2) << std::endl;
        } else if (choice == "/") {
            std::cout << "Result: " << divide(num1, num2) << std::endl;
        } else if (choice == "q") {
            return 0;
        } else {
            std::cout << "Invalid operation type" << std::endl;
        }
    }
    return 0;
}