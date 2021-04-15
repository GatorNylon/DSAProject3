#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <chrono>
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "Emissions.h"
#include "ShellSort.h"
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
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

    vector<Emissions> heap_States_250;
    vector<Emissions> heap_Zip_250;
    vector<Emissions> heap_City_250;
    vector<Emissions> heap_Amount_250;

    vector<Emissions> merge_States_250;
    vector<Emissions> merge_Zip_250;
    vector<Emissions> merge_City_250;
    vector<Emissions> merge_Amount_250;

    vector<Emissions> shell_States_250;
    vector<Emissions> shell_Zip_250;
    vector<Emissions> shell_City_250;
    vector<Emissions> shell_Amount_250;

    //Quick Sort for 500 Size
    vector<Emissions> qS_States_500;
    vector<Emissions> qS_Zip_500;
    vector<Emissions> qS_City_500;
    vector<Emissions> qS_Amount_500;

    vector<Emissions> heap_States_500;
    vector<Emissions> heap_Zip_500;
    vector<Emissions> heap_City_500;
    vector<Emissions> heap_Amount_500;

    vector<Emissions> merge_States_500;
    vector<Emissions> merge_Zip_500;
    vector<Emissions> merge_City_500;
    vector<Emissions> merge_Amount_500;

    vector<Emissions> shell_States_500;
    vector<Emissions> shell_Zip_500;
    vector<Emissions> shell_City_500;
    vector<Emissions> shell_Amount_500;

    //Quick Sort for 750 Size
    vector<Emissions> qS_States_750;
    vector<Emissions> qS_Zip_750;
    vector<Emissions> qS_City_750;
    vector<Emissions> qS_Amount_750;

    vector<Emissions> heap_States_750;
    vector<Emissions> heap_Zip_750;
    vector<Emissions> heap_City_750;
    vector<Emissions> heap_Amount_750;

    vector<Emissions> merge_States_750;
    vector<Emissions> merge_Zip_750;
    vector<Emissions> merge_City_750;
    vector<Emissions> merge_Amount_750;

    vector<Emissions> shell_States_750;
    vector<Emissions> shell_Zip_750;
    vector<Emissions> shell_City_750;
    vector<Emissions> shell_Amount_750;

    //Quick Sort for 1000 Size
    vector<Emissions> qS_States_1000;
    vector<Emissions> qS_Zip_1000;
    vector<Emissions> qS_City_1000;
    vector<Emissions> qS_Amount_1000;

    vector<Emissions> heap_States_1000;
    vector<Emissions> heap_Zip_1000;
    vector<Emissions> heap_City_1000;
    vector<Emissions> heap_Amount_1000;

    vector<Emissions> merge_States_1000;
    vector<Emissions> merge_Zip_1000;
    vector<Emissions> merge_City_1000;
    vector<Emissions> merge_Amount_1000;

    vector<Emissions> shell_States_1000;
    vector<Emissions> shell_Zip_1000;
    vector<Emissions> shell_City_1000;
    vector<Emissions> shell_Amount_1000;



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
        readFile("2019.csv", emissionData);
    else
        readFile("2018.csv", emissionData);

    /*======= Load data from main vectors into sub vectors depending on sizes =======*/

    for (int i = 0; i < 5000; i++) {

        //Quick Sort Vectors
        qS_States_250.push_back(emissionData[i]);
        qS_Zip_250.push_back(emissionData[i]);
        qS_City_250.push_back(emissionData[i]);
        qS_Amount_250.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_250.push_back(emissionData[i]);
        heap_Zip_250.push_back(emissionData[i]);
        heap_City_250.push_back(emissionData[i]);
        heap_Amount_250.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_250.push_back(emissionData[i]);
        merge_Zip_250.push_back(emissionData[i]);
        merge_City_250.push_back(emissionData[i]);
        merge_Amount_250.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_250.push_back(emissionData[i]);
        shell_Zip_250.push_back(emissionData[i]);
        shell_City_250.push_back(emissionData[i]);
        shell_Amount_250.push_back(emissionData[i]);
    }

    for (int i = 0; i < 15000; i++) {

        //Quick Sort Vectors
        qS_States_500.push_back(emissionData[i]);
        qS_Zip_500.push_back(emissionData[i]);
        qS_City_500.push_back(emissionData[i]);
        qS_Amount_500.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_500.push_back(emissionData[i]);
        heap_Zip_500.push_back(emissionData[i]);
        heap_City_500.push_back(emissionData[i]);
        heap_Amount_500.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_500.push_back(emissionData[i]);
        merge_Zip_500.push_back(emissionData[i]);
        merge_City_500.push_back(emissionData[i]);
        merge_Amount_500.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_500.push_back(emissionData[i]);
        shell_Zip_500.push_back(emissionData[i]);
        shell_City_500.push_back(emissionData[i]);
        shell_Amount_500.push_back(emissionData[i]);

    }

    for (int i = 0; i < 30000; i++) {

        //Quick Sort Vectors
        qS_States_750.push_back(emissionData[i]);
        qS_Zip_750.push_back(emissionData[i]);
        qS_City_750.push_back(emissionData[i]);
        qS_Amount_750.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_750.push_back(emissionData[i]);
        heap_Zip_750.push_back(emissionData[i]);
        heap_City_750.push_back(emissionData[i]);
        heap_Amount_750.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_750.push_back(emissionData[i]);
        merge_Zip_750.push_back(emissionData[i]);
        merge_City_750.push_back(emissionData[i]);
        merge_Amount_750.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_750.push_back(emissionData[i]);
        shell_Zip_750.push_back(emissionData[i]);
        shell_City_750.push_back(emissionData[i]);
        shell_Amount_750.push_back(emissionData[i]);
    }

    for (int i = 0; i < emissionData.size(); i++) {

        //Quick Sort Vectors
        qS_States_1000.push_back(emissionData[i]);
        qS_Zip_1000.push_back(emissionData[i]);
        qS_City_1000.push_back(emissionData[i]);
        qS_Amount_1000.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_1000.push_back(emissionData[i]);
        heap_Zip_1000.push_back(emissionData[i]);
        heap_City_1000.push_back(emissionData[i]);
        heap_Amount_1000.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_1000.push_back(emissionData[i]);
        merge_Zip_1000.push_back(emissionData[i]);
        merge_City_1000.push_back(emissionData[i]);
        merge_Amount_1000.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_1000.push_back(emissionData[i]);
        shell_Zip_1000.push_back(emissionData[i]);
        shell_City_1000.push_back(emissionData[i]);
        shell_Amount_1000.push_back(emissionData[i]);
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

        /*====== Data Point Vectors ======*/
        vector<int> yNumDataQuickSort;
        vector<int> xTimeTakenQuickSort;

        vector<int> yNumDataHeapSort;
        vector<int> xTimeTakenHeapSort;

        vector<int> yNumDataMergeSort;
        vector<int> xTimeTakenMergeSort;

        vector<int> yNumDataShellSort;
        vector<int> xTimeTakenShellSort;

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
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_States_250, "qS_States_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(250);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_250, heap_States_250.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_States_250, "heap_States_250.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(250);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_250, 0, merge_States_250.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_States_250, "merge_States_250.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(250);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_250, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_States_250, "shell_States_250.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(250);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_500, 0, qS_States_500.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_States_500, "qS_States_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(15000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_500, heap_States_500.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_States_500, "heap_States_500.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(15000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_500, 0, merge_States_500.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_States_500, "merge_States_500.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(15000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_500, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_States_500, "shell_States_500.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(15000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_750, 0, qS_States_750.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_States_750, "qS_States_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_750, heap_States_750.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_States_750, "heap_States_750.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_750, 0, merge_States_750.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_States_750, "merge_States_750.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_750, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_States_750, "shell_States_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_1000, 0, qS_States_1000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_States_1000, "qS_States_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_1000, heap_States_1000.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_States_1000, "heap_States_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_1000, 0, merge_States_1000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_States_1000, "merge_States_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_1000, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_States_1000, "shell_States_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }
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
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Zip_250, "qS_Zip_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(250);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_250, heap_Zip_250.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Zip_250, "heap_Zip_250.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(250);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_250, 0, merge_Zip_250.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_Zip_250, "merge_Zip_250.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(250);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_250, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Zip_250, "shell_Zip_250.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(250);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;
            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_500, 0, qS_Zip_500.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Zip_500, "qS_Zip_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(15000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_500, heap_Zip_500.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Zip_500, "heap_Zip_500.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(15000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_500, 0, merge_Zip_500.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_Zip_500, "merge_Zip_500.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(15000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_500, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Zip_500, "shell_Zip_500.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(15000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_750, 0, qS_Zip_750.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Zip_750, "qS_Zip_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_750, heap_Zip_750.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Zip_750, "heap_Zip_750.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_750, 0, merge_Zip_750.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_Zip_750, "merge_Zip_750.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_750, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Zip_750, "shell_Zip_750.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;
            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_1000, 0, qS_Zip_1000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Zip_1000, "qS_Zip_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_1000, heap_Zip_1000.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Zip_1000, "heap_Zip_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_1000, 0, merge_Zip_1000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_Zip_1000, "merge_Zip_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_1000, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Zip_1000, "shell_Zip_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }

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
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_City_250, "qS_City_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(250);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_250, heap_City_250.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_City_250, "heap_City_250.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(250);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_250, 0, merge_City_250.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_250, "merge_City_250.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(250);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_250, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_City_250, "shell_City_250.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(250);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_500, 0, qS_City_500.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_City_500, "qS_City_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(15000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_500, heap_City_500.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_City_500, "heap_City_500.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(15000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_500, 0, merge_City_500.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_500, "merge_City_500.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(15000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_500, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_City_500, "shell_City_500.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(15000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;
            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_750, 0, qS_City_750.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_City_750, "qS_City_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_750, heap_City_750.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_City_750, "heap_City_750.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_750, 0, merge_City_750.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_750, "merge_City_750.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_750, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_City_750, "shell_City_750.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;
            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_1000, 0, qS_City_1000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_City_1000, "qS_City_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_1000, heap_City_1000.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_City_1000, "heap_City_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_1000, 0, merge_City_1000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_1000, "merge_City_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_1000, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_City_1000, "shell_City_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }

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
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Amount_250, "qS_Amount_250.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(250);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_250, heap_Amount_250.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Amount_250, "heap_Amount_250.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(250);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_250, 0, merge_City_250.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_250, "merge_City_250.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(250);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_250, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Amount_250, "shell_Amount_250.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(250);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 500 ----------------//
            cout << "----------Sorting times for data size 500----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_500, 0, qS_Amount_500.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Amount_500, "qS_Amount_500.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(15000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_500, heap_Amount_500.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Amount_500, "heap_Amount_500.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(15000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_500, 0, merge_City_500.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_500, "merge_City_500.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(15000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_500, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Amount_500, "shell_Amount_500.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(15000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 750 ----------------//
            cout << "----------Sorting times for data size 750----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_750, 0, qS_Amount_750.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Amount_750, "qS_Amount_750.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_750, heap_Amount_750.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Amount_750, "heap_Amount_750.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_750, 0, merge_City_750.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_750, "merge_City_750.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_750, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Amount_750, "shell_Amount_750.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_1000, 0, qS_Amount_1000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(qS_Amount_1000, "qS_Amount_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_1000, heap_Amount_1000.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(heap_Amount_1000, "heap_Amount_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_1000, 0, merge_City_1000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(merge_City_1000, "merge_City_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_1000, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            writeFile(shell_Amount_1000, "shell_Amount_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " milliseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;


            break; //Must be after all of the sorting algorithms have been inserted here

        case(5):
            check = false;
            break;
            return 0;
        default:
            break;
        }

        if (option < 5 && option > 0) {
            plt::plot(yNumDataQuickSort, xTimeTakenQuickSort);
            plt::named_plot("Quick Sort", yNumDataQuickSort, xTimeTakenQuickSort);
            plt::plot(yNumDataHeapSort, xTimeTakenHeapSort, "b-");
            plt::named_plot("Heap Sort", yNumDataHeapSort, xTimeTakenHeapSort, "b-");
            plt::plot(yNumDataMergeSort, xTimeTakenMergeSort);
            plt::named_plot("Merge Sort", yNumDataMergeSort, xTimeTakenMergeSort);
            plt::plot(yNumDataShellSort, xTimeTakenShellSort, "g-");
            plt::named_plot("Shell Sort", yNumDataShellSort, xTimeTakenShellSort, "g-");
            plt::legend();
            string nameOfTest;
            string nameFile;
            switch (option) {
            case 1:
                nameOfTest = "Sort by State Name";
                nameFile = "StateSortGraph.png";
                break;
            case 2:
                nameOfTest = "Sort by Zip Code";
                nameFile = "ZipSortGraph.png";
                break;
            case 3:
                nameOfTest = "Sort by City Name";
                nameFile = "CitySortGraph.png";
                break;
            case 4:
                nameOfTest = "Sort by Emissions Amount";
                nameFile = "EmissionsSortGraph.png";
                break;
            }
            plt::title("Emissions Sort - " + nameOfTest);
            plt::save(nameFile);
            plt::show();
        }

    }
}