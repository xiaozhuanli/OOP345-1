// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-04-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

void Utilities::setFieldWidth(size_t w) {
    m_widthField = w;
}

size_t Utilities::getFieldWidth() const {
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

string Utilities::extractToken(const string &str, size_t &next, bool &more) {
    size_t pos = str.find(m_delimiter, next);
    if (pos == next) {
        more = false;
        throw "err";
    } else {
        more = pos != string::npos;
        string re = str.substr(next, pos - next);
        next = pos + 1;
        if (re.size() > m_widthField)
            m_widthField = re.length();
        return re;
    }
}

void Utilities::setDelimiter(char c) {
    m_delimiter = c;
}

char Utilities::getDelimiter() {
    return m_delimiter;
}
