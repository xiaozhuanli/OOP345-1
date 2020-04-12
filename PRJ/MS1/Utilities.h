// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-22
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class Utilities {
    unsigned int m_widthField = 1;
    inline static char m_delimiter{','};
public:
    void setFieldWidth(unsigned int);

    unsigned int getFieldWidth() const;

    string extractToken(const string &);

    static void setDelimiter(char);

    static char getDelimiter();
};
