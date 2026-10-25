#include <string>
using namespace std;

class GelPen {
private:
    string brand;
    string ink_color;
    double tip_size;
    bool is_retractable;

public:
    void SetBrand(string brand);
    string GetBrand();

    void SetInkColor(string ink_color);
    string GetInkColor();

    void SetTipSize(double tip_size);
    double GetTipSize();

    void SetIsRetractable(bool is_retractable);
    bool GetIsRetractable();

    void Info();
};