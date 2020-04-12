// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Item {
    string m_itemName;
    size_t m_serialNumber = 0;
    bool m_isFilled = false;

    Item(const string &src) : m_itemName(src) {};
};

class CustomerOrder {
    string m_name = "";
    string m_product = "";
    size_t m_cntItem = 0;
    vector<Item> m_lstItem;
    inline static size_t m_widthField{0};

public:
    CustomerOrder() {};

    CustomerOrder(string &);

    CustomerOrder(CustomerOrder &);

    CustomerOrder &operator=(CustomerOrder &) = delete;

    CustomerOrder(CustomerOrder &&) noexcept;

    CustomerOrder &operator=(CustomerOrder &&) noexcept;

    bool isOrderFilled() const;

    bool isItemFilled(const string &) const;

    void fillItem(Station &, ostream &);

    void display(ostream &) const;
};
