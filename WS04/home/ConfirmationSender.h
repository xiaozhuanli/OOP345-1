// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/10/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        Reservation **cs_res_arr;
        int cs_count;

    public:
        int size() const;

        ConfirmationSender();

        ~ConfirmationSender();

        ConfirmationSender(ConfirmationSender &);

        ConfirmationSender(ConfirmationSender &&);

        ConfirmationSender &operator+=(Reservation &);

        ConfirmationSender &operator-=(Reservation &);

        friend ostream &operator<<(ostream &, ConfirmationSender &);
    };
}

#endif //SDDS_CONFIRMATIONSENDER_H