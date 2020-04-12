// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include "CustomerOrder.h"
#include "Station.h"
#include <vector>
#include <deque>

class Workstation : public Station {
    deque<CustomerOrder> m_orders;
    Workstation *m_pNextStation = nullptr;

public:
    Workstation(const string &);

    // no copy or move allowed
    Workstation(Workstation &) = delete;

    Workstation &operator=(Workstation &) = delete;

    Workstation(Workstation &&) = delete;

    Workstation &operator=(Workstation &&) = delete;
    //

    void runProcess(ostream &);

    bool moveOrder();

    void setNextStation(Station &);

    const Workstation *getNextStation() const;

    bool getIfCompleted(CustomerOrder &);

    void display(ostream &);

    Workstation &operator+=(CustomerOrder &&);
};
