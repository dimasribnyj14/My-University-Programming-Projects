// Підключаємо необхідні бібліотеки
#include <iostream>
// Головна програма
int main(){
    // Даємо можливість користувачу написати значення довжини сторін трикутника
    int triangleLengthA;
    std::cout << "Напишіть значення довжини сторони трикутника A.";
    std::cin >> triangleLengthA;
    // Якщо користувач написав довжину 1 см або більше, то
    if (triangleLengthA > 0){
        int triangleLengthB;
        std::cout << "Напишіть значення довжини сторони трикутника B.";
        std::cin >> triangleLengthB;

        if (triangleLengthB > 0){
            int triangleLengthC;
            std::cout << "Напишіть значення довжини сторони трикутника C.";
            std::cin >> triangleLengthC;
            
            if (triangleLengthC > 0){
                // Перевірка якщо трикутник є рівностороннім, рівнобедреним та різностороннім.
                if (triangleLengthA == triangleLengthB && triangleLengthB == triangleLengthC){
                    std::cout << "Довжина у сторін трикутника рівні, тому трикутник рівносторонній.\nРезультат довжин: A = " << triangleLengthA << "; B = " << triangleLengthB << "; C = " << triangleLengthC << '.' << std::endl;
                } else if (triangleLengthA == triangleLengthB && triangleLengthB != triangleLengthC || triangleLengthA != triangleLengthB && triangleLengthB == triangleLengthC || triangleLengthA != triangleLengthB && triangleLengthA == triangleLengthC)
                {
                    std::cout << "Довжина у лише двох сторін трикутника рівні, тому трикутник рівнобедрений.\nРезультат довжин: A = " << triangleLengthA << "; B = " << triangleLengthB << "; C = " << triangleLengthC << '.' << std::endl;
                } else {
                    std::cout << "Довжина у сторін трикутника різні, тому трикутник різносторонній.\nРезультат довжин: A = " << triangleLengthA << "; B = " << triangleLengthB << "; C = " << triangleLengthC << '.' << std::endl;
                }
                
            }else{
                std::cerr << "Виникла помилка! Будь ласка введіть число правильно." << std::endl;
            }

        }else{
            std::cerr << "Виникла помилка! Будь ласка введіть число правильно." << std::endl;
        }

    }// Але якщо користувач написав довжину менше 1, то виникає помилка.
    else{
        std::cerr << "Виникла помилка! Будь ласка введіть число правильно." << std::endl;
    }
    return 0;
}
