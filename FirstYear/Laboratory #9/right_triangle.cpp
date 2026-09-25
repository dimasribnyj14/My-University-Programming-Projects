#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Клас для роботи з трикутником
class Triangle {
    private:
        double a, b, c; // Сторони трикутника
    public:
        Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}
        
        // Задання значення довжини сторін та кута між ними
        void setSidesAndAngle(double sideA, double sideB, double angleInDegrees) {
            a = sideA;
            b = sideB;
            
            // Конвертуємо кут з градусів у радіани
            double angleInRadians = angleInDegrees * 3.14 / 180.0;
            
            // Використовуємо закон косинусів для знаходження третьої сторони
            c = sqrt(a * a + b * b - 2 * a * b * cos(angleInRadians));
        };
        
        // Знаходження кутів трикутника
        vector<double> getAngles() {
            vector<double> angles;
            double angleA = acos((b * b + c * c - a * a) / (2 * b * c));
            double angleB = acos((a * a + c * c - b * b) / (2 * a * c));
            double angleC = acos((a * a + b * b - c * c) / (2 * a * b));

            angles.push_back(angleA * 180.0 / 3.14);
            angles.push_back(angleB * 180.0 / 3.14);
            angles.push_back(angleC * 180.0 / 3.14);
            
            return angles;
        };
        
        // Обчислення периметра трикутника
        double getPerimeter() {
            return a + b + c;
        };

        // Отримання довжин сторін трикутника
        vector<double> getSides() {
            return {a, b, c};
        };
};

// Клас для роботи з прямокутним трикутником, який наслідує від класу Triangle
class RightTriangle : public Triangle {
    public:
        // Конструктор: два катети, гіпотенузу обчислюємо за теоремою Піфагора
        // Потрібних методів не треба перевизначати – базові getSides та getPerimeter вже працюють, оскільки c було задано в конструкторі.
        RightTriangle(double sideA, double sideB) : Triangle(sideA, sideB, sqrt(sideA*sideA + sideB*sideB)) {}
};

int main(){
    // Створюємо трикутник зі сторонами 3, 4, 5
    Triangle t1(3, 4, 5);
    cout << "Звичайний трикутник Triangle1:" << endl;
    auto sides1 = t1.getSides();
    cout << "  Сторони: " << sides1[0] << ", " << sides1[1] << ", " << sides1[2] << endl;
    auto angles1 = t1.getAngles();
    cout << "  Кути: " << angles1[0] << "°, " << angles1[1] << "°, " << angles1[2] << "°" << endl;
    cout << "  Периметр: " << t1.getPerimeter() << endl;

    // Створюємо прямокутний трикутник з катетами 5 і 12
    RightTriangle rt(5, 12);
    cout << "\nПрямокутний трикутник RightTriangle:" << endl;
    auto sides2 = rt.getSides();
    cout << "  Сторони: " << sides2[0] << ", " << sides2[1] << ", " << sides2[2] << endl;
    auto angles2 = rt.getAngles();
    cout << "  Кути: " << angles2[0] << "°, " << angles2[1] << "°, " << angles2[2] << "°" << endl;
    cout << "  Периметр: " << rt.getPerimeter() << endl;

    return 0;
}