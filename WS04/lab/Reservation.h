// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/06/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

using namespace std;

namespace sdds {
    class Reservation {
    protected:
        string res_id;
        string res_name;
        string res_email;
        int res_people;
        int res_day;
        int res_hour;
    public:
        Reservation();

        Reservation(const string &res);

        friend ostream &operator<<(ostream &os, Reservation &res);
    };
}

#endif