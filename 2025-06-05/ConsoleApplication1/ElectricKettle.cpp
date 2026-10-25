#include "ElectricKettle.h"
#include <iostream>
using namespace std;

void ElectricKettle::SetBrand(string brand) {
    this->brand = brand;
}

string ElectricKettle::GetBrand() { return brand; }

void ElectricKettle::SetCapacity(double capacity) {
    this->capacity = capacity;
}

double ElectricKettle::GetCapacity() { return capacity; }

void ElectricKettle::SetHasAutoOff(bool has_auto_off) {
    this->has_auto_off = has_auto_off;
}

bool ElectricKettle::GetHasAutoOff() { return has_auto_off; }

void ElectricKettle::SetColor(string color) {
    this->color = color;
}

string ElectricKettle::GetColor() { return color; }

void ElectricKettle::Info() {
    cout << "Electric Kettle Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Capacity: " << capacity << " L\n";
    cout << "Auto Off: " << (has_auto_off ? "Yes" : "No") << "\n";
    cout << "Color: " << color << "\n\n";
}
