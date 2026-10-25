#include <string>
using namespace std;

class Phone {
private:
    string brand;
    string model;
    int storage;
    double screen_size;

public:
    void SetBrand(string brand);
    string GetBrand();

    void SetModel(string model);
    string GetModel();

    void SetStorage(int storage);
    int GetStorage();

    void SetScreenSize(double screen_size);
    double GetScreenSize();

    void Info();
};