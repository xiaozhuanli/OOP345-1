// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/18/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "event.h"

unsigned long g_sysClock;

namespace sdds {

    Event::Event() {
        desc = nullptr;
        seconds = 0;
    }

    Event::~Event() {
        if (desc == nullptr) {
            delete[] desc;
        }
    }

    void Event::display() {
        static int count = 1;
        int hh = 0, mm = 0, ss = 0;

        hh = seconds / 3600;
        mm = seconds / 60 % 60;
        ss = seconds % 60;

        if (desc == nullptr) {
            cout << setw(3) << setfill(' ') << count << ". " << "[ No Event ]\n";
        } else {
            cout << setw(3) << setfill(' ') << count << ". " << setw(2) << setfill('0') << hh << ":" << setw(2)
                 << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss << " -> " << desc << "\n";
        }
        count++;
    }

    void Event::setDescription(char *arr) {
        if (arr != nullptr) {
            if (desc != nullptr) {
                desc = nullptr;
            }
            desc = new char[strlen(arr) + 1];
            strcpy(desc, arr);
            seconds = g_sysClock;
        } else {
            desc = nullptr;
            seconds = 0;
        }
    }
}