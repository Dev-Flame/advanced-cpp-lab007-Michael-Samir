# Lab 7 — Recursive Algorithms Laboratory

## Course
CS 20 — Advanced Programming with C++

## Objective
This laboratory focuses on writing recursive solutions to common algorithmic problems. Students must understand when recursion is appropriate, how to define base cases and recursive cases, and how to compare recursive design with iterative approaches.

## Required Algorithms

Students must implement the following functions in C++:

1. `factorial(n)`
2. `fibonacci(n)`
3. `binarySearch(array, target)`
4. `arraySum(array)`
5. `reverseArray(array)`

For each recursive implementation:

- use recursion only; no loops inside the recursive implementation;
- clearly identify the base case and recursive case in comments;
- validate input where appropriate;
- choose suitable function parameters and return types;
- ensure the `binarySearch` implementation works on sorted arrays;
- ensure `reverseArray` modifies the array in place.

## Iterative Comparison

For each algorithm where an iterative solution is natural, also implement an iterative version and compare the two approaches in writing.

Students should discuss:

- time complexity;
- space complexity;
- recursive call depth and number of calls;
- readability and maintainability;
- advantages and disadvantages of recursion;
- stack overflow risk;
- Big-Oh for both recursive and iterative implementations.

## Unit Testing Requirement

The project includes unit tests that check:

- standard cases;
- boundary values;
- empty arrays where applicable;
- single-element arrays where applicable;
- zero and small values where applicable;
- values not found in binary search;
- already reversed and already sorted arrays;
- correctness of output and edge-case behavior.

The tests should be organized clearly so a failing case identifies the function and scenario.

## Required Deliverables

Students must submit:

- C++ source and header files;
- recursive implementations;
- iterative implementations where required;
- unit tests;
- a short comparison of recursive versus iterative approaches;
- Big-Oh time and space complexity for each implementation.

## Quality Expectations

- meaningful names;
- comments explaining the recursive structure;
- const-correctness where appropriate;
- no unnecessary global variables;
- no duplicated implementation logic;
- clean formatting and modular design;
- code that compiles with standard C++.

## Important Note
The starter project intentionally provides function stubs and tests. Students must complete the implementation logic themselves and verify each algorithm against the provided scenarios.
