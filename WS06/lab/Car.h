// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-05
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

namespace sdds {

    class Car : public Vehicle {
        string maker;
        string cnd;
        double maxSpd;

    public:
        Car();

        Car(istream &);

        string condition() const;

        double topSpeed() const;

        void display(ostream &) const;
    };

} // namespace sdds

#endif // SDDS_CAR_H
