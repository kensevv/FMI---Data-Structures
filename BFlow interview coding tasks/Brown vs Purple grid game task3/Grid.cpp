#include "Grid.h"
#include <iostream>

Grid::Grid(std::vector<std::string> lines, const position& selectedPosition, int N)
{
	this->columns = lines[0].size();
	this->rows = lines.size();
	this->selectedPosition = selectedPosition;
	this->N = N;

	//resize the matrix
	grid.resize(rows);
	for (size_t i = 0; i < grid.size(); i++)
	{
		grid[i].resize(columns);
	}

	//parse the strings -> fill the matrix
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			this->grid[j][i] = lines[i][j] - '0';
		}
	}
}

const std::vector<std::vector<int>>& Grid::getGrid() const
{
	return this->grid;
}

void Grid::printGrid()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			std::cout << this->grid[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

bool Grid::selectedPositionIsPurple()
{
	if (this->grid[this->selectedPosition.x][this->selectedPosition.y] == 1) return true;
	else return false;
}

bool Grid::positionIsInRage(const position& pos)
{
	return pos.x >= 0 &&
		pos.y >= 0 &&
		pos.x < columns&&
		pos.y < rows;
}

int Grid::playGame()
{
	int result = 0;
	for (size_t i = 0; i < this->N; i++)
	{
		if (selectedPositionIsPurple()) result++;
		nextGeneration();
	}
	if (selectedPositionIsPurple()) result++;
	return result;
}

void Grid::nextGeneration()
{
	std::vector<std::vector<int>> newFormedGrid;
	newFormedGrid.resize(rows);
	for (size_t i = 0; i < newFormedGrid.size(); i++)
	{
		newFormedGrid[i].resize(columns);
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (this->grid[j][i] == 0)
			{
				if0CellChanges(position{j,i}, newFormedGrid);
			}
			else
			{
				if1CellChanges(position{j,i}, newFormedGrid);
			}
		}
	}
	
	this->grid = newFormedGrid;
}

int Grid::countSurroudings(position currPos, int neighbours)
{
	int surroundings = 0;
	if (positionIsInRage(currPos.right()))
	{
		if (this->grid[currPos.right().x][currPos.right().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.down()))
	{
		if (this->grid[currPos.down().x][currPos.down().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.left()))
	{
		if (this->grid[currPos.left().x][currPos.left().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.up()))
	{
		if (this->grid[currPos.up().x][currPos.up().y] == neighbours) surroundings++;
	}
	//diagonals
	if (positionIsInRage(currPos.rightup()))
	{
		if (this->grid[currPos.rightup().x][currPos.rightup().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.rightdown()))
	{
		if (this->grid[currPos.rightdown().x][currPos.rightdown().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.leftup()))
	{
		if (this->grid[currPos.leftup().x][currPos.leftup().y] == neighbours) surroundings++;
	}
	if (positionIsInRage(currPos.leftdown()))
	{
		if (this->grid[currPos.leftdown().x][currPos.leftdown().y] == neighbours) surroundings++;
	}
	return surroundings;
}

void Grid::if0CellChanges(position currPos, std::vector<std::vector<int>>& newFormedGrid)
{

	int surrounding1s = countSurroudings(currPos, 1);
	
	if (surrounding1s == 3 || surrounding1s == 6)
	{
		newFormedGrid[currPos.x][currPos.y] = 1;
	}
	else
	{
		newFormedGrid[currPos.x][currPos.y] = 0;
	}
}

void Grid::if1CellChanges(position currPos, std::vector<std::vector<int>>& newFormedGrid)
{
	int surrounding1s = countSurroudings(currPos, 1);

	if (surrounding1s != 2 && surrounding1s != 3 && surrounding1s != 6)
	{
		newFormedGrid[currPos.x][currPos.y] = 0;
	}
	else {
		newFormedGrid[currPos.x][currPos.y] = 1;
	}
}
