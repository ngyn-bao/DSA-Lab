#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    char *title;
    char *authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this->publishingYear = 0;
        this->title = nullptr;
        this->authors = nullptr;
    }

    Book(const char *title, const char *authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this->title = book.title;
        this->authors = book.authors;
        this->publishingYear = book.publishingYear;
    }

    void setTitle(const char *title)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = title;
    }

    void setAuthors(const char *authors)
    {
        /*
         * STUDENT ANSWER
         */
        this->authors = authors;
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->publishingYear = publishingYear;
    }

    const char *getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->title;
    }

    const char *getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
        delete this->title;
        delete this->authors;
    }

    void printBook()
    {
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};