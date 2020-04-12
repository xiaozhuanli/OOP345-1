// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/18/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

extern size_t g_sysClock;

namespace sdds {
    class Event {
    private:
        char *desc;
        size_t seconds;
    public:
        Event();

        ~Event();

        void display();

        void setDescription(char arr_in[]);
    };
}

#endif