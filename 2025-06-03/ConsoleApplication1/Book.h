#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;
    string genre;

public:
    void SetTitle(string t);
    string GetTitle();

    void SetAuthor(string a);
    string GetAuthor();

    void SetPages(int p);
    int GetPages();

    void SetGenre(string g);
    string GetGenre();

    void Info();
};
