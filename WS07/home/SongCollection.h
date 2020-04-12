// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-16
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
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>

using namespace std;

namespace sdds {

    void trim(string &);

    struct Song {
        string artist, title, album, price, year, mins, secs;
        int length;
        double m_price;
    };

    class SongCollection {
        int total;
        vector<Song> songs;
    public:
        SongCollection(string);

        void display(ostream &);

        void sort(string);

        void cleanAlbum();

        bool inCollection(string) const;

        vector<Song> getSongsForArtist(string) const;
    };

    ostream &operator<<(ostream &, const Song &);
}