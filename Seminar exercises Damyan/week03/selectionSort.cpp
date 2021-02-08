#include <iostream>
using std::cout;
using std::cin;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void selectionSort(int arr[], size_t size) {
    for(size_t i = 0; i < size - 1; i++) {
        size_t minIndex = i;

        for(size_t j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main() {
    int arr[] = {4, 17, 23, 4, 7, 42, 7, -1};
    const size_t arrSize = sizeof(arr)/sizeof(int);
    
    selectionSort(arr, arrSize);
    printArray(arr, arrSize);
    
    return 0;
}
