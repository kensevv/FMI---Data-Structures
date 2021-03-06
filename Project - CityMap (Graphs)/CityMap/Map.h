#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <fstream>

// Realizing graph with Adjacency lists containing pairs to carry the Nodes and the distance between each node
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
	
	bool pathIsNotVisited(const std::pair<Node,int>& pair, const std::vector<std::pair<Node, int>>& path);
	const std::vector<std::pair<Node, int>>& shorterPath(const std::vector<std::pair<Node, int>>& one, const std::vector<std::pair<Node, int>>& two);
	void sortAllPathsByDistance(std::vector<std::vector<std::pair<Node, int>>>& allpaths);
	int calculatePathDistance(const std::vector<std::pair<Node, int>>& path);
public:
	Map(std::ifstream& in);
	Node addNode(const std::string& location);
	void addEdge(const Node& source, const Node& destination, int distance);
	Node findNode(const std::string& location);
	void updateMapFile(std::ofstream& out);

	bool hasPath(const std::string& start, const std::string& end, const std::vector<Node>& closedNodes = {});
	
	std::vector<std::vector<Node>> ThreeShortestWays(const std::string& start, const std::string& end, const std::vector<Node>& closedNodes = {});

	//for doctest purposes
	const unsigned int getSize()const;
	const unsigned int getCurrID()const;
	const std::vector<std::list<std::pair<Node, int>>>& getGraphAdjacent() const;
};