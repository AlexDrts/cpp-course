#include <string>
using namespace std;

class Phone {
private:
    string brand;
    string model;
    int storage;
    double screen_size;

public:
    void SetBrand(string b);
    string GetBrand();

    void SetModel(string m);
    string GetModel();

    void SetStorage(int s);
    int GetStorage();

    void SetScreenSize(double s);
    double GetScreenSize();

    void Info();
};