#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

extern unsigned long g_sysClock;

namespace sdds {
    class Event {
    private:
        char desc[128];
        unsigned long seconds;
    public:
        Event();

        void display();

        void setDescription(char arr_in[]);
    };
}

#endif