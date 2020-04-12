// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include "Utilities.h"

class Station {
    size_t m_id;
    string m_name = "";
    string m_desc = "";
    size_t m_serial = 0u;
    size_t m_stock = 0u;
    inline static size_t m_widthField{0u};
    inline static size_t id_generator{0u};
public:

    Station(const string &);

    const string &getItemName() const;

    size_t getNextSerialNumber();

    size_t getQuantity() const;

    void updateQuantity();

    void display(ostream &, bool) const;
};
