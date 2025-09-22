#include <iostream>

int main() {
    int n; // Змінна з числом

    // Видає можливість користувачу написати число
    std::cout << "Введіть число n: ";
    std::cin >> n;

    // Виникає помилка, якщо число дорівнює менше одиниці
    if (n < 1) {
        std::cerr << "Виникла помилка! Введіть число, більше нуля." << std::endl;
        return 1;
    }

    long long current_lcm = 1; // Початкові найменших спільних кратних для чисел.

    // Обчислення найменшого спільного кратного для всіх чисел від 1 до значення, написаних користувачем.
    for (int i = 2; i <= n; ++i) {

        long long a = current_lcm;
        int b = i;

        long long temp_a = a;
        int temp_b = b;

        // Обчислення НСД за допомогою алгоритму Евкліда
        while (temp_b != 0) {
            long long temp = temp_b;
            temp_b = temp_a % temp_b;
            temp_a = temp;
        }
        long long gcd = temp_a;

        // Обчислення нового НСК
        current_lcm = (current_lcm / gcd) * i;
    }

    std::cout << "Сума найменших спільних кратних для чисел від 1 до " << n << " дорівнює: " << current_lcm << std::endl;

    return 0;
}