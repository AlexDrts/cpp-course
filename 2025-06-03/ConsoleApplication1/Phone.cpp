#include "Phone.h"
#include <iostream>
using namespace std;

void Phone::SetBrand(string b) { brand = b; }
string Phone::GetBrand() { return brand; }

void Phone::SetModel(string m) { model = m; }
string Phone::GetModel() { return model; }

void Phone::SetStorage(int s) { storage = s; }
int Phone::GetStorage() { return storage; }

void Phone::SetScreenSize(double s) { screen_size = s; }
double Phone::GetScreenSize() { return screen_size; }

void Phone::Info() {
    cout << "Phone Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Model: " << model << "\n";
    cout << "Storage: " << storage << " GB\n";
    cout << "Screen Size: " << screen_size << " inch\n\n";
}