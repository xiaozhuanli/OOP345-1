// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include "Set.h"

namespace sdds {
    template<typename T, unsigned int N, typename K, typename V>
    class SetSummable : public Set<T, N> {
    public:
        V accumulate(const K &key) const {
            V val;
            val = (*this)[0].getInitialValue();
            for (size_t i = 0; i < this->size(); i++) {
                val = (*this)[i].sum(key, val);
            }
            return val;
        }
    };
}

#endif //SDDS_SETSUMMABLE_H