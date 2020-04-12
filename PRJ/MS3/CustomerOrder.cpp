// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "CustomerOrder.h"

CustomerOrder::CustomerOrder(string &str) {
    Utilities u;
    string custName, orderName, list;

    custName = u.extractToken(str);
    str.erase(0, custName.length() + 1);

    orderName = u.extractToken(str);
    str.erase(0, orderName.length() + 1);

    list = str;

    if (m_widthField < u.getFieldWidth()) {
        m_widthField = u.getFieldWidth();
    }

    m_name = custName;
    m_product = orderName;

    while (list.length() > 0) {
        m_lstItem.emplace_back(u.extractToken(list));
        list.erase(0, u.extractToken(list).length() + 1);
    }
    m_cntItem = m_lstItem.size();
}

CustomerOrder::CustomerOrder(CustomerOrder &co) {
    string err("no copying allowed!");
    throw err;
}

CustomerOrder::CustomerOrder(CustomerOrder &&co) noexcept {
    *this = move(co);
}

CustomerOrder &CustomerOrder::operator=(CustomerOrder &&co) noexcept {
    m_name = co.m_name;
    m_product = co.m_product;
    m_cntItem = co.m_cntItem;
    swap(m_lstItem, co.m_lstItem);
    return *this;
}

bool CustomerOrder::isOrderFilled() const {
    for (size_t i = 0u; i < m_cntItem; ++i) {
        if (!m_lstItem[i].m_isFilled) {
            return false;
        }
    }
    return true;
}

bool CustomerOrder::isItemFilled(const string &name) const {
    for (size_t i = 0u; i < m_cntItem; ++i) {
        if (m_lstItem[i].m_itemName == name) {
            if (!m_lstItem[i].m_isFilled) {
                return false;
            }
        }
    }
    return true;
}

void CustomerOrder::fillItem(Station &st, ostream &os) {
    for (size_t i = 0u; i < m_cntItem; ++i) {
        if (m_lstItem[i].m_itemName == st.getItemName()) {
            if (st.getQuantity() != 0) {
                m_lstItem[i].m_isFilled = true;
                m_lstItem[i].m_serialNumber = st.getNextSerialNumber();
                st.updateQuantity();
                os << "    Filled " << m_name << ", " << m_product;
                os << " [" << m_lstItem[i].m_itemName << "]\n";
            } else if (st.getQuantity() == 0) {
                os << "Unable to fill " << m_name << ", " << m_product;
                os << " [" << m_lstItem[i].m_itemName << "]\n";
            }
        }
    }
}

void CustomerOrder::display(ostream &os) const {
    os << m_name << " - " << m_product << endl;
    for (auto &&i : m_lstItem) {
        os << "[" << setfill('0') << right << setw(6) << i.m_serialNumber << "] ";
        os << setfill(' ') << left;
        os << setw(m_widthField) << i.m_itemName << " - ";
        if (i.m_isFilled) {
            os << "FILLED\n";
        } else {
            os << "MISSING\n";
        }
    }
}
