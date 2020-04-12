// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/10/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant() {
        rest_reserves = nullptr;
        rest_num = 0;
    }

    Restaurant::~Restaurant() {
        delete[] rest_reserves;
        rest_reserves = nullptr;
    }

    Restaurant::Restaurant(Reservation *reserves[], int count) {
        rest_num = 0;
        rest_reserves = new Reservation[count];

        for (int i = 0; i < count; ++i) {
            rest_reserves[i] = *reserves[i];
        }
        rest_num = count;
    }

    int Restaurant::size() const {
        return rest_num;
    }

    ostream &operator<<(ostream &os, const Restaurant &res) {
        if (res.size() <= 0) {
            os << "--------------------------\n";
            os << "Fancy Restaurant\n";
            os << "--------------------------\n";
            os << "The object is empty!\n";
            os << "--------------------------\n";
        } else {
            os << "--------------------------\n";
            os << "Fancy Restaurant\n";
            os << "--------------------------\n";
            for (int i = 0; i < res.size(); ++i) {
                os << res.rest_reserves[i];
            }
            os << "--------------------------\n";
        }
        return os;
    }

    Restaurant::Restaurant(const Restaurant &res) {
        if (res.rest_reserves != nullptr) {
            rest_reserves = new Reservation[res.size() + 1];
            for (int i = 0; i < res.size(); ++i) {
                rest_reserves[i] = res.rest_reserves[i];
            }
            rest_num = res.rest_num;
        }
    }

    Restaurant::Restaurant(Restaurant &&res) {
        if (res.rest_reserves != nullptr) {
            swap(rest_reserves, res.rest_reserves);
            rest_num = res.rest_num;
            res.rest_num = 0;
            res.rest_reserves = nullptr;
        }
    }
}