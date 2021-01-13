// BFlow codings task2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

bool isSubsequence(int firstArr[], int firstSize, int secondArr[], int secondSize, bool adjacent = false); // by default the adjacent modifier is set to false, if its given as true then it applies.

int main()
{
	//can aswell easily be implemented with vectors instead of arrays
	int arr1[] = { 1,2,3,4, 1,6,1,2,5,6,7,1 };
	int arr2[] = { 1,6,1,2,5,6,1 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	std::cout << isSubsequence(arr1, size1, arr2, size2); // give adjacent modifier as bool as additional parameter to turn it on;
}

bool isSubsequence(int firstArr[], int firstSize, int secondArr[], int secondSize, bool adjacent)
{
	int firstArrayIndex = 0;

	for (size_t i = 0; i < secondSize; i++)
	{
		bool found = false;
		for (size_t j = firstArrayIndex; j < firstSize; j++)
		{
			if (secondArr[i] == firstArr[j])
			{
				if (adjacent == true)
				{
					if (j != firstArrayIndex) return false;
				}
				found = true;
				firstArrayIndex = j + 1; // the main array will continue from the next index that follows the found int
				break; // breaking to stop at the first found.
			}
		}
		if (found == false) return false;
	}
	return true;
}