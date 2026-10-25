#include <string>
using namespace std;

class Banknote1000UAH {
private:
    string country;
    int nomination;
    string currency;
    int year_issued;

public:
    Banknote1000UAH();

    void SetYearIssued(int y);
    int GetYearIssued();

    string GetCountry();
    int GetNomination();
    string GetCurrency();

    void Info();
};