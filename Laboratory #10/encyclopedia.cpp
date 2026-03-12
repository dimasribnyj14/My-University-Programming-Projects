#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Додатковий клас для зберігання інформації про особистостей
class Person {
    private:
        string name;
        string occupation;
        string description;

    public:
        // Конструктор без параметрів
        Person() : name("Невідомо"), occupation("Невідомо"), description("Немає опису") {
            cout << "Викликано конструктор без параметрів класу Person" << endl;
        }

        // Конструктор із параметрами
        Person(string n, string o, string d) : name(n), occupation(o), description(d) {
            cout << "Викликано конструктор із параметрами класу Person (" << name << ")" << endl;
        }

        // Деструктор
        ~Person() {
            cout << "Викликано деструктор класу Person (" << name << ")" << endl;
        }

        void displayInfo() const {
            cout << "Name: " << name << "; Occupation: " << occupation << "; Description: " << description << endl;
        }
};

// Основний клас для енциклопедії
class Encyclopedia {
    private:
        string title;
        int year;
        // Контейнер для зберігання об'єктів додаткового класу
        vector<Person> peopleContainer; 

    public:
        // Конструктор без параметрів
        Encyclopedia() : title("Без назви"), year(0) {
            cout << "Викликано конструктор без параметрів класу Encyclopedia" << endl;
        }

        // Конструктор із параметрами
        Encyclopedia(string t, int y) : title(t), year(y) {
            cout << "Викликано конструктор із параметрами класу Encyclopedia (" << title << ")" << endl;
        }

        // Деструктор
        ~Encyclopedia() {
            cout << "Викликано деструктор класу Encyclopedia (" << title << ")" << endl;
        }

        // Метод створення та додавання об'єкта додаткового класу
        void addPersonToContainer(string n, string o, string d) {
            // Створюється об'єкт за допомогою конструктора з параметрами
            Person newPerson(n, o, d); 

            // Додається до контейнеру
            peopleContainer.push_back(newPerson); 
        }

        void displayInfo() const {
            cout << "\nЕнциклопедія: " << title << " (" << year << ")" << endl;
            cout << "Список особистостей:" << endl;
            for (const auto& person : peopleContainer) {
                person.displayInfo();
            }
            cout << endl;
        }
};

// Головна програма
int main() {
    // Демонстрація конструктора без параметрів
    Encyclopedia emptyEncyc; 

    // Демонстрація конструктора з параметрами
    Encyclopedia historyEncyc("Видатні діячі", 2024);

    // Демонстрація додавання об'єктів
    historyEncyc.addPersonToContainer("Тарас Шевченко", "Поет та художник", "Видатний український митець");
    historyEncyc.addPersonToContainer("Леся Українка", "Письменниця", "Видатна українська поетеса");

    historyEncyc.displayInfo();

    return 0;
}