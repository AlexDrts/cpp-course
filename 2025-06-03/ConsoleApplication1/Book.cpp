#include "Book.h"
#include <iostream>
using namespace std;

void Book::SetTitle(string t) { title = t; }
string Book::GetTitle() { return title; }

void Book::SetAuthor(string a) { author = a; }
string Book::GetAuthor() { return author; }

void Book::SetPages(int p) { pages = p; }
int Book::GetPages() { return pages; }

void Book::SetGenre(string g) { genre = g; }
string Book::GetGenre() { return genre; }

void Book::Info() {
    cout << "Book Info:\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Pages: " << pages << "\n";
    cout << "Genre: " << genre << "\n\n";
}