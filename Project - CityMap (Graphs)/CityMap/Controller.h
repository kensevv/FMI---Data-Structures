#pragma once
#include "Map.h"

class Controller
{
private:
	Map map;
	Node currentPosition;
	std::vector<Node> closedCrossRoads;
public:
	Controller(std::ifstream& in);

	const std::string& location();
	void changeLocation(const std::string& node);

	void hasPath(const std::string& destination);
	void threeShortestWays(const std::string& destination);
	void move(const std::string& node);
	void openCrossRoad(const std::string& node);
	void closeCrossRoad(const std::string& node);
	void closed();
	void tour(); // todo
};