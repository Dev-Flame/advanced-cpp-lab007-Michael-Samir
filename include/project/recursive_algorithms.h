#pragma once

#include <vector>

// Students must implement each of the following recursively.
// Do not use loops inside the recursive implementations.
// For each function, identify the base case and recursive case in comments.

int factorial(int n);
int factorialIterative(int n);

int fibonacci(int n);
int fibonacciIterative(int n);

int binarySearch(const std::vector<int>& array, int target);
int binarySearchIterative(const std::vector<int>& array, int target);

int arraySum(const std::vector<int>& array);
int arraySumIterative(const std::vector<int>& array);

void reverseArray(std::vector<int>& array);
void reverseArrayIterative(std::vector<int>& array);
