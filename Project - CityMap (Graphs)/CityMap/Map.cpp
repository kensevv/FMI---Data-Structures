#include "Map.h"
#include <sstream>

inline bool Node::operator==(const Node& other) const
{
	return this->location == other.location && this->nodeID == other.nodeID;
}

Node::Node(const std::string& location, const int ID) : location(location), nodeID(ID){}

Node::Node(){}

Node Map::findNode(const std::string& location)
{
	for (const auto& node : this->graphAdjacent)
	{
		if (!node.empty())
		{
			if (node.front().first.location == location)
			{
				return node.front().first;
			}
		}
		
	}
	return Node("", -1);
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

//bool Map::hasPath(const Node& start, const Node& end)
bool Map::hasPath(const std::string& from, const std::string& to)
{
	Node start = findNode(from);
	Node end = findNode(to);

	std::vector<bool> visited;
	visited.resize(this->size, false);
	
	std::queue<Node> q;
	q.push(start);

	while (!q.empty())
	{
		Node crr = q.front();
		q.pop();

		for (const auto& pair : this->graphAdjacent[crr.nodeID])
		{
			if (pair.first == end)
			{
				return true;
			}
			if (!visited[pair.first.nodeID])
			{
				visited[pair.first.nodeID] = true;
				q.push(pair.first);
			}
		}
	}
	return false;
}

void Map::updateMapFile(std::ofstream& out)
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