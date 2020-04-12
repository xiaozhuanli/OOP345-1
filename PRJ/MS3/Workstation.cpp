// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Workstation.h"

Workstation::Workstation(const string &str) : Station(str) {}

void Workstation::runProcess(ostream &os) {
    if (!m_orders.empty()) {
        m_orders.front().fillItem(*this, os);
    }
}

bool Workstation::moveOrder() {
    bool flag = false;
    if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation) {
        *m_pNextStation += move(m_orders.front());
        m_orders.pop_front();
        flag = true;
    }
    return flag;
}

void Workstation::setNextStation(Station &st) {
    m_pNextStation = (Workstation *) &st;
}

const Workstation *Workstation::getNextStation() const {
    return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder &co) {
    bool flag = false;
    if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
        co = move(m_orders.front());
        m_orders.pop_front();
        flag = true;
    }
    return flag;
}

void Workstation::display(ostream &os) {
    if (getNextStation()) {
        os << getItemName() << " --> " << getNextStation()->getItemName() << '\n';
    } else {
        os << getItemName() << " --> END OF LINE\n";
    }
}

Workstation &Workstation::operator+=(CustomerOrder &&co) {
    m_orders.push_back(move(co));
    return *this;
}
