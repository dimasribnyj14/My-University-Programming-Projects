#include <iostream>
// Для генерації випадкових чисел
class PasswordGenerator {
    // Зберігаємо згенерований пароль у приватній змінній
    private:
        std::string password;
    // Метод для генерації пароля на основі заданих параметрів
    public:
        void generatePassword(int length, bool includeDigits, bool includeSymbols, bool includeUppercase, bool includeLowercase) {
            std::string characters;
            if (includeDigits) {
                characters += "0123456789"; //Цифри
            }
            if (includeSymbols) {
                characters += "!@#$%^&*()_+-=[]{}|;:,.<>?"; //Символи
            }
            if (includeUppercase) {
                characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Великі літери
            }
            if (includeLowercase) {
                characters += "abcdefghijklmnopqrstuvwxyz"; //Малі літери
            }

            for (int i = 0; i < length; i++) {
                password += characters[rand() % characters.size()]; //Випадковий вибір символу з набору
            }
        }
        // Отримуємо згенерований пароль
        std::string getPassword() {
            return password;
        }
};

int main() {
    int length;
    bool includeDigits, includeSymbols, includeUppercase, includeLowercase;
    // Запитуємо користувача про параметри пароля
    std::cout << "Напишіть довжину пароля: ";
    std::cin >> length;
    std::cout << "Чи включати цифри? (1 для так, 0 для ні): ";
    std::cin >> includeDigits;
    std::cout << "Чи включати символи? (1 для так, 0 для ні): ";
    std::cin >> includeSymbols;
    std::cout << "Чи включати великі літери? (1 для так, 0 для ні): ";
    std::cin >> includeUppercase;
    std::cout << "Чи включати малі літери? (1 для так, 0 для ні): ";
    std::cin >> includeLowercase;

    PasswordGenerator generator;
    // Генеруємо пароль на основі введених параметрів
    generator.generatePassword(length, includeDigits, includeSymbols, includeUppercase, includeLowercase);
    
    std::cout << "Згенерований пароль: " << generator.getPassword() << "\n";

    return 0;
}
