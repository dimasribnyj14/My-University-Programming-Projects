#include <iostream>

int main() {
    int n;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> n;

    // Динамічне виділення пам'яті для початкового масиву
    int* arr = new int[n];
    
    std::cout << "Введіть " << n << " цілих чисел:\n";
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Динамічне виділення пам'яті для результуючого масиву 
    int* result = new int[n];
    int resultSize = 0;

    // Проходимо по кожному елементу початкового масиву
    for(int i = 0; i < n; i++) {
        bool isDuplicate = false;
        
        // Перевіряємо, чи є вже цей елемент у масиві result
        for(int dups = 0; dups < resultSize; dups++) {
            if(arr[i] == result[dups]) {
                isDuplicate = true;
                break; // Якщо знайшли дублікат, зупиняємо
            }
        }
        
        // Якщо елемент унікальний, додаємо його до результату
        if(!isDuplicate) {
            result[resultSize] = arr[i];
            resultSize++;
        }
    }

    std::cout << "Масив без дублікатів: ";
    for(int i = 0; i < resultSize; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

    // Звільнення пам'яті для масивів
    delete[] arr;
    delete[] result;

    return 0;
}