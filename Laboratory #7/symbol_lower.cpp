#include <iostream>
#include <cstring>
#include <cctype> // Для функції tolower

int main() {
    int maxSize = 256; // Максимальна довжина рядка
    
    // Динамічне виділення пам'яті для рядка символів 
    char* str = new char[maxSize];

    std::cout << "Введіть рядок (English): ";
    // Зчитуємо рядок з пробілами
    std::cin.getline(str, maxSize);

    // Проходимо по кожному символу рядка і переводимо у нижній регістр
    for(int i = 0; i < std::strlen(str); i++) {
        str[i] = std::tolower(str[i]);
    }

    std::cout << "Рядок у нижньому регістрі: " << str << "\n";

    // Звільнення динамічної пам'яті
    delete[] str;

    return 0;
}