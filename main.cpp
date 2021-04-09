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
    int zip;
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

    try {
        getline(fullString, partialString, ',');
        zip = stoi(partialString);

        if (zip < 0) {
            throw 1;
        }
    }
    catch (exception& excpt) {
        zip = 0;
    }



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
    File.close();
}

void writeFile(vector<Emissions>& sortedData, string filename) {
    ofstream myFile;

    myFile.open("Sorted/" + filename);
    if (!myFile) {
        cout << "Error: File not Created" << endl;
    }

    else {
        myFile << "Facility Name" << ',' << "Street Address" << "," << "City" << ',' << "State" << ',' << "Zip" << ',' << "IndustrySector" << ',' << "Chemical Name" << ',' << "Total Release" << endl;
        for (int i = 0; i < sortedData.size(); i++) {
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


int main()
{
    int year, option;
    bool check = true;

    //p = 4 (types of sorting)
    //q = 4(types of fields to be sorted)
    //r = 4 (number of data volumnes) 

    /*======= Vector Declarations =======*/

    //Quick Sort for 250 Size
    vector<Emissions> emissionData;
    vector<Emissions> qS_States_250;
    vector<Emissions> qS_Zip_250;
    vector<Emissions> qS_City_250;
    vector<Emissions> qS_Amount_250;

    //Quick Sort for 500 Size
    vector<Emissions> qS_States_500;
    vector<Emissions> qS_Zip_500;
    vector<Emissions> qS_City_500;
    vector<Emissions> qS_Amount_500;

    //Quick Sort for 750 Size
    vector<Emissions> qS_States_750;
    vector<Emissions> qS_Zip_750;
    vector<Emissions> qS_City_750;
    vector<Emissions> qS_Amount_750;

    //Quick Sort for 1000 Size
    vector<Emissions> qS_States_1000;
    vector<Emissions> qS_Zip_1000;
    vector<Emissions> qS_City_1000;
    vector<Emissions> qS_Amount_1000;



    /*======= Main Program Starts Here =======*/
    cout << "//==========Welcome to EmmissionSort!==========//" << endl;
    cout << endl;
    cout << "Select from one of the following years: " << endl
        << "1. 2019" << endl << "2. 2018" << endl;

    cout << endl;
    cout << "Year Option: ";
    cin >> year;

    /*======= Load data from main file(s) =======*/
    if (year == 1)
        readFile("Test2.csv", emissionData);
    else
        readFile("2018.csv", emissionData);

    /*======= Load data from main vectors into sub vectors depending on sizes =======*/

    for (int i = 0; i < 250; i++) {

        //Quick Sort Vectors
        qS_States_250.push_back(emissionData[i]);
        qS_Zip_250.push_back(emissionData[i]);
        qS_City_250.push_back(emissionData[i]);
        qS_Amount_250.push_back(emissionData[i]);

        //Heap Sort Vectors
        //Merge Sort Vectors
        //Shell Sort Vectors
    }

    for (int i = 0; i < 500; i++) {

        //Quick Sort Vectors
        qS_States_500.push_back(emissionData[i]);
        qS_Zip_500.push_back(emissionData[i]);
        qS_City_500.push_back(emissionData[i]);
        qS_Amount_500.push_back(emissionData[i]);


        //Heap Sort Vectors
        //Merge Sort Vectors
        //Shell Sort Vectors
    }

    for (int i = 0; i < 750; i++) {

        //Quick Sort Vectors
        qS_States_750.push_back(emissionData[i]);
        qS_Zip_750.push_back(emissionData[i]);
        qS_City_750.push_back(emissionData[i]);
        qS_Amount_750.push_back(emissionData[i]);

        //Heap Sort Vectors
        //Merge Sort Vectors
        //Shell Sort Vectors
    }

    for (int i = 0; i < 1000; i++) {

        //Quick Sort Vectors
        qS_States_1000.push_back(emissionData[i]);
        qS_Zip_1000.push_back(emissionData[i]);
        qS_City_1000.push_back(emissionData[i]);
        qS_Amount_1000.push_back(emissionData[i]);

        //Heap Sort Vectors
        //Merge Sort Vectors
        //Shell Sort Vectors
    }

    while (check == true) {

        /*======= Sorting Options =======*/
        cout << endl << "Sort By: " << endl
            << "1. State " << endl
            << "2. Zip Code" << endl
            << "3. City" << endl
            << "4. Emmisions Amount" << endl
            << "5. Exit" << endl;
        cout << endl;
        cout << "Sort Option: ";
        cin >> option;
        cout << endl;

        switch (option)
        {

            /*======= Case 1: Sorting by State =======*/
        case(1):
            cout << "//**********Sorting by State**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 250 ----------------//
            cout << "----------Sorting times for data size 250----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_250, 0, qS_States_250.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_250, "qS_States_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_500, 0, qS_States_500.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_500, "qS_States_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_750, 0, qS_States_750.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_750, "qS_States_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_1000, 0, qS_States_1000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_1000, "qS_States_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            break; //Must be after all of the sorting algorithms have been inserted here



            /*======= Case 2: Sorting by Zip Code =======*/


        case(2):

            cout << "//**********Sorting by Zip Code**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 250 ----------------//
            cout << "----------Sorting times for data size 250----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_250, 0, qS_Zip_250.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_250, "qS_Zip_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_500, 0, qS_Zip_500.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_500, "qS_Zip_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_750, 0, qS_Zip_750.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_750, "qS_Zip_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_1000, 0, qS_Zip_1000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_1000, "qS_Zip_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;


            break; //Must be after all of the sorting algorithms have been inserted here



            /*======= Case 3: Sorting by City =======*/
        case(3):
            cout << "//**********Sorting by City**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 250 ----------------//
            cout << "----------Sorting times for data size 250----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_250, 0, qS_City_250.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_250, "qS_City_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_500, 0, qS_City_500.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_500, "qS_City_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_750, 0, qS_City_750.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_750, "qS_City_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_1000, 0, qS_City_1000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_1000, "qS_City_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;


            break; //Must be after all of the sorting algorithms have been inserted here



            /*======= Case 4: Sorting by Emission Amount =======*/
        case(4):
            cout << "//**********Sorting by Emission Amount**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 250 ----------------//
            cout << "----------Sorting times for data size 250----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_250, 0, qS_Amount_250.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_250, "qS_Amount_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_500, 0, qS_Amount_500.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_500, "qS_Amount_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_750, 0, qS_Amount_750.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_750, "qS_Amount_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_1000, 0, qS_Amount_1000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_1000, "qS_Amount_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl; }
            cout << endl;


            break; //Must be after all of the sorting algorithms have been inserted here

        case(5):
            check = false;
            break;

        default:
            break;
        }
    }
}
