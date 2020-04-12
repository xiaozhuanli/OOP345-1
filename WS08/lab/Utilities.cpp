// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-21
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price) {
        List<Product> priceList;
        // TODO: Add your code here to build a list of products
        //         using raw pointers
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    auto *tmp = new Product(desc[i].desc, price[j].price);
                    tmp->validate();
                    priceList += tmp;
                    delete tmp;
                }
            }
        }
        return priceList;
    }
}