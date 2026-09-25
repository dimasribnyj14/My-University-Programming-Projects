#include <iostream>

// Функція для виведення масиву
void logArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        // Доступ до елемента масиву за індексом
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Головна програма
int main() {
    // Оголошуємо одновимірний масив цілих чисел
    const int SIZE = 12;
    int myArray[SIZE] = {8, -3, 6, 0, -7, 11, 4, 0, -9, 5, 2, -1};

    std::cout << "Початковий масив: " << std::endl;
    logArray(myArray, SIZE);

    long long productOfEvens = 1; // Уникнення переповнення

    // Проходимо по всіх елементах масиву
    for (int i = 0; i < SIZE; ++i) {
        // Якщо індекс парний,
        if (i % 2 == 0) {
            // То множимо наш результат на елемент масиву
            productOfEvens *= myArray[i];
        }
    }
    std::cout << "Множення елементів з парними номерами: " << productOfEvens << std::endl;

    int firstZeroIndex = -1; // Якщо -1, то 0 ще не знайдено
    int lastZeroIndex = -1;

    // Шукаємо індекс першого нульового елемента
    for (int i = 0; i < SIZE; ++i) {
        if (myArray[i] == 0) {
            firstZeroIndex = i;
            break; // Зупиняємо
        }
    }

    // Шукаємо індекс останнього нульового елемента
    for (int i = SIZE - 1; i >= 0; --i) {
        if (myArray[i] == 0) {
            lastZeroIndex = i;
            break; // Зупиняємо
        }
    }

    int sumBetweenZeros = 0;
    // Перевіряємо, чи були знайдені 0 й чи є елементи
    if (firstZeroIndex != -1 && lastZeroIndex != -1 && lastZeroIndex > firstZeroIndex) {
        // Сумуємо елементи, що знаходяться між індексами першим нульовим індексом та останнім нульовим індексом
        for (int i = firstZeroIndex + 1; i < lastZeroIndex; ++i) {
            sumBetweenZeros += myArray[i];
        }
        std::cout << "Сума елементів між першим і останнім нулем: " << sumBetweenZeros << std::endl;
    } else {
        std::cout << "В масиві немає двох нулів або між ними немає елементів." << std::endl;
    }


    // Масив для збереження результату
    int transformedArray[SIZE];
    int currentIndex = 0;

    // Крок 1: Копіюємо всі позитивні елементи та нулі
    for (int i = 0; i < SIZE; ++i) {
        // Згідно з умовою, 0 вважаємо позитивним
        if (myArray[i] >= 0) {
            transformedArray[currentIndex] = myArray[i];
            currentIndex++; // Збільшуємо індекс для наступного елемента
        }
    }

    // Копіюємо всі негативні елементи в кінець нового масиву
    for (int i = 0; i < SIZE; ++i) {
        if (myArray[i] < 0) {
            transformedArray[currentIndex] = myArray[i];
            currentIndex++;
        }
    }

    std::cout << "Перетворений масив: " << std::endl;
    logArray(transformedArray, SIZE);

    return 0;
}