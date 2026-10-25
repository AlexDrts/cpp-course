#include "GelPen.h"
#include <iostream>
using namespace std;

void GelPen::SetBrand(string brand) {
    this->brand = brand;
}

string GelPen::GetBrand() { return brand; }

void GelPen::SetInkColor(string ink_color) {
    this->ink_color = ink_color;
}

string GelPen::GetInkColor() { return ink_color; }

void GelPen::SetTipSize(double tip_size) {
    this->tip_size = tip_size;
}

double GelPen::GetTipSize() { return tip_size; }

void GelPen::SetIsRetractable(bool is_retractable) {
    this->is_retractable = is_retractable;
}

bool GelPen::GetIsRetractable() { return is_retractable; }

void GelPen::Info() {
    cout << "Gel Pen Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Ink Color: " << ink_color << "\n";
    cout << "Tip Size: " << tip_size << " mm\n";
    cout << "Retractable: " << (is_retractable ? "Yes" : "No") << "\n\n";
}