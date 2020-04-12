// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/13/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

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
        Book();

        const string title();

        const string country();

        const int year();

        double &price();

        Book(const string &);

        friend ostream &operator<<(ostream &, const Book &);
    };
}

#endif //SDDS_BOOK_H