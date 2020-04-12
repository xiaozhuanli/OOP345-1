// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/17/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "SpellChecker.h"

namespace sdds {
    SpellChecker::SpellChecker() {
        for (int i = 0; i < 5; ++i) {
            sc_bad[i] = "";
            sc_good[i] = "";
        }
    }

    SpellChecker::SpellChecker(const char *filename) {
        ifstream file(filename);
        if (file) {
            string line[5];
            int i = 0;
            for (i = 0; i < 5; ++i) {
                getline(file, line[i]);
            }
            for (i = 0; i < 5; ++i) {
                sc_bad[i] = line[i].substr(0, line[i].find(' '));
                sc_good[i] = line[i].substr(line[i].find(' '), line[i].find('\n'));
                sc_good[i].erase(0, sc_good[i].find_first_not_of(' '));
            }
        } else {
            throw "Bad file name!\n";
        }
    }

    void SpellChecker::operator()(string &text) {
        for (int i = 0; i < 5; ++i) {
            if (text.find(sc_bad[i])) {
                text.replace(text.find(sc_bad[i]), sc_good[i].length(), sc_good[i]);
            }
        }
    }
}