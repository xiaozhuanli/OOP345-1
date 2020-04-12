// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Car.h"

namespace sdds {

    string &trim(string &str) {
        str.erase(str.find_last_not_of(' ') + 1);
        str.erase(0, str.find_first_not_of(' '));
        return str;
    }

    Car::Car() {
        cr_make = "";
        cr_cond = "";
        cr_topSpd = 0;
    }

    Car::Car(istream &is) {
        string _make, _cond, _spd, _str;
        getline(is, _str, ',');
        getline(is, _make, ',');
        getline(is, _cond, ',');
        is >> _spd;

        trim(_make);
        trim(_cond);
        trim(_spd);

        if (_cond.empty()) {
            _cond = "new";
        } else {
            if (_cond[0] == 'n') {
                _cond = "new";
            } else if (_cond[0] == 'b') {
                _cond = "broken";
            } else if (_cond[0] == 'u') {
                _cond = "used";
            } else {
                string err = "Invalid record!";
                throw err;
            }
        }
        cr_make = _make;
        cr_cond = _cond;
        try {
            cr_topSpd = stod(_spd);
        } catch (exception &e) {
            string err = "Invalid record!";
            throw err;
        }
    }

    string Car::condition() const {
        return cr_cond;
    }

    double Car::topSpeed() const {
        return cr_topSpd;
    }

    void Car::display(ostream &os) const {
        os << "| ";
        os << setw(10) << right << cr_make << " | ";
        os << setw(6) << left << cr_cond << " | ";
        os << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
    }

}