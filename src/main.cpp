#include "project/recursive_algorithms.h"

#include <iostream>
#include <vector>

int main() {
    std::cout << "factorial(5): " << factorial(5) << '\n';
    std::cout << "fibonacci(10): " << fibonacci(10) << '\n';

    std::vector<int> values = {1, 3, 5, 7, 9};
    std::cout << "binarySearch(values, 7): " << binarySearch(values, 7) << '\n';
    std::cout << "arraySum(values): " << arraySum(values) << '\n';

    reverseArray(values);
    std::cout << "reverseArray(values):";
    for (int value : values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
    return 0;
}
