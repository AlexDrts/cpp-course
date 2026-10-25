#include "ElectricKettle.h"
#include <iostream>
using namespace std;

void ElectricKettle::SetBrand(string b) { brand = b; }
string ElectricKettle::GetBrand() { return brand; }

void ElectricKettle::SetCapacity(double c) { capacity = c; }
double ElectricKettle::GetCapacity() { return capacity; }

void ElectricKettle::SetHasAutoOff(bool a) { has_auto_off = a; }
bool ElectricKettle::GetHasAutoOff() { return has_auto_off; }

void ElectricKettle::SetColor(string c) { color = c; }
string ElectricKettle::GetColor() { return color; }

void ElectricKettle::Info() {
    cout << "Electric Kettle Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Capacity: " << capacity << " L\n";
    cout << "Auto Off: " << (has_auto_off ? "Yes" : "No") << "\n";
    cout << "Color: " << color << "\n\n";
}
