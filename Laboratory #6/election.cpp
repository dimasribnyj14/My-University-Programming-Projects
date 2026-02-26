#include <iostream>
#include <string>

using namespace std;

// Описуємо структуру виборів
struct Election {
    string name; // Прізвище кандидата
    int votes;   // Кількість голосів
};

int main() {
    const int total_voters = 20; // Усього виборців
    const int num_candidates = 3; // Кількість кандидатів
    Election candidates[num_candidates];

    cout << "Введіть дані кандидатів (сума голосів має бути не більше 20):";
    
    // Заповнюємо масив кандидатів
    for (int i = 0; i < num_candidates; i++) {
        cout << "Прізвище кандидата: ";
        cin >> candidates[i].name;
        cout << "Кількість голосів: ";
        cin >> candidates[i].votes;
    }

    cout << "Результати виборів:";
    bool winner_found = false;
    double required_votes = total_voters / 3.0;

    // Перевіряємо кожного кандидата
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes >= required_votes) {
            cout << "Делегат " << candidates[i].name << " пройшов!";
            winner_found = true;
        }
    }

    // Якщо жоден не набрав
    if (winner_found == false) {
        cout << "Жоден кандидат не набрав потрібну кількість голосів. Потрібно проводити вибори ще раз!";
    }

    return 0;
}