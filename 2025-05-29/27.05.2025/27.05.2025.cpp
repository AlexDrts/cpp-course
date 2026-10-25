#include <iostream>
#include <string>
using namespace std;

class ElectricKettle {
private:
    string brand;
    double capacity;
    bool has_auto_off;
    string color;

public:
    void SetBrand(string b) { brand = b; }
    string GetBrand() { return brand; }

    void SetCapacity(double c) { capacity = c; }
    double GetCapacity() { return capacity; }

    void SetHasAutoOff(bool a) { has_auto_off = a; }
    bool GetHasAutoOff() { return has_auto_off; }

    void SetColor(string c) { color = c; }
    string GetColor() { return color; }

    void Info() {
        cout << "Electric Kettle Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Capacity: " << capacity << " L\n";
        cout << "Auto Off: " << (has_auto_off ? "Yes" : "No") << "\n";
        cout << "Color: " << color << "\n\n";
    }
};

class Book {
private:
    string title;
    string author;
    int pages;
    string genre;

public:
    void SetTitle(string t) { title = t; }
    string GetTitle() { return title; }

    void SetAuthor(string a) { author = a; }
    string GetAuthor() { return author; }

    void SetPages(int p) { pages = p; }
    int GetPages() { return pages; }

    void SetGenre(string g) { genre = g; }
    string GetGenre() { return genre; }

    void Info() {
        cout << "Book Info:\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Pages: " << pages << "\n";
        cout << "Genre: " << genre << "\n\n";
    }
};

class Phone {
private:
    string brand;
    string model;
    int storage;
    double screen_size;

public:
    void SetBrand(string b) { brand = b; }
    string GetBrand() { return brand; }

    void SetModel(string m) { model = m; }
    string GetModel() { return model; }

    void SetStorage(int s) { storage = s; }
    int GetStorage() { return storage; }

    void SetScreenSize(double s) { screen_size = s; }
    double GetScreenSize() { return screen_size; }

    void Info() {
        cout << "Phone Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
        cout << "Storage: " << storage << " GB\n";
        cout << "Screen Size: " << screen_size << " inch\n\n";
    }
};

class GelPen {
private:
    string brand;
    string ink_color;
    double tip_size;
    bool is_retractable;

public:
    void SetBrand(string b) { brand = b; }
    string GetBrand() { return brand; }

    void SetInkColor(string c) { ink_color = c; }
    string GetInkColor() { return ink_color; }

    void SetTipSize(double s) { tip_size = s; }
    double GetTipSize() { return tip_size; }

    void SetIsRetractable(bool r) { is_retractable = r; }
    bool GetIsRetractable() { return is_retractable; }

    void Info() {
        cout << "Gel Pen Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Ink Color: " << ink_color << "\n";
        cout << "Tip Size: " << tip_size << " mm\n";
        cout << "Retractable: " << (is_retractable ? "Yes" : "No") << "\n\n";
    }
};

class Banknote1000UAH {
private:
    string country = "Ukraine";
    int nomination = 1000;
    string currency = "UAH";
    int year_issued;

public:
    void SetYearIssued(int y) { year_issued = y; }
    int GetYearIssued() { return year_issued; }

    string GetCountry() { return country; }
    int GetNomination() { return nomination; }
    string GetCurrency() { return currency; }

    void Info() {
        cout << "Banknote Info:\n";
        cout << "Country: " << country << "\n";
        cout << "Nomination: " << nomination << " " << currency << "\n";
        cout << "Year Issued: " << year_issued << "\n\n";
    }
};

int main() {
    ElectricKettle kettle;
    kettle.SetBrand("Tiphal");
    kettle.SetCapacity(1.7);
    kettle.SetHasAutoOff(true);
    kettle.SetColor("White");

    Book book;
    book.SetTitle("Harry Potter and the Philosopher's Stone");
    book.SetAuthor("J.K. Rowling");
    book.SetPages(223);
    book.SetGenre("Fantasy");

    Phone phone;
    phone.SetBrand("Apple");
    phone.SetModel("iPhone 16");
    phone.SetStorage(256);
    phone.SetScreenSize(6.3);

    GelPen pen;
    pen.SetBrand("Pilot");
    pen.SetInkColor("Blue");
    pen.SetTipSize(0.5);
    pen.SetIsRetractable(true);

    Banknote1000UAH note;
    note.SetYearIssued(2019);

    kettle.Info();
    book.Info();
    phone.Info();
    pen.Info();
    note.Info();
}

