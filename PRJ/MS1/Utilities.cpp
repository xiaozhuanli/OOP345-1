// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-22
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

void Utilities::setFieldWidth(unsigned int w) {
    m_widthField = w;
}

unsigned int Utilities::getFieldWidth() const {
    return m_widthField;
}

string Utilities::extractToken(const string &str) {
    string re = str.substr(0, str.find(m_delimiter));
    if (m_widthField < re.length()) {
        m_widthField = re.length();
    }
    if (getFieldWidth() < re.length()) {
        setFieldWidth(re.length());
    }
    return re;
}

void Utilities::setDelimiter(char c) {
    m_delimiter = c;
}

char Utilities::getDelimiter() {
    return m_delimiter;
}
