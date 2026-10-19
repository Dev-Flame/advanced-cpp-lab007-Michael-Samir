#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    (void)n;
    throw std::logic_error("Student implementation required: factorial");
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    (void)n;
    throw std::logic_error("Student implementation required: factorialIterative");
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    (void)n;
    throw std::logic_error("Student implementation required: fibonacci");
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    (void)n;
    throw std::logic_error("Student implementation required: fibonacciIterative");
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    (void)array;
    (void)target;
    throw std::logic_error("Student implementation required: binarySearch");
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    (void)array;
    (void)target;
    throw std::logic_error("Student implementation required: binarySearchIterative");
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    (void)array;
    throw std::logic_error("Student implementation required: arraySum");
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    (void)array;
    throw std::logic_error("Student implementation required: arraySumIterative");
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    (void)array;
    throw std::logic_error("Student implementation required: reverseArray");
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    (void)array;
    throw std::logic_error("Student implementation required: reverseArrayIterative");
}
