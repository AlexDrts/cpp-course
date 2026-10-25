#include <iostream>
using namespace std;


class Visa {
private:
    string country;
    string type;
    string expiration;
public:
    Visa() {
        country = "Romania";
        type = "Tourist";
        expiration = "22.11.2025";
        cout << "C-TOR WITHOUT PARAMS A\n";
    }

    Visa(string country, string type, string expiration) {
        this->country = country;
        this->type = type;
        this->expiration = expiration;
        cout << "C-TOR WITH PARAMS A\n";
    }

    void Print() const {
        cout << "Visa to: " << country << ", Type: " << type << ", Expiration: " << expiration << endl;
    }
};


class Passport {
protected:
    string name;
    string surname;
    string birthday;
    string passportNumber;
public:
    Passport() {
        name = "Olga";
        surname = "Petrovna";
        birthday = "07-05-1995";
        passportNumber = "AA123456";
        cout << "C-TOR WITHOUT PARAMS B\n";
    }

    Passport(string name, string surname, string birthday, string passportNumber) {
        this->name = name;
        this->surname = surname;
        this->birthday = birthday;
        this->passportNumber = passportNumber;
        cout << "C-TOR WITH PARAMS B\n";
    }

    void Print() const {
        cout << "Name: " << name << "\n";
        cout << "Surname: " << surname << "\n";
        cout << "Date of Birth: " << birthday << "\n";
        cout << "Passport Number: " << passportNumber << "\n";
    }
};


class Foreign_Passport : public Passport {
protected:
    Visa visa;
public:
    Foreign_Passport() : Passport() {
        cout << "C-TOR WITHOUT PARAMS C\n";
    }

    Foreign_Passport(string name, string surname, string birthday, string number) : Passport(name, surname, birthday, number) {
        cout << "C-TOR WITH PARAMS C\n";
    }

    void Print() const {
        Passport::Print();
        cout << "Foreign Passport Info:\n";
        visa.Print();
    }
};


int main() {
    Passport p1("Dima", "Petrovich", "15-06-1990", "AB987654");
    p1.Print();
    cout << "----------------------\n";


    Foreign_Passport f1("Inna", "Ivanovna", "20-02-1985", "AC123321");
    f1.Print();
}
