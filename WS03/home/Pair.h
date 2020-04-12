// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
#include "Set.h"

namespace sdds {
    template<typename K, typename V>
    class Pair {
    public:
        K p_key;
        V p_value;

        Pair() {
            p_key = {};
            p_value = {};
        }

        Pair(const K &k, const V &v) {
            p_key = k;
            p_value = v;
        }

        const K &key() const {
            return p_key;
        }

        const V &value() const {
            return p_value;
        }

        virtual void display(std::ostream &os) const {
            os << p_key << " : " << p_value << "\n";
        }
    };

    template<typename K, typename V>
    std::ostream &operator<<(std::ostream &os, const Pair<K, V> &p) {
        p.display(os);
        return os;
    }
}

#endif //SDDS_PAIR_H