#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <fstream>

// Realizing graph with Adjacency lists

struct Node
{
	std::string location;
	int nodeID;
	bool operator==(const Node& other) const;

	Node(const std::string& data, const int ID);
	Node();
};

class Map
{
private:
	unsigned int size;
	unsigned int currID;
	std::vector<std::list<std::pair<Node,int>>> graphAdjacent; // pair - node, distance

	Node findNode(const std::string& location);
public:
	Map(size_t size);
	Map(std::ifstream& in);
	Node addNode(const std::string& location);
	void addEdge(const Node& source, const Node& destination, int distance);

	void updateMapFile(std::ofstream& out);

	bool hasPath(const std::string& start, const std::string& end);
};
