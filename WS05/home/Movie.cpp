// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/17/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Movie.h"

namespace sdds {
    Movie::Movie() {
        mov_year = 0;
        mov_title = "";
        mov_desc = "";
    }

    const string &Movie::title() const {
        return mov_title;
    }

    Movie::Movie(const string &_mov) {
        string title, year, desc;
        string str = _mov; // make copy of _mov

        // extract data from str
        title = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        year = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        desc = str;

        // trim whitespace
        title.erase(title.find_last_not_of(' ') + 1);
        title.erase(0, title.find_first_not_of(' '));

        desc.erase(desc.find_last_not_of(' ') + 1);
        desc.erase(0, desc.find_first_not_of(' '));

        // assign temp variables to class variables
        mov_title = title;
        mov_desc = desc;
        mov_year = stoi(year);
    }

    ostream &operator<<(ostream &os, const Movie &_mov) {
        if (_mov.mov_year > 0) {
            os << setw(40) << setfill(' ') << _mov.mov_title << " | ";
            os << setw(4) << _mov.mov_year << " | ";
            os << _mov.mov_desc << '\n';
        }
        return os;
    }
}