// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/25/2020
//
//   I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "RecordSet.h"

namespace sdds {
    RecordSet::RecordSet() {
        rs_strings = nullptr;
        rs_string_count = 0;
    }

    RecordSet::~RecordSet() {
        delete[] rs_strings;
        rs_strings = nullptr;
    }

    RecordSet::RecordSet(char *given_str) {
        string _buffer;
        ifstream file(given_str);
        int i = 0;
        while (!file.eof()) {
            getline(file, _buffer, ' ');
            ++i;
        }
        rs_strings = new string[i + 1];
        _buffer = {};
        file.close();
        file.open(given_str);
        i = 0;
        while (getline(file, _buffer, ' ')) {
            rs_strings[i] = _buffer;
            ++i;
        }
        rs_string_count = i;
    }

    RecordSet::RecordSet(const RecordSet &given_rs) {
        *this = given_rs;
    }

    RecordSet &RecordSet::operator=(const RecordSet &given_rs) {
        rs_string_count = given_rs.rs_string_count;
        rs_strings = new string[rs_string_count];
        for (int i = 0; i < rs_string_count; ++i) {
            rs_strings[i] = given_rs.rs_strings[i];
        }
        return *this;
    }

    size_t RecordSet::size() {
        return rs_string_count;
    }

    string RecordSet::getRecord(int given_t) {
        if (rs_strings != nullptr) {
            return string(rs_strings[given_t]);
        } else {
            return "";
        }
    }

    RecordSet::RecordSet(RecordSet &&given_rs) {
        *this = move(given_rs);
    }

    RecordSet &RecordSet::operator=(RecordSet &&given_rs) {
        if (this != &given_rs) {
            rs_string_count = given_rs.rs_string_count;
            rs_strings = new string[rs_string_count];
            for (int i = 0; i < rs_string_count; ++i) {
                rs_strings[i] = given_rs.rs_strings[i];
            }
            delete[] given_rs.rs_strings;
            given_rs.rs_strings = nullptr;
            given_rs.rs_string_count = 0;
        }
        return *this;
    }
}