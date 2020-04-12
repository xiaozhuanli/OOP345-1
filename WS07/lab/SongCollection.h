// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-12
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

namespace sdds {

    void trim(string &);

    struct Song {
        string artist, title, album, price, year, mins, secs;
    };

    class SongCollection {
        vector<Song> songs;
    public:
        SongCollection(string);

        void display(ostream &) const;
    };

    ostream &operator<<(ostream &, const Song &);
}