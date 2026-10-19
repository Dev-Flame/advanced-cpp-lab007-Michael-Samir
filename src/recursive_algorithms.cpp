#include "project/recursive_algorithms.h"

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

namespace {

// Use half-open ranges [left, right) to handle empty arrays without underflow.
int binarySearchRange(const std::vector<int>& array, int target,
                      std::size_t left, std::size_t right) {
    // Base case: the remaining range is empty.
    if (left == right) {
        return -1;
    }

    const std::size_t middle = left + (right - left) / 2;
    if (array[middle] == target) {
        return static_cast<int>(middle);
    }

    // Recursive case: search only the half that can contain the target.
    if (target < array[middle]) {
        return binarySearchRange(array, target, left, middle);
    }
    return binarySearchRange(array, target, middle + 1, right);
}

int arraySumFrom(const std::vector<int>& array, std::size_t index) {
    // Base case: no elements remain.
    if (index == array.size()) {
        return 0;
    }
    // Recursive case: add this element to the sum of the remaining elements.
    return array[index] + arraySumFrom(array, index + 1);
}

void reverseRange(std::vector<int>& array, std::size_t left,
                  std::size_t right) {
    // Base case: zero or one elements remain.
    if (right - left <= 1) {
        return;
    }
    // Recursive case: swap the endpoints, then reverse the inner range.
    std::swap(array[left], array[right - 1]);
    reverseRange(array, left + 1, right - 1);
}

}  // namespace

// Both factorial versions take O(n) time. Recursion uses O(n) stack space
// and call depth; iteration uses O(1) extra space and avoids stack growth.
int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("factorial requires a non-negative input");
    }
    // 13! exceeds the 32-bit int return type; reject before recursing.
    if (n > 12) {
        throw std::overflow_error("factorial result exceeds the int range");
    }
    // Base case: 0! and 1! are both 1.
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n - 1)!.
    return n * factorial(n - 1);
}

int factorialIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("factorial requires a non-negative input");
    }
    if (n > 12) {
        throw std::overflow_error("factorial result exceeds the int range");
    }

    int result = 1;
    for (int factor = 2; factor <= n; ++factor) {
        result *= factor;
    }
    return result;
}

// Direct recursion mirrors the recurrence but repeats subproblems: O(2^n)
// time/calls and O(n) stack depth/space. Iteration takes O(n) time and O(1)
// extra space, making it preferable for larger inputs.
int fibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("fibonacci requires a non-negative input");
    }
    // Fibonacci(47) exceeds the 32-bit int return type.
    if (n > 46) {
        throw std::overflow_error("fibonacci result exceeds the int range");
    }
    // Base case: fib(0) = 0 and fib(1) = 1.
    if (n <= 1) {
        return n;
    }
    // Recursive case: add the two preceding Fibonacci numbers.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciIterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("fibonacci requires a non-negative input");
    }
    if (n > 46) {
        throw std::overflow_error("fibonacci result exceeds the int range");
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

// Input must be sorted in ascending order. Both versions take O(log n) time;
// recursion takes O(log n) calls/stack depth/space, iteration O(1) extra space.
int binarySearch(const std::vector<int>& array, int target) {
    return binarySearchRange(array, target, 0, array.size());
}

int binarySearchIterative(const std::vector<int>& array, int target) {
    std::size_t left = 0;
    std::size_t right = array.size();
    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        if (array[middle] == target) {
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

// Both sums take O(n) time without copying the array. Recursion uses O(n)
// calls/stack depth/space; iteration uses O(1) extra space. Sums must fit int.
int arraySum(const std::vector<int>& array) {
    return arraySumFrom(array, 0);
}

int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int value : array) {
        sum += value;
    }
    return sum;
}

// Both reversals modify the array in place in O(n) time. Recursion uses O(n)
// calls/stack depth/space, while iteration uses O(1) extra space.
// Recursive range helpers express the base/recursive cases clearly, but the
// iterative versions are simpler to maintain and avoid stack overflow on
// large arrays (especially for linear-depth summation and reversal).
void reverseArray(std::vector<int>& array) {
    reverseRange(array, 0, array.size());
}

void reverseArrayIterative(std::vector<int>& array) {
    std::size_t left = 0;
    std::size_t right = array.size();
    while (right - left > 1) {
        std::swap(array[left], array[right - 1]);
        ++left;
        --right;
    }
}
