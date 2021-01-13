#pragma once
#include <string>
#include <vector>
#include "position.h"

class Grid
{
private:
	int columns;
	int rows;
	position selectedPosition;
	int N;
	std::vector<std::vector<int>> grid;
public:
	Grid(std::vector<std::string> lines, const position& selectedPosition, int N);
	
	const std::vector<std::vector<int>>& getGrid() const;
	void printGrid();
	bool selectedPositionIsPurple();
	bool positionIsInRage(const position& pos);
	
	int playGame();
	void nextGeneration();
	int countSurroudings(position currPos, int neighbours); // counts surroudings that are 0 or 1, defined by int neighbours
	void if0CellChanges(position, std::vector<std::vector<int>>&);
	void if1CellChanges(position, std::vector<std::vector<int>>&);
};