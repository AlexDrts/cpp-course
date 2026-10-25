#include <iostream>
#include <string>
using namespace std;

class ElectricKettle {
public:
    string brand;
    double capacity;      // литры
	bool has_auto_off;    // автоматическое отключение
    string color;

    void Info() {
        cout << "Electric Kettle Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Capacity: " << capacity << " L\n";
        cout << "Auto Off: " << (has_auto_off ? "Yes" : "No") << "\n";
        cout << "Color: " << color << "\n\n";
    }
};

class Book {
public:
    string title;
    string author;
    int pages;
    string genre;

    void Info() {
        cout << "Book Info:\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Pages: " << pages << "\n";
        cout << "Genre: " << genre << "\n\n";
    }
};

class Phone {
public:
    string brand;
    string model;
    int storage;          // ГБ
    double screen_size;   // дюймы

    void Info() {
        cout << "Phone Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Model: " << model << "\n";
        cout << "Storage: " << storage << " GB\n";
        cout << "Screen Size: " << screen_size << " inch\n\n";
    }
};

class GelPen {
public:
    string brand;
    string ink_color;
    double tip_size;      // мм
    bool is_retractable;

    void Info() {
        cout << "Gel Pen Info:\n";
        cout << "Brand: " << brand << "\n";
        cout << "Ink Color: " << ink_color << "\n";
        cout << "Tip Size: " << tip_size << " mm\n";
        cout << "Retractable: " << (is_retractable ? "Yes" : "No") << "\n\n";
    }
};

class Banknote1000UAH {
public:
    string country = "Ukraine";
    int nomination = 1000;
    string currency = "UAH";
    int year_issued;

    void Info() {
        cout << "Banknote Info:\n";
        cout << "Country: " << country << "\n";
        cout << "Nomination: " << nomination << " " << currency << "\n";
        cout << "Year Issued: " << year_issued << "\n\n";
    }
};

int main() {
    ElectricKettle kettle;
    kettle.brand = "Tiphal";
    kettle.capacity = 1.7;
    kettle.has_auto_off = true;
    kettle.color = "White";

    Book book;
    book.title = "Harry Potter and the Philosopher's Stone";
    book.author = "J.K. Rowling";
    book.pages = 223;
    book.genre = "Fantasy";

    Phone phone;
    phone.brand = "Apple";
    phone.model = "iPhone 16";
    phone.storage = 256;
    phone.screen_size = 6.3;

    GelPen pen;
    pen.brand = "Pilot";
    pen.ink_color = "Blue";
    pen.tip_size = 0.5;
    pen.is_retractable = true;

    Banknote1000UAH note;
    note.year_issued = 2019;

    kettle.Info();
    book.Info();
    phone.Info();
    pen.Info();
    note.Info();
}
