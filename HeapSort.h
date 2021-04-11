#include <vector>
#include <math.h>
#include "Emissions.h"
using namespace std;

void removeHeap(vector<Emissions>&, int);
void printVec(vector<Emissions> arr, int left, int right) {
    for (int i = left; i < right + 1; i++)
        cout << arr[i].getZip() << " ";
    cout << endl;
}

void heapifyByState(vector<Emissions> &arr, int size, int curr) { // Heap Sort "Heapify" if the user decides to sort by state name.
    int left = (2 * curr) + 1; // The left child's index of the sub tree is found in the array with this calculation.
    int right = (2 * curr) + 2; // The right child's index of the sub tree is found in the array with this calculation.
    int max = curr;
    
    
    if (right < size && (arr[max].getState() < arr[right].getState())) max = right;
    if (left < size && (arr[max].getState() < arr[left].getState())) max = left;
    
    if (max != curr) {
        swap(arr[max], arr[curr]);
        heapifyByState(arr, size, max); // Heapify the current sub tree until the new max is the root.
    }
}

void heapifyByZip(vector<Emissions> &arr, int size, int curr) { // Heap Sort "Heapify" if the user decides to sort by zip code.
    int left = (2 * curr) + 1; // The left child's index of the sub tree is found in the array with this calculation.
    int right = (2 * curr) + 2; // The right child's index of the sub tree is found in the array with this calculation.
    int max = curr;
    
    
    if (right < size && (arr[max].getZip() < arr[right].getZip())) max = right;
    if (left < size && (arr[max].getZip() < arr[left].getZip())) max = left;
    
    if (max != curr) {
        swap(arr[max], arr[curr]);
        heapifyByZip(arr, size, max); // Heapify the current sub tree until the new max is the root.
    }
}

void heapifyByCity(vector<Emissions> &arr, int size, int curr) { // Heap Sort "Heapify" if the user decides to sort by city name.
    int left = (2 * curr) + 1; // The left child's index of the sub tree is found in the array with this calculation.
    int right = (2 * curr) + 2; // The right child's index of the sub tree is found in the array with this calculation.
    int max = curr;
    
    
    if (right < size && (arr[max].getCity() < arr[right].getCity())) max = right;
    if (left < size && (arr[max].getCity() < arr[left].getCity())) max = left;
    
    if (max != curr) {
        swap(arr[max], arr[curr]);
        heapifyByCity(arr, size, max); // Heapify the current sub tree until the new max is the root.
    }
}

void heapifyByEmmAmnt(vector<Emissions> &arr, int size, int curr) { // Heap Sort "Heapify" if the user decides to sort by emission release amount.
    int left = (2 * curr) + 1; // The left child's index of the sub tree is found in the array with this calculation.
    int right = (2 * curr) + 2; // The right child's index of the sub tree is found in the array with this calculation.
    int max = curr;
    
    if (right < size && (isgreater(arr[right].getTotalReleases(), arr[max].getTotalReleases()))) max = right;
    if (left < size && (isgreater(arr[left].getTotalReleases(), arr[max].getTotalReleases()))) max = left;
    
    if (max != curr) {
        swap(arr[max], arr[curr]);
        heapifyByEmmAmnt(arr, size, max); // Heapify the current sub tree until the new max is the root.
    }
}

void heapSort(vector<Emissions> &heap, int size, int type) {
    int buildHeapCounter = (size / 2) - 1;
    int sortCount = size - 1;
    switch (type) {
        case 1: // Sort by state name
            while (buildHeapCounter >= 0) { // Build a max heap
                heapifyByState(heap, size, buildHeapCounter);
                buildHeapCounter--;
            }
            
            while (sortCount > 0) {
                swap(heap[0], heap[sortCount]); // Swap the first and last element in the array (when the max element is at the heap root, add it to the end of the array, which sorts the array).
                heapifyByState(heap, sortCount, 0); // Build the new max heap once the root is removed in the swap above.
                sortCount--;
            }
            break;
        case 2: // Sort by zip code
            while (buildHeapCounter >= 0) { // Build a max heap
                heapifyByZip(heap, size, buildHeapCounter);
                buildHeapCounter--;
            }
            
            while (sortCount > 0) {
                swap(heap[0], heap[sortCount]); // Swap the first and last element in the array (when the max element is at the heap root, add it to the end of the array, which sorts the array).
                heapifyByZip(heap, sortCount, 0); // Build the new max heap once the root is removed in the swap above.
                sortCount--;
            }
            break;
        case 3: // Sort by city name
            while (buildHeapCounter >= 0) { // Build a max heap
                heapifyByCity(heap, size, buildHeapCounter);
                buildHeapCounter--;
            }
            
            while (sortCount > 0) {
                swap(heap[0], heap[sortCount]); // Swap the first and last element in the array (when the max element is at the heap root, add it to the end of the array, which sorts the array).
                heapifyByCity(heap, sortCount, 0); // Build the new max heap once the root is removed in the swap above.
                sortCount--;
            }
            break;
        case 4: // Sort by emission releases
            while (buildHeapCounter >= 0) { // Build a max heap
                heapifyByEmmAmnt(heap, size, buildHeapCounter);
                buildHeapCounter--;
            }
            
            while (sortCount > 0) {
                swap(heap[0], heap[sortCount]); // Swap the first and last element in the array (when the max element is at the heap root, add it to the end of the array, which sorts the array).
                heapifyByEmmAmnt(heap, sortCount, 0); // Build the new max heap once the root is removed in the swap above.
                sortCount--;
            }
            break;
    }
}
