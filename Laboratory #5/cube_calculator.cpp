#include <iostream>

// Функція для обчислення куба числа
double cube(double x) {
    return x * x * x;
}

// Головна програма
int main(){
    double number;
    std::cout << "Введіть число: ";
    std::cin >> number;

    double result = cube(number);
    std::cout << "Куб числа " << number << " дорівнює " << result << std::endl;

    return 0;
}