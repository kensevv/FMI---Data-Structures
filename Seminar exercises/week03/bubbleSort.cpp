#include <iostream>
// #include <cstddef>
using std::cout;
using std::cin;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], size_t size) {
    for(size_t i = 0; i < size - 1; ++i) {
        for(size_t j = 0; j < size - i - 1; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main() {
    
    int arr[] = {4, 17, 23, 4, 7, 42, 7, -1};
    const size_t arrSize = sizeof(arr)/sizeof(int);
    
    bubbleSort(arr, arrSize);
    printArray(arr, arrSize);
    
    return 0;
}   
