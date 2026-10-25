#include "Banknote1000UAH.h"
#include <iostream>
using namespace std;

Banknote1000UAH::Banknote1000UAH() {
    country = "Ukraine";
    nomination = 1000;
    currency = "UAH";
}

void Banknote1000UAH::SetYearIssued(int y) { year_issued = y; }
int Banknote1000UAH::GetYearIssued() { return year_issued; }

string Banknote1000UAH::GetCountry() { return country; }
int Banknote1000UAH::GetNomination() { return nomination; }
string Banknote1000UAH::GetCurrency() { return currency; }

void Banknote1000UAH::Info() {
    cout << "Banknote Info:\n";
    cout << "Country: " << country << "\n";
    cout << "Nomination: " << nomination << " " << currency << "\n";
    cout << "Year Issued: " << year_issued << "\n\n";
}