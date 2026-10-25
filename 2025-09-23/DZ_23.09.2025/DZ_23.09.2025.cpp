#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void main() {
    setlocale(0, "");
    srand(time(0));

    // запис у файл
    ofstream outFile("DZ.txt");
    if (!outFile) {
        cout << "ERROR!\n";
        return;
    }

    // записуємо 10 міст
    outFile << "Київ\n";
    outFile << "Львiв\n";
    outFile << "Одеса\n";
    outFile << "Харкiв\n";
    outFile << "Днiпро\n";
    outFile << "Запорiжжя\n";
    outFile << "Вiнниця\n";
    outFile << "Полтава\n";
    outFile << "Чернiвцi\n";
    outFile << "Ужгород\n";

    outFile.close();

    // читання з файлу
    ifstream inFile("DZ.txt");
    if (!inFile) {
        cout << "ERROR!\n";
        return;
    }

    // випадкове число від 1 до 10
    int RandomLine = rand() % 10 + 1;

    // читаємо файл поки не дійдемо до випадкової строки
    string line;
    int num = 1;
    while (getline(inFile, line)) {
        if (num == RandomLine) {
            cout << "Випадкове мiсто: " << line << "\n";
            break;
        }
        num++;
    }

    inFile.close();
}