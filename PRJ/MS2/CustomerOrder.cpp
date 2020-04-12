#include "CustomerOrder.h"

// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-01
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

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
        m_lstItem.push_back(u.extractToken(list));
        list.erase(0, u.extractToken(list).length() + 1);
    }
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

CustomerOrder::~CustomerOrder() {
}

bool CustomerOrder::isOrderFilled() const {
    bool flag = true;
    for (auto &&item : m_lstItem) {
        if (item.m_isFilled == false) {
            flag = false;
        }
    }
    return flag;
}

bool CustomerOrder::isItemFilled(const string &name) const {
    bool flag = false;
    for (auto &&item : m_lstItem) {
        if (item.m_itemName == name) {
            flag = true;
        }
    }
    return flag;
}

void CustomerOrder::fillItem(Station &st, ostream &os) {
    bool found = false;
    int foundAt = 0;
    for (size_t i = 0; i < m_lstItem.size(); i++) {
        if (m_lstItem[i].m_itemName == st.getItemName()) {
            found = true;
            foundAt = i;
            break;
        }
    }
    if (found) {
        if (st.getQuantity() == 0) {
            os << "Unable to fill " << m_name << ", " << m_product;
            os << " [" << m_lstItem[foundAt].m_itemName << "]";
            os << endl;
        } else {
            m_lstItem[foundAt].m_isFilled = true;
            m_lstItem[foundAt].m_serialNumber = st.getNextSerialNumber();
            st.updateQuantity();
            m_cntItem++;
            os << "    Filled " << m_name << ", " << m_product;
            os << " [" << m_lstItem[foundAt].m_itemName << "]";
            os << endl;
        }
    }
}

void CustomerOrder::display(ostream &os) const {
    os << m_name << " - " << m_product << endl;
    for (auto &&i : m_lstItem) {
        os << setw(6) << setfill('0') << "[" << i.m_serialNumber << "] ";
        os << setfill(' ');
        os << setw(m_widthField) << i.m_itemName << " - ";
        if (i.m_isFilled) {
            os << "FILLED\n";
        } else {
            os << "MISSING\n";
        }
    }
}
