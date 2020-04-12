// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include "Vehicle.h"
#include <cstring>
#include <exception>
#include <iomanip>
#include <vector>

using namespace std;

namespace sdds {

    string &trim(string &);

    class Car : public Vehicle {
        string cr_make;
        string cr_cond;
        double cr_topSpd;

    public:
        Car();

        Car(istream &);

        string condition() const;

        double topSpeed() const;

        void display(ostream &) const;
    };

}