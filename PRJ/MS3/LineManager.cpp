// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "LineManager.h"
#include <fstream>

LineManager::LineManager(const string &filename, vector<Workstation *> &ws, vector<CustomerOrder> &co) {
    Utilities u;
    string line, one, two;
    fstream file(filename);
    size_t pos = 0;
    bool more = true;
    while (file) {
        while (getline(file, line, '\n')) {
            one = u.extractToken(line, pos, more);
            for (size_t i = 0u; i < ws.size(); i++) {
                if (one == ws[i]->getItemName()) {
                    if (more) {
                        two = u.extractToken(line, pos, more);
                        for (size_t j = 0u; j < ws.size(); j++) {
                            if (two == ws[j]->getItemName()) {
                                ws[i]->setNextStation(*ws[j]);
                            }
                        }
                    }
                    m_assemblySorted.push_back(ws[i]);
                }
            }
        }
    }
    m_assemblyLine = ws;
    m_cntCustomerOrder = co.size();
    m_toBeFilled = deque<CustomerOrder>(m_cntCustomerOrder);
    for (size_t i = 0u; i < co.size(); i++) {
        m_toBeFilled[i] = move(co[i]);
    }
}

bool LineManager::run(ostream &os) {
    static size_t count = 0;
    os << "Line Manager Iteration: " << ++count << endl;
    if (!m_toBeFilled.empty()) {
        *m_assemblySorted.at(0) += move(m_toBeFilled.front());
        m_toBeFilled.pop_front();
    }
    for (auto &&i : m_assemblyLine) {
        i->runProcess(os);
    }
    CustomerOrder tmp;
    for (auto &&j : m_assemblyLine) {
        j->moveOrder();
        if (j->getIfCompleted(tmp)) {
            m_completed.push_back(move(tmp));
        }
    }
    return m_completed.size() == m_cntCustomerOrder;
}

void LineManager::displayCompletedOrders(ostream &os) {
    for (auto &&i : m_completed) {
        i.display(os);
    }
}

void LineManager::displayStations() const {
    for (auto &&i : m_assemblyLine) {
        i->display(cout);
    }
}

void LineManager::displayStationsSorted() const {
    for (auto &&i : m_assemblySorted) {
        i->display(cout);
    }
}
