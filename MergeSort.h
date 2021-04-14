#include <algorithm>
#include <iterator>
using namespace std;

void merge(vector<Emissions> &arr, int left, int middle, int right, int type) {
    vector<Emissions> sorted; // Create a new vector that will hold the sorted values.
    
    int leftTemp = left;
    int rightTemp = middle + 1;
    int sortedTemp = 0;
    
    while (!(right < rightTemp) && !(middle < leftTemp)) {
        switch (type) {
            case 1:
                if (arr[rightTemp].getState() > arr[leftTemp].getState()) { // Check if the state name is "bigger" in the right subarray than the left subarray. Add to "sorted" array if it is.
                    sorted.push_back(arr[leftTemp]);
                    ++sortedTemp;
                    ++leftTemp;
                } else {
                    sorted.push_back(arr[rightTemp]);
                    ++sortedTemp;
                    ++rightTemp;
                }
                break;
            case 2:
                if (arr[rightTemp].getZip() > arr[leftTemp].getZip()) { // Check if the zip code is "bigger" in the right subarray than the left subarray. Add to "sorted" array if it is.
                    sorted.push_back(arr[leftTemp]);
                    ++sortedTemp;
                    ++leftTemp;
                } else {
                    sorted.push_back(arr[rightTemp]);
                    ++sortedTemp;
                    ++rightTemp;
                }
                break;
            case 3:
                if (arr[rightTemp].getCity() > arr[leftTemp].getCity()) { // Check if the city name is "bigger" in the right subarray than the left subarray. Add to "sorted" array if it is.
                    sorted.push_back(arr[leftTemp]);
                    ++sortedTemp;
                    ++leftTemp;
                } else {
                    sorted.push_back(arr[rightTemp]);
                    ++sortedTemp;
                    ++rightTemp;
                }
                break;
            case 4:
                if (isgreater(arr[rightTemp].getTotalReleases(), arr[leftTemp].getTotalReleases())) { // Check if the emissions released are "bigger" in the right subarray than the left subarray. Add to "sorted" array if it is.
                    sorted.push_back(arr[leftTemp]);
                    ++sortedTemp;
                    ++leftTemp;
                } else {
                    sorted.push_back(arr[rightTemp]);
                    ++sortedTemp;
                    ++rightTemp;
                }
                break;
        }
    }
    
    for (int i = leftTemp; i <= middle; i++) { // Whatever elements are left over in the left subarray, copy them over.
        sorted.push_back(arr[i]);
        sortedTemp++;
    }
    
    for (int j = rightTemp; j <= right; j++) { // Whatever elements are left over in the right subarray, copy them over.
        sorted.push_back(arr[j]);
        sortedTemp++;
    }
    
    while (!(right < left)) { // Add back to the original array the sorted values.
        sortedTemp--;
        arr[right] = sorted[sortedTemp];
        right--;
    }
}


void mergeSort(vector<Emissions> &arr, int left, int right, int type) {
    if (left >= right) {
        return;
    } else {
        int middle = (left + right) / 2; // Find the middle element in order to split the array in half recursively.
        mergeSort(arr, left, middle, type);
        mergeSort(arr, middle + 1, right, type);
        merge(arr, left, middle, right, type);
    }
}
