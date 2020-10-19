#include <iostream>
#include <vector>

template<class T>
void bubbleSort(std::vector<T>& container)
{
    size_t size = container.size();

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (container[j] > container[j + 1]) std::swap(container[j], container[j + 1]);
        }
    }
}

template<class T>
void selectiveSort(std::vector<T>& container)
{
    size_t size = container.size();

    for (size_t i = 0; i < size - 1; i++)
    {
        int minIdex = i;

        for (size_t j = i; j < size - 1; j++)
        {
            if (container[j] < container[minIdex]) minIdex = j;
        }
        std::swap(container[i], container[minIdex]);
    }
}


template<class T>
void mergeSortedArrays(std::vector<T>& leftArr, std::vector<T>& rightArr, std::vector<T>& arr)
{
    size_t leftSize = leftArr.size();
    size_t rightSize = rightArr.size();

    size_t leftIndex = 0;
    size_t rightIndex = 0;
    size_t k = 0;

    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[k] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[k] = rightArr[rightIndex];
            rightIndex++;
        }
        k++;
    }

    while (leftIndex < leftSize)
    {
        arr[k] = leftArr[leftIndex];
        leftIndex++; k++;
    }

    while (rightIndex < rightSize)
    {
        arr[k] = rightArr[rightIndex];
        rightIndex++; k++;
    }
}

template<class T>
void mergeSort(std::vector<T>& arr)
{
    size_t size = arr.size();

    if (size == 1) return;

    std::vector<T> leftArr;
    std::vector<T> rightArr;
    
    for (size_t i = 0; i < size/2; i++)
    {
        leftArr.push_back(arr[i]);
    }
    
    for (size_t i = 0; i < size - size/2; i++)
    {
        rightArr.push_back(arr[ size / 2 + i]);
    }

    mergeSort(leftArr);
    mergeSort(rightArr);
    mergeSortedArrays(leftArr, rightArr, arr);
}

int main()
{
    std::vector<int> arr;

    arr.push_back(9); arr.push_back(1); arr.push_back(6); 
    arr.push_back(7); arr.push_back(2); arr.push_back(5); 
    arr.push_back(4); arr.push_back(3); arr.push_back(8);

    //bubbleSort(arr);

    //selectiveSort(arr);

    //mergeSort(arr);
    
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}