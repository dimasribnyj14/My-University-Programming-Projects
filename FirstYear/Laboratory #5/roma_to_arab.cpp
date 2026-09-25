#include <iostream>

// Функція для конвертації римських цифр у арабські
int romanToArabic(const std::string& roman) {
    int total = 0;
    int prevValue = 0;

    for (char ch : roman) {
        int value = 0;
        switch (ch) {
            case 'I': value = 1; break;
            case 'V': value = 5; break;
            case 'X': value = 10; break;
            case 'L': value = 50; break;
            case 'C': value = 100; break;
            case 'D': value = 500; break;
            case 'M': value = 1000; break;
            default:
                std::cerr << "Невірний символ: " << ch << std::endl;
                return -1; // Повертаємо -1 для позначення помилки
        }

        // Якщо поточне значення більше за попереднє, це означає віднімання
        if (value > prevValue) {
            total += value - 2 * prevValue; // Віднімаємо подвійне попереднє значення
        } else {
            total += value;
        }
        prevValue = value;
    }

    return total;
}

// Головна програма
int main() {
    std::string romanNumeral;
    std::cout << "Введіть римське число: ";
    std::cin >> romanNumeral;

    int arabicNumeral = romanToArabic(romanNumeral);
    if (arabicNumeral != -1) {
        std::cout << "Арабське число: " << arabicNumeral << std::endl;
    } else {
        std::cout << "Конвертація не вдалася через помилку у вхідних даних." << std::endl;
    }

    return 0;
}