// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-05
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Autoshop.h"

namespace sdds {

    Autoshop &Autoshop::operator+=(Vehicle *v_in) {
        m_vehicles.push_back(v_in);
        return *this;
    }

    void Autoshop::display(ostream &os) const {
        os << "--------------------------------\n";
        os << "| Cars in the autoshop!        |\n";
        os << "--------------------------------\n";
        for (auto m_vehicle : m_vehicles) {
            m_vehicle->display(os);
        }
        os << "--------------------------------\n";
    }
}