#include "project/recursive_algorithms.h"

#include <exception>
#include <iostream>
#include <vector>

int main() {
    try {
        const int factorialInput = 5;
        const int fibonacciInput = 10;
        const std::vector<int> sortedValues = {1, 3, 5, 7, 9, 11, 13};
        const int searchTarget = 7;
        const std::vector<int> values = {1, 2, 3, 4, 5};

        std::cout << "Recursive Algorithms Laboratory\n"
                  << "Factorial of " << factorialInput << ": "
                  << factorial(factorialInput) << " (iterative: "
                  << factorialIterative(factorialInput) << ")\n"
                  << "Fibonacci number " << fibonacciInput << ": "
                  << fibonacci(fibonacciInput) << " (iterative: "
                  << fibonacciIterative(fibonacciInput) << ")\n"
                  << "Binary search for " << searchTarget
                  << " in sorted values: "
                  << binarySearch(sortedValues, searchTarget)
                  << " (iterative: "
                  << binarySearchIterative(sortedValues, searchTarget)
                  << ")\n"
                  << "Sum of values: " << arraySum(values)
                  << " (iterative: " << arraySumIterative(values) << ")\n";

        std::vector<int> recursivelyReversed = values;
        std::vector<int> iterativelyReversed = values;
        reverseArray(recursivelyReversed);
        reverseArrayIterative(iterativelyReversed);

        std::cout << "Reversed values (recursive): ";
        for (std::size_t index = 0; index < recursivelyReversed.size(); ++index) {
            if (index != 0) {
                std::cout << ", ";
            }
            std::cout << recursivelyReversed[index];
        }

        std::cout << "\nReversed values (iterative): ";
        for (std::size_t index = 0; index < iterativelyReversed.size(); ++index) {
            if (index != 0) {
                std::cout << ", ";
            }
            std::cout << iterativelyReversed[index];
        }
        std::cout << '\n';
    } catch (const std::exception& error) {
        std::cerr << "Unable to run the algorithm examples: " << error.what()
                  << '\n';
        return 1;
    }

    return 0;
}
