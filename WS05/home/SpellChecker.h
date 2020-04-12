// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/17/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

namespace sdds {
    class SpellChecker {
        string sc_bad[5];
        string sc_good[5];

    public:
        SpellChecker();

        SpellChecker(const char *);

        void operator()(string &);
    };
}

#endif //SDDS_SPELLCHECKER_H