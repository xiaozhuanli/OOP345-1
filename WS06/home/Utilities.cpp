// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"
#include "Racecar.h"

namespace sdds {

    Vehicle *createInstance(istream &is) {
        stringstream ss;
        string str;
        getline(is, str, '\n');
        ss << str;
        str = str.substr(0, str.find(','));
        trim(str);
        if (str.empty()) {
            return nullptr;
        }
        if (str[0] == 'c' || str[0] == 'C' || str[0] == 'r' || str[0] == 'R') {
            if (str[0] == 'c' || str[0] == 'C') {
                Car *c = nullptr;
                c = new Car(ss);
                return c;
            } else if (str[0] == 'r' || str[0] == 'R') {
                Racecar *rc = nullptr;
                rc = new Racecar(ss);
                return rc;
            } else {
                return nullptr;
            }
        } else {
            throw str[0];
        }
    }
}