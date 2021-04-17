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


Emissions breakString(string line) {  //Helper Function that takes a line from the excel file, breaks it into the respective attributes, and pushes the data a vector object of type Emissions
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


void readFile(string FileName, vector<Emissions>& emissionData) { //Function to read a line from the excel file and sends it to the breakString Function for further processing
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

void writeFile(vector<Emissions>& sortedData, string filename) { //Function that writes the sorted data into files. File name is generated in main and is based on sorting algorithm name, sorting attribute and size
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
 //Total number of vectors used = 64

    /*======= Vector Declarations =======*/

    //Quick Sort for 1000 Size
    vector<Emissions> emissionData;
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

    //Quick Sort for 10000 Size
    vector<Emissions> qS_States_10000;
    vector<Emissions> qS_Zip_10000;
    vector<Emissions> qS_City_10000;
    vector<Emissions> qS_Amount_10000;

    vector<Emissions> heap_States_10000;
    vector<Emissions> heap_Zip_10000;
    vector<Emissions> heap_City_10000;
    vector<Emissions> heap_Amount_10000;

    vector<Emissions> merge_States_10000;
    vector<Emissions> merge_Zip_10000;
    vector<Emissions> merge_City_10000;
    vector<Emissions> merge_Amount_10000;

    vector<Emissions> shell_States_10000;
    vector<Emissions> shell_Zip_10000;
    vector<Emissions> shell_City_10000;
    vector<Emissions> shell_Amount_10000;

    //Quick Sort for 30000 Size
    vector<Emissions> qS_States_30000;
    vector<Emissions> qS_Zip_30000;
    vector<Emissions> qS_City_30000;
    vector<Emissions> qS_Amount_30000;

    vector<Emissions> heap_States_30000;
    vector<Emissions> heap_Zip_30000;
    vector<Emissions> heap_City_30000;
    vector<Emissions> heap_Amount_30000;

    vector<Emissions> merge_States_30000;
    vector<Emissions> merge_Zip_30000;
    vector<Emissions> merge_City_30000;
    vector<Emissions> merge_Amount_30000;

    vector<Emissions> shell_States_30000;
    vector<Emissions> shell_Zip_30000;
    vector<Emissions> shell_City_30000;
    vector<Emissions> shell_Amount_30000;

    //Quick Sort for FullSize Size
    vector<Emissions> qS_States_FullSize;
    vector<Emissions> qS_Zip_FullSize;
    vector<Emissions> qS_City_FullSize;
    vector<Emissions> qS_Amount_FullSize;

    vector<Emissions> heap_States_FullSize;
    vector<Emissions> heap_Zip_FullSize;
    vector<Emissions> heap_City_FullSize;
    vector<Emissions> heap_Amount_FullSize;

    vector<Emissions> merge_States_FullSize;
    vector<Emissions> merge_Zip_FullSize;
    vector<Emissions> merge_City_FullSize;
    vector<Emissions> merge_Amount_FullSize;

    vector<Emissions> shell_States_FullSize;
    vector<Emissions> shell_Zip_FullSize;
    vector<Emissions> shell_City_FullSize;
    vector<Emissions> shell_Amount_FullSize;



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

    for (int i = 0; i < 1000; i++) {

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

    for (int i = 0; i < 10000; i++) {

        //Quick Sort Vectors
        qS_States_10000.push_back(emissionData[i]);
        qS_Zip_10000.push_back(emissionData[i]);
        qS_City_10000.push_back(emissionData[i]);
        qS_Amount_10000.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_10000.push_back(emissionData[i]);
        heap_Zip_10000.push_back(emissionData[i]);
        heap_City_10000.push_back(emissionData[i]);
        heap_Amount_10000.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_10000.push_back(emissionData[i]);
        merge_Zip_10000.push_back(emissionData[i]);
        merge_City_10000.push_back(emissionData[i]);
        merge_Amount_10000.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_10000.push_back(emissionData[i]);
        shell_Zip_10000.push_back(emissionData[i]);
        shell_City_10000.push_back(emissionData[i]);
        shell_Amount_10000.push_back(emissionData[i]);

    }

    for (int i = 0; i < 30000; i++) {

        //Quick Sort Vectors
        qS_States_30000.push_back(emissionData[i]);
        qS_Zip_30000.push_back(emissionData[i]);
        qS_City_30000.push_back(emissionData[i]);
        qS_Amount_30000.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_30000.push_back(emissionData[i]);
        heap_Zip_30000.push_back(emissionData[i]);
        heap_City_30000.push_back(emissionData[i]);
        heap_Amount_30000.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_30000.push_back(emissionData[i]);
        merge_Zip_30000.push_back(emissionData[i]);
        merge_City_30000.push_back(emissionData[i]);
        merge_Amount_30000.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_30000.push_back(emissionData[i]);
        shell_Zip_30000.push_back(emissionData[i]);
        shell_City_30000.push_back(emissionData[i]);
        shell_Amount_30000.push_back(emissionData[i]);
    }

    for (int i = 0; i < emissionData.size(); i++) {

        //Quick Sort Vectors
        qS_States_FullSize.push_back(emissionData[i]);
        qS_Zip_FullSize.push_back(emissionData[i]);
        qS_City_FullSize.push_back(emissionData[i]);
        qS_Amount_FullSize.push_back(emissionData[i]);

        //Heap Sort Vectors
        heap_States_FullSize.push_back(emissionData[i]);
        heap_Zip_FullSize.push_back(emissionData[i]);
        heap_City_FullSize.push_back(emissionData[i]);
        heap_Amount_FullSize.push_back(emissionData[i]);

        //Merge Sort Vectors
        merge_States_FullSize.push_back(emissionData[i]);
        merge_Zip_FullSize.push_back(emissionData[i]);
        merge_City_FullSize.push_back(emissionData[i]);
        merge_Amount_FullSize.push_back(emissionData[i]);

        //Shell Sort Vectors
        shell_States_FullSize.push_back(emissionData[i]);
        shell_Zip_FullSize.push_back(emissionData[i]);
        shell_City_FullSize.push_back(emissionData[i]);
        shell_Amount_FullSize.push_back(emissionData[i]);
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

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_1000, 0, qS_States_1000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_1000, "qS_States_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(1000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_1000, heap_States_1000.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_States_1000, "heap_States_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(1000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_1000, 0, merge_States_1000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_States_1000, "merge_States_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(1000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_1000, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_States_1000, "shell_States_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(1000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 10000 ----------------//
            cout << "----------Sorting times for data size 10000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_10000, 0, qS_States_10000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_10000, "qS_States_10000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(10000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_10000, heap_States_10000.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_States_10000, "heap_States_10000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(10000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_10000, 0, merge_States_10000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_States_10000, "merge_States_10000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(10000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_10000, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_States_10000, "shell_States_10000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(10000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 30000 ----------------//
            cout << "----------Sorting times for data size 30000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_30000, 0, qS_States_30000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_30000, "qS_States_30000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_30000, heap_States_30000.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_States_30000, "heap_States_30000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_30000, 0, merge_States_30000.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_States_30000, "merge_States_30000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_30000, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_States_30000, "shell_States_30000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size FullSize ----------------//
            cout << "----------Sorting times for data size FullSize----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_States_FullSize, 0, qS_States_FullSize.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_States_FullSize, "qS_States_FullSize.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_States_FullSize, heap_States_FullSize.size(), 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_States_FullSize, "heap_States_FullSize.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_States_FullSize, 0, merge_States_FullSize.size() - 1, 1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_States_FullSize, "merge_States_FullSize.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_States_FullSize, lessThan_state);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_States_FullSize, "shell_States_FullSize.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;
            break; //Must be after all of the sorting algorithms have been inserted here


            /*======= Case 2: Sorting by Zip Code =======*/

        case(2):

            cout << "//**********Sorting by Zip Code**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_1000, 0, qS_Zip_1000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_1000, "qS_Zip_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(1000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_1000, heap_Zip_1000.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Zip_1000, "heap_Zip_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(1000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_1000, 0, merge_Zip_1000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_Zip_1000, "merge_Zip_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(1000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_1000, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Zip_1000, "shell_Zip_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(1000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 10000 ----------------//
            cout << "----------Sorting times for data size 10000----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_10000, 0, qS_Zip_10000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_10000, "qS_Zip_10000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(10000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_10000, heap_Zip_10000.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Zip_10000, "heap_Zip_10000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(10000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_10000, 0, merge_Zip_10000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_Zip_10000, "merge_Zip_10000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(10000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_10000, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Zip_10000, "shell_Zip_10000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(10000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;

            //---------Sorting times for data size 30000 ----------------//
            cout << "----------Sorting times for data size 30000----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_30000, 0, qS_Zip_30000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_30000, "qS_Zip_30000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_30000, heap_Zip_30000.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Zip_30000, "heap_Zip_30000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_30000, 0, merge_Zip_30000.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_Zip_30000, "merge_Zip_30000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_30000, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Zip_30000, "shell_Zip_30000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;

            //---------Sorting times for data size FullSize ----------------//
            cout << "----------Sorting times for data size FullSize----------" << endl;
            {auto start = high_resolution_clock::now();
            quickSort(qS_Zip_FullSize, 0, qS_Zip_FullSize.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Zip_FullSize, "qS_Zip_FullSize.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Zip_FullSize, heap_Zip_FullSize.size(), 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Zip_FullSize, "heap_Zip_FullSize.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_Zip_FullSize, 0, merge_Zip_FullSize.size() - 1, 2);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_Zip_FullSize, "merge_Zip_FullSize.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Zip_FullSize, lessThan_zipCode);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Zip_FullSize, "shell_Zip_FullSize.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;
            break; //Must be after all of the sorting algorithms have been inserted here


            /*======= Case 3: Sorting by City =======*/

        case(3):

            cout << "//**********Sorting by City**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_1000, 0, qS_City_1000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_1000, "qS_City_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(1000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_1000, heap_City_1000.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_City_1000, "heap_City_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(1000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_1000, 0, merge_City_1000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_1000, "merge_City_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(1000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_1000, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_City_1000, "shell_City_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(1000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 10000 ----------------//
            cout << "----------Sorting times for data size 10000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_10000, 0, qS_City_10000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_10000, "qS_City_10000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(10000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_10000, heap_City_10000.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_City_10000, "heap_City_10000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(10000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_10000, 0, merge_City_10000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_10000, "merge_City_10000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(10000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_10000, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_City_10000, "shell_City_10000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(10000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;

            //---------Sorting times for data size 30000 ----------------//
            cout << "----------Sorting times for data size 30000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_30000, 0, qS_City_30000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_30000, "qS_City_30000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_30000, heap_City_30000.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_City_30000, "heap_City_30000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_30000, 0, merge_City_30000.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_30000, "merge_City_30000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_30000, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_City_30000, "shell_City_30000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }
            cout << endl;

            //---------Sorting times for data size FullSize ----------------//
            cout << "----------Sorting times for data size FullSize----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_City_FullSize, 0, qS_City_FullSize.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_City_FullSize, "qS_City_FullSize.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_City_FullSize, heap_City_FullSize.size(), 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_City_FullSize, "heap_City_FullSize.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_FullSize, 0, merge_City_FullSize.size() - 1, 3);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_FullSize, "merge_City_FullSize.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_City_FullSize, lessThan_City);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_City_FullSize, "shell_City_FullSize.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(emissionData.size());
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;
            break; //Must be after all of the sorting algorithms have been inserted here


            /*======= Case 4: Sorting by Emission Amount =======*/

        case(4):

            cout << "//**********Sorting by Emission Amount**********//" << endl;
            cout << endl;

            //---------Sorting times for data size 1000 ----------------//
            cout << "----------Sorting times for data size 1000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_1000, 0, qS_Amount_1000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_1000, "qS_Amount_1000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(1000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_1000, heap_Amount_1000.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Amount_1000, "heap_Amount_1000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(1000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_1000, 0, merge_City_1000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_1000, "merge_City_1000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(1000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_1000, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Amount_1000, "shell_Amount_1000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(1000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 10000 ----------------//
            cout << "----------Sorting times for data size 10000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_10000, 0, qS_Amount_10000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_10000, "qS_Amount_10000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(10000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_10000, heap_Amount_10000.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Amount_10000, "heap_Amount_10000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(10000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_10000, 0, merge_City_10000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_10000, "merge_City_10000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(10000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_10000, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Amount_10000, "shell_Amount_10000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(10000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size 30000 ----------------//
            cout << "----------Sorting times for data size 30000----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_30000, 0, qS_Amount_30000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_30000, "qS_Amount_30000.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(30000);
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_30000, heap_Amount_30000.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Amount_30000, "heap_Amount_30000.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(30000);
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_30000, 0, merge_City_30000.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_30000, "merge_City_30000.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(30000);
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_30000, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Amount_30000, "shell_Amount_30000.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
            yNumDataShellSort.push_back(30000);
            xTimeTakenShellSort.push_back(duration.count());
            }

            cout << endl;

            //---------Sorting times for data size FullSize ----------------//
            cout << "----------Sorting times for data size " << emissionData.size() << "----------" << endl;

            {auto start = high_resolution_clock::now();
            quickSort(qS_Amount_FullSize, 0, qS_Amount_FullSize.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(qS_Amount_FullSize, "qS_Amount_FullSize.csv");
            cout << "1. Quick Sort: " << duration.count() << " microseconds" << endl;
            yNumDataQuickSort.push_back(emissionData.size());
            xTimeTakenQuickSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            heapSort(heap_Amount_FullSize, heap_Amount_FullSize.size(), 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(heap_Amount_FullSize, "heap_Amount_FullSize.csv");
            cout << "2. Heap Sort: " << duration.count() << " microseconds" << endl;
            yNumDataHeapSort.push_back(emissionData.size());
            xTimeTakenHeapSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            mergeSort(merge_City_FullSize, 0, merge_City_FullSize.size() - 1, 4);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(merge_City_FullSize, "merge_City_FullSize.csv");
            cout << "3. Merge Sort: " << duration.count() << " microseconds" << endl;
            yNumDataMergeSort.push_back(emissionData.size());
            xTimeTakenMergeSort.push_back(duration.count());
            }

            {auto start = high_resolution_clock::now();
            Shellsort(shell_Amount_FullSize, lessThan_totalRelease);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            writeFile(shell_Amount_FullSize, "shell_Amount_FullSize.csv");
            cout << "4. Shell Sort: " << duration.count() << " microseconds" << endl;
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

        if (option < 5 && option > 0) { //Implementation of Graph Functionality
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
            plt::xlabel("Data Size");
            plt::ylabel("Time (microseconds)");
            plt::save(nameFile);
            plt::show();
        }

    }
}