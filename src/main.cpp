#include <iostream>
#include "math_utils.h"

int main() {
    int sum = myproject::add(2, 3);
    int product = myproject::multiply(2, 3);

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
