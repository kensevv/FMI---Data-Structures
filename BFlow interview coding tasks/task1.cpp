// BFlow codings task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <map>

void findDublicates(std::string str, std::map<char, int>& map); // finds dublicates and inserts them into the given map container.
void printMapDublicates(const std::map<char, int>& map); // prints map container of dublicates correspondingly

int main()
{
	//Task 1 test code:
	std::string str = "ababccvvlllq";
	std::map<char, int> mapDublicates;
	findDublicates(str, mapDublicates);
	printMapDublicates(mapDublicates);
}

void findDublicates(std::string str, std::map<char, int>& map)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		char letter = str[i]; // take the curren letter
		size_t count = 1; // reset the count for each letter
		if (map.find(letter) != map.end() || letter == ' ') // Skip If we have already checked for that letter or its a white space
		{
			continue;
		}
		for (size_t j = i + 1; j < str.size(); j++) // iterate the rest of the string
		{
			if (str[j] == letter) count++;
		}

		if (count >= 2) map.insert(std::pair<char, int>(letter, count)); // add key-value to map container if the letter is seen more than 1 time
	}
}

void printMapDublicates(const std::map<char, int>& map)
{
	for (const auto& x : map) // using std::map<>::iterator
	{
		std::cout << "'" << x.first << "' occurs " << x.second << " times." << std::endl;
	}
}
