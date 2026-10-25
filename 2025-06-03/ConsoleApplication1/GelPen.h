#include <string>
using namespace std;

class GelPen {
private:
    string brand;
    string ink_color;
    double tip_size;
    bool is_retractable;

public:
    void SetBrand(string b);
    string GetBrand();

    void SetInkColor(string c);
    string GetInkColor();

    void SetTipSize(double s);
    double GetTipSize();

    void SetIsRetractable(bool r);
    bool GetIsRetractable();

    void Info();
};