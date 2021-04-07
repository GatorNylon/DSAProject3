#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <chrono>
#include "QuickSort.h"
#include "Emissions.h"
using namespace std;
using namespace std::chrono;


Emissions breakString(string line) {
    string facilityName;
    string streetAddress;
    string city;
    string state;
    string zip;
    string industrySector;
    string chemical;
    double totalReleases;
    stringstream fullString(line);
    string partialString;

    getline(fullString, partialString, ',');
    facilityName = partialString;

    getline(fullString, partialString, ',');
    streetAddress = partialString;

    getline(fullString, partialString, ',');
    city = partialString;

    getline(fullString, partialString, ',');
    state = partialString;

    getline(fullString, partialString, ',');
    zip = partialString;

    getline(fullString, partialString, ',');
    industrySector = partialString;

    getline(fullString, partialString, ',');
    chemical = partialString;

    try {
        getline(fullString, partialString, ',');
        totalReleases = stod(partialString);

        if (totalReleases < 0.0) {
            throw 1;
        }
    }
    catch (exception& excpt) {
        totalReleases = 0.0;
    }

    Emissions dataObject(facilityName, streetAddress, city, state, zip, industrySector, chemical, totalReleases);
    return dataObject;
}


void readFile(string FileName, vector<Emissions>& emissionData) {
    string line;
    ifstream File(FileName);

    if (File.is_open()) {
        getline(File, line);
        while (getline(File, line)) {
            emissionData.push_back(breakString(line));
        }
       
    }
}

void writeFile(string filename, vector<Emissions>& sortedData) { //This function needs fixing. Working on that
    ofstream myFile;

    myFile.open("quickSortData.csv");
    if (!myFile) {
        cout << "Error: File not Created" << endl;
    }

    else {
        cout << "File created successfully!" << endl;
        cout << sortedData.size();

        myFile << "Facility Name" << ',' << "Street Address" << "," << "City" << ',' << "State" << ',' << "Zip" << ',' << "IndustrySector" << ',' << "Chemical Name" << ',' << "Total Release" << endl;
        for (int i = 0; i < sortedData.size(); i++) {
            if (i == 603) {
                cout << "Here after 603";
            }
            //cout << sortedData[1000].getFacilityName()  << endl;
            myFile << sortedData[i].getFacilityName() << ','
                   << sortedData[i].getStreetAddress() << ','
                   << sortedData[i].getCity() << ','
                   << sortedData[i].getState() << ',' 
                   << sortedData[i].getZip() << ',' 
                   << sortedData[i].getIndustrySector() << ',' 
                   << sortedData[i].getChemical() << ',' 
                   << sortedData[i].getTotalReleases() << endl;
        }
        myFile.close();
    }
}

void printFile(vector<Emissions>& emissionData) {
    for (int i = 0; i < emissionData.size(); i++) {
         
        cout << "Facility Name: " << emissionData[i].getFacilityName() << endl
             << "Street Address: " << emissionData[i].getStreetAddress() << endl 
             << "City: " << emissionData[i].getCity() << endl 
             << "State: " << emissionData[i].getState() << endl 
             << "Zip: " << emissionData[i].getZip() << endl 
             << "Industry Sector: " << emissionData[i].getIndustrySector() << endl 
             << "Chemical Name: " << emissionData[i].getChemical() << endl 
             << "Total Release: " << emissionData[i].getTotalReleases() << endl << endl; 
    }
}



int main()
{
    int year, option;
    vector<Emissions> emissionData;
    vector<Emissions> quickSortData;

    
   

    cout << "Welcome to EmmissionSort!" << endl;
    cout << "Select from one of the following years: " << endl
        << "1. 2019" << endl << "2. 2018" << endl;

    cin >> year;

    /*======= Load data from file(s) =======*/
    if (year == 1)
        readFile("Test2.csv", emissionData);
    else
        readFile("2018.csv", emissionData);


   //How to only copy certain rows .. can i do for (int i = 0; i < 5000; i++).. something like this ?
    quickSortData = emissionData;

    writeFile("quickSortData.csv", quickSortData);

    cout << endl << "Sort By: " << endl
        << "1. State " << endl
        << "2. Zip Code" << endl
        << "3. City" << endl
        << "4. Emmisions Amount" << endl;
    cin >> option;

    switch (option)
    {

    case(1):
    {auto start = high_resolution_clock::now();
    quickSort(quickSortData, 0, quickSortData.size() - 1, 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
   // printFile(quickSortData);
   // writeFile("quickSortData.csv", quickSortData);
    cout << "Time taken to Quick Sort Emission Data: " << duration.count() << endl; }
        break;

    case(2):
    {auto start = high_resolution_clock::now();
    quickSort(emissionData, 0, emissionData.size() - 1, 2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // printFile(emissionData);
    cout << "Time taken to Quick Sort Emission Data: " << duration.count() << endl; }
        break;

    case(3):
    { auto start = high_resolution_clock::now();
    quickSort(emissionData, 0, emissionData.size() - 1, 3);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // printFile(emissionData);
    cout << "Time taken to Quick Sort Emission Data: " << duration.count() << endl; }
        break;

    case(4):
    { auto start = high_resolution_clock::now();
    quickSort(emissionData, 0, emissionData.size() - 1, 4);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //printFile(emissionData);
    cout << "Time taken to Quick Sort Emission Data: " << duration.count() << endl; }
        break;

    default:
        break;
    } 
}
