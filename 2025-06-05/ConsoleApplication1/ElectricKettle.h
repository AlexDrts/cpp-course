#include <string>
using namespace std;

class ElectricKettle {
private:
    string brand;
    double capacity;
    bool has_auto_off;
    string color;

public:
    void SetBrand(string brand);
    string GetBrand();

    void SetCapacity(double capacity);
    double GetCapacity();

    void SetHasAutoOff(bool has_auto_off);
    bool GetHasAutoOff();

    void SetColor(string color);
    string GetColor();

    void Info();
};

