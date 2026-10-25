#include "Book.h"
#include <iostream>
using namespace std;

void Book::SetTitle(string title) {
    this->title = title;
}
string Book::GetTitle() { return title; }

void Book::SetAuthor(string author) {
    this->author = author;
}
string Book::GetAuthor() { return author; }

void Book::SetPages(int pages) {
    this->pages = pages;
}
int Book::GetPages() { return pages; }

void Book::SetGenre(string genre) {
    this->genre = genre;
}
string Book::GetGenre() { return genre; }

void Book::Info() {
    cout << "Book Info:\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Pages: " << pages << "\n";
    cout << "Genre: " << genre << "\n\n";
}