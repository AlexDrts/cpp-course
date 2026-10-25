#include "Phone.h"
#include <iostream>
using namespace std;

void Phone::SetBrand(string brand) {
    this->brand = brand;
}
string Phone::GetBrand() { return brand; }

void Phone::SetModel(string model) {
    this->model = model;
}

string Phone::GetModel() { return model; }

void Phone::SetStorage(int storage) {
    this->storage = storage;
}

int Phone::GetStorage() { return storage; }

void Phone::SetScreenSize(double screen_size) {
    this->screen_size = screen_size;
}

double Phone::GetScreenSize() { return screen_size; }

void Phone::Info() {
    cout << "Phone Info:\n";
    cout << "Brand: " << brand << "\n";
    cout << "Model: " << model << "\n";
    cout << "Storage: " << storage << " GB\n";
    cout << "Screen Size: " << screen_size << " inch\n\n";
}