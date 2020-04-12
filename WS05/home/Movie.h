// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/17/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace sdds {
    class Movie {
        string mov_title;
        int mov_year;
        string mov_desc;
    public:
        Movie();

        const string &title() const;

        Movie(const string &);

        template<typename T>
        void fixSpelling(T SP) {
            SP(mov_title);
            SP(mov_desc);
        }

        friend ostream &operator<<(ostream &, const Movie &);
    };
}

#endif //SDDS_MOVIE_H