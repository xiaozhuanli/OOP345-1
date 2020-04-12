// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Utilities {
    size_t m_widthField = 1;
    inline static char m_delimiter{','};
public:
    void setFieldWidth(size_t);

    size_t getFieldWidth() const;

    string extractToken(const string &);

    string extractToken(const string &str_in, size_t &next, bool &more);

    static void setDelimiter(char);

    static char getDelimiter();
};
