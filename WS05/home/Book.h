// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/17/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "SpellChecker.h"

using namespace std;

namespace sdds {
    class Book {
        string book_author;
        string book_title;
        string book_country;
        int book_year;
        double book_price;
        string book_desc;

    public:
        template<typename T>
        void fixSpelling(T SP) {
            SP(book_desc);
        }

        Book();

        const string title() const;

        const string country() const;

        const int year() const;

        double &price();

        Book(const string &);

        friend ostream &operator<<(ostream &, const Book &);
    };
}

#endif //SDDS_BOOK_H