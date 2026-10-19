#include "project/recursive_algorithms.h"

#include <cstdint>
#include <limits>
#include <stdexcept>
#include <utility>
#include <vector>

namespace {

int fibonacciRecursive(int n, std::vector<int>& cache) {
    if (n <= 1) {
        return n;
    }
    if (cache[static_cast<std::size_t>(n)] != -1) {
        return cache[static_cast<std::size_t>(n)];
    }

    cache[static_cast<std::size_t>(n)] =
        fibonacciRecursive(n - 1, cache) + fibonacciRecursive(n - 2, cache);
    return cache[static_cast<std::size_t>(n)];
}

std::size_t binarySearchRecursive(const std::vector<int>& array, int target,
                                  std::size_t left, std::size_t right) {
    if (left >= right) {
        return array.size();
    }

    const std::size_t middle = left + (right - left) / 2;
    if (array[middle] == target) {
        return middle;
    }
    if (target < array[middle]) {
        return binarySearchRecursive(array, target, left, middle);
    }
    return binarySearchRecursive(array, target, middle + 1, right);
}

std::int64_t checkedSum(std::int64_t left, std::int64_t right) {
    if ((right > 0 &&
         left > std::numeric_limits<std::int64_t>::max() - right) ||
        (right < 0 &&
         left < std::numeric_limits<std::int64_t>::min() - right)) {
        throw std::overflow_error("array sum exceeds the range of int");
    }
    return left + right;
}

std::int64_t arraySumRecursive(const std::vector<int>& array,
                               std::size_t index) {
    if (index == array.size()) {
        return 0;
    }
    return checkedSum(array[index], arraySumRecursive(array, index + 1));
}

int checkedIntResult(std::int64_t sum) {
    if (sum < std::numeric_limits<int>::min() ||
        sum > std::numeric_limits<int>::max()) {
        throw std::overflow_error("array sum exceeds the range of int");
    }
    return static_cast<int>(sum);
}

void reverseArrayRecursive(std::vector<int>& array, std::size_t left,
                           std::size_t right) {
    if (left >= right) {
        return;
    }
    std::swap(array[left], array[right]);
    reverseArrayRecursive(array, left + 1, right - 1);
}

}  // namespace

// Base case: 0! and 1! are both 1. Recursive case: n! = n * (n - 1)!.
int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("factorial is undefined for negative values");
    }
    if (n > 12) {
        throw std::overflow_error("factorial result exceeds the range of int");
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Iteratively multiply each positive integer through n.
int factorialIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("factorial is undefined for negative values");
    }
    if (n > 12) {
        throw std::overflow_error("factorial result exceeds the range of int");
    }

    int result = 1;
    for (int factor = 2; factor <= n; ++factor) {
        result *= factor;
    }
    return result;
}

// Base cases: fib(0) = 0 and fib(1) = 1. Recursive case: sum the two
// preceding values; caching keeps the repeated recursive subproblems linear.
int fibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("fibonacci is undefined for negative values");
    }
    if (n > 46) {
        throw std::overflow_error("fibonacci result exceeds the range of int");
    }

    std::vector<int> cache(static_cast<std::size_t>(n) + 1, -1);
    return fibonacciRecursive(n, cache);
}

// Keep the previous two terms and advance through the sequence once.
int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("fibonacci is undefined for negative values");
    }
    if (n > 46) {
        throw std::overflow_error("fibonacci result exceeds the range of int");
    }
    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current = 1;
    for (int index = 2; index <= n; ++index) {
        const int next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

// Base case: the half-open search range is empty. Recursive case: discard
// the half that cannot contain the target.
int binarySearch(const std::vector<int>& array, int target) {
    const std::size_t index =
        binarySearchRecursive(array, target, 0, array.size());
    if (index == array.size()) {
        return -1;
    }
    if (index > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
        throw std::overflow_error("binary search index exceeds the range of int");
    }
    return static_cast<int>(index);
}

// Iteratively narrow the half-open search range until it is empty or matches.
int binarySearchIterative(const std::vector<int>& array, int target) {
    std::size_t left = 0;
    std::size_t right = array.size();
    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        if (array[middle] == target) {
            if (middle >
                static_cast<std::size_t>(std::numeric_limits<int>::max())) {
                throw std::overflow_error(
                    "binary search index exceeds the range of int");
            }
            return static_cast<int>(middle);
        }
        if (target < array[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}

// Base case: the index reaches the end. Recursive case: add this element to
// the recursively computed sum of the remaining elements.
int arraySum(const std::vector<int>& array) {
    return checkedIntResult(arraySumRecursive(array, 0));
}

// Add each element once, reporting a result that cannot fit in int.
int arraySumIterative(const std::vector<int>& array) {
    std::int64_t sum = 0;
    for (int value : array) {
        sum = checkedSum(sum, value);
    }
    return checkedIntResult(sum);
}

// Base case: the two endpoints have met or crossed. Recursive case: swap the
// endpoints and reverse the remaining middle range.
void reverseArray(std::vector<int>& array) {
    if (!array.empty()) {
        reverseArrayRecursive(array, 0, array.size() - 1);
    }
}

// Swap elements from the two ends inward.
void reverseArrayIterative(std::vector<int>& array) {
    std::size_t left = 0;
    std::size_t right = array.size();
    while (left < right) {
        --right;
        if (left >= right) {
            break;
        }
        std::swap(array[left], array[right]);
        ++left;
    }
}
