#include <iostream>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice = 0;
    double firstNumber = 0.0;
    double secondNumber = 0.0;

    std::cout << "=== Simple Calculator ===\n";

    while (choice != 5) {
        std::cout << "\n1. Addition\n"
                  << "2. Subtraction\n"
                  << "3. Multiplication\n"
                  << "4. Division\n"
                  << "5. Exit\n"
                  << "Choose an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid choice. Please enter a number from 1 to 5.\n";
            clearInput();
            continue;
        }

        if (choice == 5) {
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "Please choose a valid option.\n";
            continue;
        }

        std::cout << "Enter the first number: ";
        if (!(std::cin >> firstNumber)) {
            std::cout << "Invalid number.\n";
            clearInput();
            continue;
        }

        std::cout << "Enter the second number: ";
        if (!(std::cin >> secondNumber)) {
            std::cout << "Invalid number.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Result: " << firstNumber + secondNumber << '\n';
                break;
            case 2:
                std::cout << "Result: " << firstNumber - secondNumber << '\n';
                break;
            case 3:
                std::cout << "Result: " << firstNumber * secondNumber << '\n';
                break;
            case 4:
                if (secondNumber == 0.0) {
                    std::cout << "Error: division by zero is not allowed.\n";
                } else {
                    std::cout << "Result: " << firstNumber / secondNumber << '\n';
                }
                break;
        }
    }

    std::cout << "Calculator closed.\n";
    return 0;
}
