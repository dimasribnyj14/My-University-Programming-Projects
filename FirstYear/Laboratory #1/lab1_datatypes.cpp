#include <iostream>

int main() {
    const int x{ 742 }, z{ 110 };
    const float y{ -84.60 };

    const float result{ (((1.3 * z) - (y + y) * (3 * z) * z + (1.1 * z * 1.0) / 2) / (17 * y + 1.8 * z)) * 3 };

    std::cout << "Result: " << result;
}