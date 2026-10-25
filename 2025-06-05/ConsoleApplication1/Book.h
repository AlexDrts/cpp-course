#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;
    string genre;

public:
    void SetTitle(string title);
    string GetTitle();

    void SetAuthor(string author);
    string GetAuthor();

    void SetPages(int pages);
    int GetPages();

    void SetGenre(string genre);
    string GetGenre();

    void Info();
};
