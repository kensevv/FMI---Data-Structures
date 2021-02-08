#include <iostream>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;

void printArray(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void mergeSortedArrays(int leftArr[], size_t leftSize, int rightArr[], size_t rightSize) { // leftSize + rightSize
    std::vector<int> sorted;
    size_t leftIndex = 0, rightIndex = 0;
    
    while(leftIndex < leftSize && rightIndex < rightSize) {
        if(leftArr[leftIndex] < rightArr[rightIndex]) {
            sorted.push_back(leftArr[leftIndex]);
            leftIndex++;
        } else {
            sorted.push_back(rightArr[rightIndex]);
            rightIndex++;
        }
    }

    for(;leftIndex < leftSize; leftIndex++) {
        sorted.push_back(leftArr[leftIndex]);
    }

    for(;rightIndex < rightSize; rightIndex++) {
        sorted.push_back(rightArr[rightIndex]);
    }

    for(size_t i = 0; i < leftSize; i++) {
        leftArr[i] = sorted[i];
    }

    for(size_t i = 0; i < rightSize; i++) {
        rightArr[i] = sorted[leftSize + i];
    }


}

void mergeSort(int arr[], size_t size) {
    if(size == 1) {
        return;
    }

    mergeSort(arr, size/2); 
    mergeSort(arr + size/2, size - size/2);
    mergeSortedArrays(arr, size/2, arr + size/2, size - size/2); // O(n)
}

int main() {
    int arr[] = {4, 17, 23, 4, 7, 42, 7, -1, 42};
    const size_t arrSize = sizeof(arr)/sizeof(int);
    
    mergeSort(arr, arrSize);
    printArray(arr, arrSize);
    
    return 0;
}
