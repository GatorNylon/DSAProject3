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

    //added for testing sorting
    //=============================================
    Emissions ( double totalReleases) {
        this->totalReleases = totalReleases;
    }

    Emissions (string state) {
        this->state = state;
    }

    /*bool lessThan_totalRelease(Emissions a, Emissions b)
    {
        return (a.getTotalReleases() < b.getTotalReleases());
    }*/
    //=============================================


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
