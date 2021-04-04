#pragma once
#include <string>
using namespace std;

class Emissions {
    string facilityName;
    string streetAddress;
    string city;
    string state;
    string zip;
    string industrySector;
    string chemical;
    double totalReleases;

public:
    Emissions(string facilityName, string streetAddress, string city, string state, string zip, string industrySector, string chemical, double totalReleases) {
        this->facilityName = facilityName;
        this->streetAddress = streetAddress;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->industrySector = industrySector;
        this->chemical = chemical;
        this->totalReleases = totalReleases;
    }

    string getFacilityName() {
        return facilityName;
    }

    string getStreetAddress() {
        return streetAddress;
    }

    string getCity() {
        return city;
    }

    string getState() {
        return state;
    }

    string getZip() {
        return zip;
    }

    string getIndustrySector() {
        return industrySector;
    }

    string getChemical() {
        return chemical;
    }

    double getTotalReleases() {
        return totalReleases;
    }
};
