// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/23/2020
//
//   I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;

#define MAX_RECS 7

namespace sdds {
    class TimedEvents {
    public:
        int te_cur_recs;
        chrono::steady_clock::time_point te_start_time;
        chrono::steady_clock::time_point te_end_time;
        struct {
            const char *te_name;
            const char *te_time_unit;
            chrono::steady_clock::duration te_duration;
        } recs[MAX_RECS];

        TimedEvents();

        void startClock();

        void stopClock();

        void recordEvent(const char *name);

        friend ostream &operator<<(ostream &os, const TimedEvents &te);
    };
}

#endif