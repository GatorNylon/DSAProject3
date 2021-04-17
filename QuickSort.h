#pragma once
#include "Emissions.h"
using namespace std;
//Used the sorting Lecture slide for Quick Sort as a reference

void swapValue(vector<Emissions>& emissionData, int a, int b) { //Helper function that helps swap the Emission data nodes
    Emissions temp = emissionData[a];
    emissionData[a] = emissionData[b];
    emissionData[b] = temp;
}


int partition(vector<Emissions>& emissionData, int low, int high, int type) { //Function that has main implementation of quicksort
    Emissions pivot = emissionData[low]; //Choosing pivot as the first index
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (type == 1) { //type is based on the sorting attribute that is set in the main.cpp
                if (emissionData[up].getState().compare(pivot.getState()) > 0) { //Compare function returns 1 for if it is greater
                    break;
                }
                up++;
            }

            else if (type == 2) {
                if (emissionData[up].getZip() > pivot.getZip()) {
                    break;
                }
                up++;
            }

            else if (type == 3) {
                if (emissionData[up].getCity().compare(pivot.getCity()) > 0) {
                    break;
                }
                up++;
            }

            else {
                if (emissionData[up].getTotalReleases() > pivot.getTotalReleases()) {
                    break;
                }
                up++;
            }
        }

        for (int j = high; j > low; j--) {
            if (type == 1) {
                if (emissionData[down].getState().compare(pivot.getState()) <= 0) { //Compare function returns 0 or -1 for if it is less than or equal to the value being compared to. Using <= ensures that duplicates can be handled as well
                    break;
                }
                down--;
            }

            else if (type == 2) {
                if (emissionData[down].getZip() <= pivot.getZip()) {
                    break;
                }
                down--;
            }

            else if (type == 3) {
                if (emissionData[down].getCity().compare(pivot.getCity()) <= 0) {
                    break;
                }
                down--;
            }

            else {
                if (emissionData[down].getTotalReleases() <= pivot.getTotalReleases()) {
                    break;
                }
                down--;
            }
        }

        if (up < down) {
            swapValue(emissionData, up, down);
        }
    }
    swapValue(emissionData, low, down);
    return down;
}


void quickSort(vector<Emissions>& emissionData, int low, int high, int type) { //Main recursive function 
    if (low < high) {
        int pivotIndex = partition(emissionData, low, high, type); //Helper function that helps choose pivot after every partition
        quickSort(emissionData, low, pivotIndex - 1, type); //Recursively apply quicksort to indexes from the start to less than the pivot
        quickSort(emissionData, pivotIndex + 1, high, type); ////Recursively apply quicksort to indexes from the pivot to end of the vector
    }
}
