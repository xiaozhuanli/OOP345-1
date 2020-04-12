// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 02/10/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iomanip>
#include "Reservation.h"

namespace sdds {
    Reservation::Reservation() {
        res_id = "";
        res_name = "";
        res_email = "";
        res_people = 0;
        res_day = 0;
        res_hour = 0;
    }

    Reservation::Reservation(const string &res) {
        string id, name, email, people, day, hour;
        string str = res;

        id = str.substr(0, str.find(':'));

        str.erase(0, str.find(':') + 1);
        name = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        email = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        people = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        day = str.substr(0, str.find(','));

        str.erase(0, str.find(',') + 1);
        hour = str.substr(0, str.find(','));

        id.erase(id.find_last_not_of(' ') + 1);
        id.erase(0, id.find_first_not_of(' '));

        name.erase(name.find_last_not_of(' ') + 1);
        name.erase(0, name.find_first_not_of(' '));

        email.erase(email.find_last_not_of(' ') + 1);
        email.erase(0, email.find_first_not_of(' '));

        email = "<" + email + ">";

        res_id = id;
        res_name = name;
        res_email = email;
        res_people = stoi(people);
        res_day = stoi(day);
        res_hour = stoi(hour);
    }

    ostream &operator<<(ostream &os, Reservation &res) {
        string serve[4] = {"Breakfast", "Lunch", "Dinner", "Drinks"};
        int val = 0;
        if (res.res_hour >= 6 && res.res_hour <= 9) {
            val = 0;
        } else if (res.res_hour >= 11 && res.res_hour <= 15) {
            val = 1;
        } else if (res.res_hour >= 17 && res.res_hour <= 21) {
            val = 2;
        } else {
            val = 3;
        }

        os << "Reservation " << res.res_id << ": ";
        os << setw(10) << setfill(' ') << right << res.res_name << "  ";
        os << setw(24) << setfill(' ') << left << res.res_email;
        os << serve[val] << " on day " << res.res_day << " @ " << res.res_hour << ":00" << " for " << res.res_people
           << " people." << '\n';
        return os;
    }
}