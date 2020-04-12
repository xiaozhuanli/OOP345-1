// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-05
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
        maker = "";
        cnd = "";
        maxSpd = 0;
    }

    Car::Car(istream &is) {
        string _make, _cond, _spd;
        string str;
        getline(is, str, '\n');

        _make = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);

        _cond = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);

        _spd = str.substr(0, str.find(','));
        str.erase(0, str.find(',') + 1);

        trim(_make);
        trim(_cond);
        trim(_spd);
        maker = _make;
        cnd = _cond;
        maxSpd = stod(_spd);
        switch (cnd[0]) {
            case 'n':
                cnd = "new";
                break;
            case 'b':
                cnd = "broken";
                break;
            case 'u':
                cnd = "used";
                break;
        }
    }

    string Car::condition() const {
        return cnd;
    }

    double Car::topSpeed() const {
        return maxSpd;
    }

    void Car::display(ostream &os) const {
        os << "| ";
        os << setw(10) << right << maker << " | ";
        os << setw(6) << left << cnd << " | ";
        os << setw(6) << fixed << setprecision(2) << topSpeed() << " |\n";
    }

} // namespace sdds