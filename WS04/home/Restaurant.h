// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/10/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation *rest_reserves;
        int rest_num;
    public:
        Restaurant();

        ~Restaurant();

        Restaurant(Reservation *[], int);

        Restaurant(const Restaurant &);

        Restaurant(Restaurant&&);

        int size() const;

        friend ostream &operator<<(ostream &, const Restaurant &);
    };

}


#endif //SDDS_RESTAURANT_H