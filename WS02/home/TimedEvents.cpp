// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/25/2020
//
//   I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "TimedEvents.h"

namespace sdds {

    TimedEvents::TimedEvents() {
        te_cur_recs = {0};
        recs->te_name = {};
        recs->te_time_unit = {};
        recs->te_duration = {};
        te_start_time = {};
        te_end_time = {};
    }

    void TimedEvents::startClock() {
        te_start_time = chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        te_end_time = chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const char *name) {
        if (te_cur_recs < MAX_RECS) {
            recs[te_cur_recs].te_name = name;
            recs[te_cur_recs].te_time_unit = "nanoseconds";
            recs[te_cur_recs].te_duration = chrono::duration_cast<chrono::nanoseconds>(te_end_time - te_start_time);
            te_cur_recs++;
        }
    }

    ostream &operator<<(ostream &os, const TimedEvents &te) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";

        for (int i = 0; i < te.te_cur_recs; i++)
            os << setw(20) << left
               << te.recs[i].te_name << ' '
               << setw(12) << right
               << te.recs[i].te_duration.count() << ' '
               << te.recs[i].te_time_unit << '\n';
        os << "--------------------------\n";

        return os;
    }
}