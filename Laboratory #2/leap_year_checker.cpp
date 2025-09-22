// Підключаємо бібліотеки
#include <iostream>
// Головна програма
int main(){
    int yearInput;
    std::cout << "Введіть будь ласка рік.\n";
    std::cin >> yearInput;
    // Для більш людянішої умови, є перевірка якщо значення року більше нуля.
    if (yearInput > 0){
        if (yearInput % 400 == 0) {
            std::cout << "Рік є високосним." << std::endl;
        } else if (yearInput % 100 == 0) {
            std::cout << "Рік не є високосним." << std::endl;
        } else if (yearInput % 4 == 0) {
            std::cout << "Рік є високосним." << std::endl;
        } else {
            std::cout << "Рік не є високосним." << std::endl;
        }
    }else{
        std::cerr << "Виникла помилка! Рік введено некоректно." << std::endl;
    }

    return 0;
}
