#include <iostream>
#include <string>

using namespace std;

// Описуємо структуру товару
struct PRICE {
    string TOVAR; // Назва товару
    string MAG;   // Назва магазину
    double cost;  // Вартість
};

int main() {
    const int SIZE = 8;
    PRICE LIST[SIZE];

    cout << "Введіть дані про 8 товарів (використовуйте одне слово для назв):\n";
    
    // Заповнюємо масив структур
    for (int i = 0; i < SIZE; i++) {
        cout << "Товар " << i + 1 << ":\n";
        cout << "Назва товару: ";
        cin >> LIST[i].TOVAR;
        cout << "Назва магазину: ";
        cin >> LIST[i].MAG;
        cout << "Вартість: ";
        cin >> LIST[i].cost;
    }

    string search_item;
    cout << "\nВведіть назву товару для пошуку: ";
    cin >> search_item;

    bool found = false;
    
    // Шукаємо товар у масиві
    for (int i = 0; i < SIZE; i++) {
        if (LIST[i].TOVAR == search_item) {
            cout << "Магазин: " << LIST[i].MAG << " ● Вартість: " << LIST[i].cost << "\n";
            found = true;
        }
    }

    // Якщо товар не знайдено
    if (found == false) {
        cout << "Виникла помилка! Такого товару немає.\n";
    }

    return 0;
}