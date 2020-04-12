// Name: Ricardo Maharaj
// Seneca Student ID: 160058186
// Seneca email: rmaharaj14@myseneca.ca
// Date of completion: 2020-03-09
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Autoshop.h"
#include "Utilities.h"
#include <fstream>
#include <iomanip>
#include <iostream>

void loadData(const char *filename, sdds::Autoshop &as) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
        return;
    }
    while (file) {
        // TODO: This code can throw errors to signal that something went wrong while
        //         extracting data. Write code to catch and handle the following errors:
        //       - the type of vehicle is not recognized: the first non-empty character
        //           on the line is not 'c', 'C', 'r', or 'R'. In this case print
        //           "Unrecognized record type: [TAG]<endl>"
        //       - one of the fields in the record contains invalid data. In this case print
        //           "Invalid record!<endl>"
        try {
            sdds::Vehicle *aVehicle = sdds::createInstance(file);
            if (aVehicle) {
                as += aVehicle;
            }
        } catch (char &c) {
            std::cout << "Unrecognized record type: [" << c << "]\n";
        } catch (string &s) {
            std::cout << s << endl;
        }
    }
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char **argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    sdds::Autoshop as;
    loadData(argv[1], as);
    as.display(std::cout);
    std::cout << "\n";
    loadData(argv[2], as);
    as.display(std::cout);

    std::cout << std::endl;
    std::list<const sdds::Vehicle *> vehicles;
    {
        // TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
        //         and returns true if the vehicle has a top speed >300km/h
        auto fastVehicles = [&](const sdds::Vehicle *v) {
            return (v->topSpeed() > 300);
        };
        as.select(fastVehicles, vehicles);
        std::cout << "--------------------------------\n";
        std::cout << "|       Fast Vehicles          |\n";
        std::cout << "--------------------------------\n";
        for (auto &vehicle : vehicles) {
            vehicle->display(std::cout);
            std::cout << std::endl;
        }
        std::cout << "--------------------------------\n";
    }

    vehicles.clear();
    std::cout << std::endl;
    {
        // TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
        //         and returns true if the vehicle is broken and needs repairs.
        auto brokenVehicles = [&](const sdds::Vehicle *v) {
            return (v->condition() == "broken");
        };
        as.select(brokenVehicles, vehicles);
        std::cout << "--------------------------------\n";
        std::cout << "| Vehicles in need of repair   |\n";
        std::cout << "--------------------------------\n";
        for (const auto vehicle : vehicles) {
            vehicle->display(std::cout);
            std::cout << std::endl;
        }
        std::cout << "--------------------------------\n";
    }

    return 0;
}