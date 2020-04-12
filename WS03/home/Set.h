// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/30/2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
    template<typename T, unsigned int N>
    class Set {
    public:
        T arr[N];
        size_t count;
        T _arr;

        size_t size() const {
            return count;
        }

        const T &operator[](size_t pos) const {
            if (pos < N) {
                return arr[pos];
            } else {
                return _arr;
            }
        }

        void operator+=(const T &i) {
            if (count < N) {
                arr[count] = i;
                count++;
            }
        }
    };
}

#endif //SDDS_SET_H