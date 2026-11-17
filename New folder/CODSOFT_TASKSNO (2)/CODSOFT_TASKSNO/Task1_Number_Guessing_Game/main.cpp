#include <iostream>
#include <random>
#include <limits>

int main() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    char playAgain = 'y';
    std::cout << "=== Number Guessing Game ===\n";
    std::cout << "I have selected a number from 1 to 100.\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        const int secretNumber = distribution(generator);
        int attempts = 0;
        int guess = 0;

        while (guess != secretNumber) {
            std::cout << "\nEnter your guess: ";
            if (!(std::cin >> guess)) {
                std::cout << "Invalid input. Please enter a whole number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (guess < 1 || guess > 100) {
                std::cout << "Please enter a number between 1 and 100.\n";
                continue;
            }

            ++attempts;
            if (guess < secretNumber) {
                std::cout << "Too low! Try again.\n";
            } else if (guess > secretNumber) {
                std::cout << "Too high! Try again.\n";
            } else {
                std::cout << "Correct! You found the number in " << attempts
                          << " attempt(s).\n";
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
