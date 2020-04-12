// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-05
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"
using namespace std;

namespace sdds {
    class Autoshop {
        vector<Vehicle *> m_vehicles;
    public:
        Autoshop &operator+=(Vehicle *);

        void display(ostream &) const;
    };
}

#endif //SDDS_AUTOSHOP_H
