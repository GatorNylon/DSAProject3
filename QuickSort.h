#pragma once
#include "Emissions.h"
using namespace std;

void swapValue(vector<Emissions>& emissionData, int a, int b) {
    Emissions temp = emissionData[a];
    emissionData[a] = emissionData[b];
    emissionData[b] = temp;
}


int partition(vector<Emissions>& emissionData, int low, int high, int type) {
    Emissions pivot = emissionData[low];
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (type == 1) {
                if (emissionData[up].getState().compare(pivot.getState()) > 0) {
                    break;
                }
                up++;
            }

            else if (type == 2) {
                if (emissionData[up].getZip().compare(pivot.getZip()) > 0) {
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
                if (emissionData[down].getState().compare(pivot.getState()) <= 0) {
                    break;
                }
                down--;
            }

            else if (type == 2) {
                if (emissionData[down].getZip().compare(pivot.getZip()) <= 0) {
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


void quickSort(vector<Emissions>& emissionData, int low, int high, int type) {
    if (low < high) {
        int pivotIndex = partition(emissionData, low, high, type);
        quickSort(emissionData, low, pivotIndex - 1, type);
        quickSort(emissionData, pivotIndex + 1, high, type);
    }
}