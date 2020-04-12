// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 01/23/2020
//
//   I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

namespace sdds {
    class RecordSet {
    public:
        string *rs_strings;
        int rs_string_count;

        RecordSet();

        ~RecordSet();

        RecordSet(char *given_str);

        RecordSet(const RecordSet &given_rs);

        RecordSet &operator=(const RecordSet &given_rs);

        size_t size();

        string getRecord(int given_t);
    };
}

#endif