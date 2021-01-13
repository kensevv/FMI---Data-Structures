// BFlow codings task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "position.h"

bool correctLine(std::string line, int x)
{
	if (line.size() != x) return false;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] != '1' && line[i] != '0') return false;
	}

	return true;
}

bool checkPositionInRange(position pos, int x, int y)
{
	return pos.x >= 0 && pos.y >= 0 &&
		pos.x <= x-1 && pos.y <= y-1;
}

int main()
{
	int x, y, x1, y1, N;
	std::cout << "x: "; std::cin >> x;
	std::cout << "y: "; std::cin >> y;
	if (x > y || y >= 1000) // check x y : x <= y < 1000
	{
		std::cout << "Not in range: x <= y < 1000" << std::endl;
		return 0;
	}
	std::vector<std::string> lines;
	for (size_t i = 0; i < y; i++)
	{
		std::string line;
		std::cout << "Line " << i << ":" << std::endl;
		std::cin >> line;
		if (!correctLine(line, x))
		{
			std::cout << "Wrong string input.";
			return 0;
		}
		lines.push_back(line);
	}
	std::cout << "x1: "; std::cin >> x1;
	std::cout << "y1: "; std::cin >> y1;
	position selectedPos{ x1,y1 };
	if (!checkPositionInRange(selectedPos, x, y)) {
		std::cout << "Position out of range";
		return 0;
	}
	std::cout << "N: "; std::cin >> N;
	Grid grid(lines, selectedPos, N);
	std::cout << grid.playGame();
}
