#include "Map.h"
#include <sstream>
#include <map>

inline bool Node::operator==(const Node& other) const
{
	return this->location == other.location && this->nodeID == other.nodeID;
}

Node::Node(const std::string& location, const int ID) : location(location), nodeID(ID){}

Node::Node(){}

Node Map::findNode(const std::string& location)
{
	for (const auto& list : this->graphAdjacent)
	{
		if (!list.empty())
		{
			if (list.front().first.location == location)
			{
				return list.front().first;
			}
		}
		
	}
	Node defaultNode("", -1);
	return defaultNode;
}

bool Map::pathIsNotVisited(const std::pair<Node, int>& pair, const std::vector<std::pair<Node, int>>& path)
{
	for (const auto& pairs : path)
	{
		if (pair.first == pairs.first)
		{
			return false;
		}
	}
	return true;
}

const std::vector<std::pair<Node, int>>& Map::shorterPath(const std::vector<std::pair<Node, int>>& one, const std::vector<std::pair<Node, int>>& two)
{
	size_t distanceOne = 0;
	size_t distanceTwo = 0;
	for (const auto& pair : one) distanceOne += pair.second;
	for (const auto& pair : two) distanceTwo += pair.second;
	
	if (distanceOne < distanceTwo) return one;
	else return two;
}

void Map::sortAllPathsByDistance(std::vector<std::vector<std::pair<Node, int>>>& allpaths)
{
	std::vector<std::vector<Node>> orderedPaths;

	size_t size = allpaths.size();

	if (size == 0)
	{
		return;
	}
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (calculatePathDistance(allpaths[j]) > calculatePathDistance(allpaths[j + 1]))
			{
				std::swap(allpaths[j], allpaths[j + 1]);
			}
		}
	}
}

int Map::calculatePathDistance(const std::vector<std::pair<Node, int>>& path)
{
	int distance = 0;
	for (const auto& pair : path)
	{
		distance = distance + pair.second;
	}
	return distance;
}

Map::Map(std::ifstream& in)
{
	this->currID = 0;
	size_t nodesCounter = 0;
	this->graphAdjacent.resize(8);
	if (in.is_open())
	{
		std::string line;
		while (std::getline(in, line))
		{
			std::stringstream sstream(line);
			std::string firstNode;
			sstream >> firstNode;
			
			if (graphAdjacent.size() == nodesCounter)
			{
				graphAdjacent.resize(graphAdjacent.size() * 2);
			}

			Node source = findNode(firstNode);
			if (source.nodeID == -1 && source.location =="")
			{
				source = addNode(firstNode);
				nodesCounter++;
			}

			std::string connectionNode;
			while (sstream >> connectionNode)
			{
				int distance;
				sstream >> distance;
				Node destination = findNode(connectionNode);
				if (destination.nodeID == -1 && destination.location == "")
				{
					destination = addNode(connectionNode);
					nodesCounter++;
				}
				addEdge(source, destination, distance);
			}
		}
	}
	in.close();
	this->size = this->graphAdjacent.size();
}

inline Node Map::addNode(const std::string& location)
{
	Node newNode(location, this->currID);
	this->graphAdjacent[this->currID].push_back(std::make_pair(newNode,0)); 
	this->currID++;
	return newNode;
}

inline void Map::addEdge(const Node& source, const Node& destination, int weight)
{
	this->graphAdjacent[source.nodeID].push_back(std::make_pair(destination, weight));
}

bool Map::hasPath(const std::string& from, const std::string& to, const std::vector<Node>& closedNodes)
{
	Node start = findNode(from);
	Node end = findNode(to);
	std::vector<bool> visited;
	visited.resize(this->size, false);

	//marking the closedNodes, if any
	for (size_t i = 0; i < closedNodes.size(); i++)
	{
		visited[closedNodes[i].nodeID] = true;
	}
	
	std::queue<Node> q;
	if (!visited[start.nodeID])
	{
		q.push(start);
	}
	
	while (!q.empty())
	{
		Node crr = q.front();
		q.pop();
		for (const auto& pair : this->graphAdjacent[crr.nodeID])
		{
			if (!visited[pair.first.nodeID])
			{
				if (pair.first == end)
				{
					return true;
				}
				visited[pair.first.nodeID] = true;
				q.push(pair.first);
			}
		}
	}
	return false;
}

std::vector<std::vector<Node>> Map::ThreeShortestWays(const std::string& from, const std::string& to, const std::vector<Node>& closedNodes)
{
	Node startNode = findNode(from);
	Node endNode = findNode(to);

	std::pair<Node, int> startPair(startNode, 0);
	std::pair<Node, int> endPair(endNode, 0);

	std::vector<bool> visited;
	visited.resize(this->size);
	for (const auto& node : closedNodes)
	{
		visited[node.nodeID] = true;
	}
	std::vector<std::vector<std::pair<Node,int>>> allPaths;
	std::vector<std::pair<Node,int>> path;
	std::queue<std::vector<std::pair<Node,int>>> q;

	if (visited[startNode.nodeID] == 0)
	{
		path.push_back(startPair);
		q.push(path);
	}

	while (!q.empty()) {
		path = q.front();
		q.pop();

		std::pair<Node,int> currPair = path.back(); // node->pair

		if (currPair.first == endPair.first)
		{
			allPaths.push_back(path);
		}

		for (const auto& pair : this->graphAdjacent[currPair.first.nodeID])
		{
			if (visited[pair.first.nodeID] == 0)
			{
				if (pathIsNotVisited(pair, path))
				{
					std::vector<std::pair<Node, int>> newPath(path);
					newPath.push_back(pair);
					q.push(newPath);
				}
			}
			
		}
	}
	// so far i have all paths -> we need to determine the distance in each and return the shortest 3
	
	sortAllPathsByDistance(allPaths); // BUG
	
	std::vector<std::vector<Node>> result;
	// creating vector of nodes only -> removing pairs
	for (const auto& path : allPaths)
	{
		std::vector<Node> nodePath;
		for (const auto& pair : path)
		{
			nodePath.push_back(pair.first);
		}
		result.push_back(nodePath);
	}
	if (result.size() > 3) result.resize(3); // removing the paths after the 3rd path.
	return result;
}

void Map::updateMapFile(std::ofstream& out)// TODO - > IMPROVE!!!
{
	if (out.is_open())
	{
		for (const auto& list : this->graphAdjacent)
		{
			for (const auto& pair : list)
			{
				out << pair.first.location << " "<< pair.second << " ";
			}
			out << std::endl;
		}
	}
	out.close();
}

const unsigned int Map::getSize() const
{
	return this->size;
}

const unsigned int Map::getCurrID() const
{
	return this->currID;
}

const std::vector<std::list<std::pair<Node, int>>>& Map::getGraphAdjacent() const
{
	return this->graphAdjacent;
}