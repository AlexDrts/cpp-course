#include "GelPen.h"
#include <iostream>
using namespace std;

void GelPen::SetBrand(string b) { brand = b; }
string GelPen::GetBrand() { return brand; }

void GelPen::SetInkColor(string c) { ink_color = c; }
string GelPen::GetInkColor() { return ink_color; }

void GelPen::SetTipSize(double s) { tip_size = s; }
double GelPen::GetTipSize() { return tip_size; }

void GelPen::SetIsRetractable(bool r) { is_retractable = r; }
bool GelPen::GetIsRetractable() { return is_retractable; }

void GelPen::Info() {
    cout << "Gel Pen Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Ink Color: " << ink_color << "\n";
    cout << "Tip Size: " << tip_size << " mm\n";
    cout << "Retractable: " << (is_retractable ? "Yes" : "No") << "\n\n";
}