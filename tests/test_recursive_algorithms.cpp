#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <vector>

TEST_CASE("factorial recursive and iterative: normal values") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(7) == 5040);
    REQUIRE(factorial(10) == 3628800);

    REQUIRE(factorialIterative(0) == 1);
    REQUIRE(factorialIterative(1) == 1);
    REQUIRE(factorialIterative(5) == 120);
    REQUIRE(factorialIterative(7) == 5040);
    REQUIRE(factorialIterative(10) == 3628800);
}

TEST_CASE("factorial recursive and iterative: invalid input") {
    REQUIRE_THROWS_AS(factorial(-1), std::logic_error);
    REQUIRE_THROWS_AS(factorialIterative(-1), std::logic_error);
}

TEST_CASE("factorial recursive and iterative: equivalence across representative inputs") {
    for (int n = 0; n <= 12; ++n) {
        REQUIRE(factorial(n) == factorialIterative(n));
    }
}

TEST_CASE("fibonacci recursive and iterative: base and normal cases") {
    REQUIRE(fibonacci(0) == 0);
    REQUIRE(fibonacci(1) == 1);
    REQUIRE(fibonacci(2) == 1);
    REQUIRE(fibonacci(7) == 13);
    REQUIRE(fibonacci(10) == 55);
    REQUIRE(fibonacci(20) == 6765);
    REQUIRE(fibonacci(25) == 75025);

    REQUIRE(fibonacciIterative(0) == 0);
    REQUIRE(fibonacciIterative(1) == 1);
    REQUIRE(fibonacciIterative(2) == 1);
    REQUIRE(fibonacciIterative(7) == 13);
    REQUIRE(fibonacciIterative(10) == 55);
    REQUIRE(fibonacciIterative(20) == 6765);
    REQUIRE(fibonacciIterative(25) == 75025);
}

TEST_CASE("fibonacci recursive and iterative: invalid input") {
    REQUIRE_THROWS_AS(fibonacci(-1), std::logic_error);
    REQUIRE_THROWS_AS(fibonacciIterative(-1), std::logic_error);
}

TEST_CASE("fibonacci recursive and iterative: equivalence across representative inputs") {
    for (int n = 0; n <= 25; ++n) {
        REQUIRE(fibonacci(n) == fibonacciIterative(n));
    }
}

TEST_CASE("binarySearch recursive and iterative: found values") {
    std::vector<int> values = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};

    REQUIRE(binarySearch(values, 1) == 0);
    REQUIRE(binarySearch(values, 7) == 3);
    REQUIRE(binarySearch(values, 15) == 7);
    REQUIRE(binarySearch(values, 25) == 12);
    REQUIRE(binarySearch(values, 19) == 9);

    REQUIRE(binarySearchIterative(values, 1) == 0);
    REQUIRE(binarySearchIterative(values, 7) == 3);
    REQUIRE(binarySearchIterative(values, 15) == 7);
    REQUIRE(binarySearchIterative(values, 25) == 12);
    REQUIRE(binarySearchIterative(values, 19) == 9);
}

TEST_CASE("binarySearch recursive and iterative: missing values and edge cases") {
    std::vector<int> values = {2, 4, 6, 8, 10, 12, 14, 16};

    REQUIRE(binarySearch(values, 1) == -1);
    REQUIRE(binarySearch(values, 7) == -1);
    REQUIRE(binarySearch(values, 10) == 4);
    REQUIRE(binarySearch(values, 16) == 7);
    REQUIRE(binarySearch({}, 5) == -1);
    REQUIRE(binarySearch({42}, 42) == 0);

    REQUIRE(binarySearchIterative(values, 1) == -1);
    REQUIRE(binarySearchIterative(values, 7) == -1);
    REQUIRE(binarySearchIterative(values, 10) == 4);
    REQUIRE(binarySearchIterative(values, 16) == 7);
    REQUIRE(binarySearchIterative({}, 5) == -1);
    REQUIRE(binarySearchIterative({42}, 42) == 0);
}

TEST_CASE("binarySearch recursive and iterative: equivalence on large sorted data") {
    std::vector<int> values;
    for (int i = 0; i <= 500; ++i) {
        values.push_back(i * 2);
    }

    for (int target = -2; target <= 1002; target += 2) {
        int expected = -1;
        for (std::size_t i = 0; i < values.size(); ++i) {
            if (values[i] == target) {
                expected = static_cast<int>(i);
                break;
            }
        }
        REQUIRE(binarySearch(values, target) == expected);
        REQUIRE(binarySearchIterative(values, target) == expected);
    }
}

TEST_CASE("arraySum recursive and iterative: normal and empty cases") {
    REQUIRE(arraySum({}) == 0);
    REQUIRE(arraySum({5}) == 5);
    REQUIRE(arraySum({1, 2, 3, 4, 5}) == 15);
    REQUIRE(arraySum({-3, 2, 9, -1}) == 7);
    REQUIRE(arraySum({-10, 20, -30, 40, -50, 60}) == 30);

    REQUIRE(arraySumIterative({}) == 0);
    REQUIRE(arraySumIterative({5}) == 5);
    REQUIRE(arraySumIterative({1, 2, 3, 4, 5}) == 15);
    REQUIRE(arraySumIterative({-3, 2, 9, -1}) == 7);
    REQUIRE(arraySumIterative({-10, 20, -30, 40, -50, 60}) == 30);
}

TEST_CASE("arraySum recursive and iterative: equivalence on larger inputs") {
    std::vector<int> values;
    for (int i = -100; i <= 100; ++i) {
        values.push_back(i);
    }

    REQUIRE(arraySum(values) == arraySumIterative(values));
}

TEST_CASE("reverseArray recursive and iterative: in-place reversal") {
    std::vector<int> original = {1, 2, 3, 4, 5};
    reverseArray(original);
    REQUIRE(original == std::vector<int>({5, 4, 3, 2, 1}));

    std::vector<int> alreadyReversed = {5, 4, 3, 2, 1};
    reverseArray(alreadyReversed);
    REQUIRE(alreadyReversed == std::vector<int>({1, 2, 3, 4, 5}));

    std::vector<int> empty;
    reverseArray(empty);
    REQUIRE(empty.empty());

    std::vector<int> single = {42};
    reverseArray(single);
    REQUIRE(single == std::vector<int>({42}));

    std::vector<int> iterativeValues = {10, 20, 30, 40};
    reverseArrayIterative(iterativeValues);
    REQUIRE(iterativeValues == std::vector<int>({40, 30, 20, 10}));
}

TEST_CASE("reverseArray recursive and iterative: equivalence on repeated larger inputs") {
    std::vector<int> values = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> iterativeCopy = values;

    reverseArray(values);
    reverseArrayIterative(iterativeCopy);

    REQUIRE(values == iterativeCopy);
    REQUIRE(values == std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
}
