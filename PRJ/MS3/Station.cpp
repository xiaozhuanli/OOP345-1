// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Station.h"

Station::Station(const string &in) {

    string str = in;
    Utilities u;
    string name, serial, stock, desc;

    name = u.extractToken(str);
    str.erase(0, name.length() + 1);

    serial = u.extractToken(str);
    str.erase(0, serial.length() + 1);

    stock = u.extractToken(str);
    str.erase(0, stock.length() + 1);

    if (m_widthField < u.getFieldWidth()) {
        m_widthField = u.getFieldWidth();
    }

    desc = str;

    m_id = id_generator++;
    m_id++;

    m_name = name;
    stringstream s1(serial);
    s1 >> m_serial;
    stringstream s2(stock);
    s2 >> m_stock;
    m_desc = desc;
}

const string &Station::getItemName() const {
    return m_name;
}

size_t Station::getNextSerialNumber() {
    return m_serial++;
}

size_t Station::getQuantity() const {
    return m_stock;
}

void Station::updateQuantity() {
    if (m_stock == 1) {
        m_stock = 0;
    } else {
        m_stock -= 1;
    }
}

void Station::display(ostream &os, bool qty) const {
    os << "[" << right << setw(3) << setfill('0') << m_id << setfill(' ') << "]";
    os << " Item: " << left << setw(m_widthField) << getItemName() << " ";
    os << "[" << right << setw(6) << setfill('0') << m_serial << setfill(' ') << "]";
    if (qty) {
        os << " Quantity: " << setw(m_widthField) << left << m_stock << " Description: " << m_desc;
    }
    os << left << setfill(' ');
    os << endl;
}
