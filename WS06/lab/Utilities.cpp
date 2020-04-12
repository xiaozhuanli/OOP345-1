// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-05
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds {

    Vehicle *createInstance(istream &is) {
        string str;
        is >> str;
        if (str[0] == 'c' || str[0] == 'C') {
            Car *c = nullptr;
            c = new Car(is);
            return c;
        } else {
            return nullptr;
        }
    }
}