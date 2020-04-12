// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include <vector>
#include "Vehicle.h"
#include <list>

using namespace std;

namespace sdds {
    class Autoshop {
        vector<Vehicle *> as_vehicles;

    public:
        ~Autoshop();

        Autoshop &operator+=(Vehicle *);

        void display(ostream &) const;

        template<typename T>
        void select(T test, list<const Vehicle *> &v) {
            for (auto &as_vehicle : as_vehicles) {
                if (test(as_vehicle)) {
                    v.push_back(as_vehicle);
                }
            }
        }
    };
}