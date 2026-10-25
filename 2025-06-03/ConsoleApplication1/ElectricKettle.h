#include <string>
using namespace std;

class ElectricKettle {
private:
    string brand;
    double capacity;
    bool has_auto_off;
    string color;

public:
    void SetBrand(string b);
    string GetBrand();

    void SetCapacity(double c);
    double GetCapacity();

    void SetHasAutoOff(bool a);
    bool GetHasAutoOff();

    void SetColor(string c);
    string GetColor();

    void Info();
};

