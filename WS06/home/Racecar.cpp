// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds {

    Racecar::Racecar(istream &is) : Car(is) {
        is >> rc_booster;
    }

    void Racecar::display(ostream &os) const {
        Car::display(os);
        os << "*";
    }

    double Racecar::topSpeed() const {
        return (Car::topSpeed() * (rc_booster + 1));
    }
}