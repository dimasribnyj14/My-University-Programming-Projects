#include <iostream>
#include <string>
#include <vector> // Для використання векторів замість динамічних масивів

// Клас для представлення витрат
class Expenses {
    private:
        int id;
        double amount;
        std::string description;
        std::string category;
        
    public:
        // Один конструктор замінює два завдяки значенням за замовчуванням (id, кількість, опис, категорія)
        Expenses(int id = 0, double amount = 0.0, std::string desc = "", std::string cat = "") 
            : id(id), amount(amount), description(desc), category(cat) {}

        void display() {
            std::cout << "ID: " << id << ", Сума: " << amount << ", Опис: " << description << ", Категорія: " << category << "\n";
        }
};

// Клас для представлення категорій витрат
class ExpensesCategory {
    private:
        std::string name;
        
    public:
        // Конструктор з параметром за замовчуванням для назви категорії
        ExpensesCategory(std::string name = "") : name(name) {}

        void display() {
            std::cout << "Категорія: " << name << "\n";
        }
};

int main() {
    int numCategories;
    std::cout << "Введіть кількість категорій витрат: ";
    std::cin >> numCategories;
    std::cin.ignore(); // Очищуємо буфер після введення числа

    // Використовуємо вектор для зберігання категорій замість динамічного масиву
    std::vector<ExpensesCategory> categories(numCategories);
    
    std::cout << "\nНазви категорій\n";
    // Зчитуємо назви категорій від користувача
    for (int i = 0; i < numCategories; i++) {
        std::string name;
        std::cout << i + 1 << ": ";
        std::getline(std::cin, name);
        categories[i] = ExpensesCategory(name);
    }

    std::cout << "\nСписок створених категорій:\n";
    // Виводимо список категорій
    for (int i = 0; i < numCategories; i++) {
        categories[i].display();
    }

    int numExpenses;
    std::cout << "\nВведіть кількість витрат: ";
    std::cin >> numExpenses;

    std::vector<Expenses> expenses(numExpenses); // Використовуємо вектор для зберігання витрат замість динамічного масиву
    
    // Зчитуємо інформацію про кожну витрату від користувача
    for (int i = 0; i < numExpenses; i++) {
        int id;
        double amount;
        std::string desc, cat;

        std::cout << "\nВитрата " << i + 1 << "\n";
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "Сума: ";
        std::cin >> amount;
        
        std::cin.ignore(); // Очищуємо буфер після введення чисел

        std::cout << "Опис: ";
        std::getline(std::cin, desc);
        std::cout << "Категорія: ";
        std::getline(std::cin, cat);
        // Створюємо об'єкт витрати і зберігаємо його у векторі
        expenses[i] = Expenses(id, amount, desc, cat);
    }

    std::cout << "\nВАШІ ВИТРАТИ\n";
    // Виводимо інформацію про кожну витрату
    for (int i = 0; i < numExpenses; i++) {
        expenses[i].display();
    }

    return 0;
}