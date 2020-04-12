// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include "Car.h"

namespace sdds {
    class Racecar : public Car {
        double rc_booster;

    public:
        Racecar(istream &);

        void display(ostream &) const;

        double topSpeed() const;
    };
}