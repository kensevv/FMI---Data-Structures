// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <queue>


// Realizing graph with Adjacency lists

template <class T>
struct Node
{
	T data;
	int nodeID;
	bool operator==(const Node<T>& other) const
	{
		return this->data == other.data && this->nodeID == other.nodeID;
	}
};

template <class T>
class Graph
{
private:
	unsigned int size;
	unsigned int currID;
	std::vector<std::vector<Node<T>>> adjecent;
	void DFShelper(const Node<T>& current, std::vector<bool>& visited)
	{
		std::cout << current.data << " ";
		visited[current.nodeID] = true;

		for (const auto& node : this->adjecent[current.nodeID])
		{
			if (!visited[node.nodeID])
			{
				visited[node.nodeID] = true;
				DFShelper(node, visited);
			}
		}
	}
	bool pathIsNotVisited(const Node<T>& node, const std::vector<Node<T>>& path)
	{
		for (size_t i = 0; i < path.size(); i++)
		{
			if (node == path[i])
			{
				return false;
			}
		}
		return true;
	}
public:
	Graph(size_t size)
	{
		this->size = size;
		this->currID = 0;
		this->adjecent.resize(size);
	}
	void addNode(const T data)
	{
		this->adjecent[this->currID].push_back(Node<T>{data, (int)this->currID });
		this->currID++;
	}
	void addEdge(const Node<T>& source, const Node<T> destination)
	{
		this->adjecent[source.nodeID].push_back(destination);
	}
	void BFS(const Node<T>& start)
	{
		std::vector<bool> visited;
		visited.resize(this->size, false);
		std::queue<Node<T>> q;
		q.push(start);
		while (!q.empty())
		{
			Node<T> current = q.front();
			q.pop();
			for (const auto& node : this->adjecent[current.nodeID])
			{
				if (!visited[node.nodeID])
				{
					std::cout << node.data << " ";
					visited[node.nodeID] = true;
					q.push(node);
				}
			}
		}
	}
	void DFS(const Node<T>& start)
	{
		std::vector<bool> visited;
		visited.resize(this->size, false);
		DFShelper(start, visited);
	}
	void allPaths (const Node<T>& start, const Node<T>& end)
	{
		std::vector<std::vector<Node<T>>> allPaths;
		std::vector<Node<T>> path;
		std::queue<std::vector<Node<T>>> q;

		path.push_back(start);
		q.push(path);

		while (!q.empty()) {
			path = q.front();
			q.pop();

			Node<T> node = path[path.size() - 1];

			if (node == end) 
			{
				allPaths.push_back(path);
			}

			for (typename std::vector<Node<T>>::iterator it = this->adjecent[node.nodeID].begin(); it != adjecent[node.nodeID].end(); ++it) 
			{
				if (pathIsNotVisited(*it,path)) {
					std::vector<Node<T>> newPath(path);
					newPath.push_back(*it);
					q.push(newPath);
				}
			}
		}

		for (const auto& crrPath : allPaths)
		{
			for (size_t i = 0; i < crrPath.size(); i++)
			{
				std::cout << crrPath[i].data << " ";
			}
			std::cout << std::endl;
		}
	}
	void shortestWay(const Node<T>& start, const Node<T>& end)
	{
		std::queue<std::vector<Node<T>>> q;
		std::vector<Node<T>> path;

		path.push_back(start);
		q.push(path);

		while (!q.empty())
		{
			path = q.front();
			q.pop();

			Node<T> node = path[path.size() - 1];
			if (node == end)
			{
				for (size_t i = 0; i < path.size(); i++)
				{
					std::cout << path[i].data << " ";
				}
				return;
			}

			for (const auto& nextNode : this->adjecent[node.nodeID])
			{
				if (pathIsNotVisited(nextNode, path))
				{
					std::vector<Node<T>> newPath(path);
					newPath.push_back(nextNode);
					q.push(newPath);
				}
			}
		}
	}
	bool hasPath(const Node<T>& start, const Node<T>& end)
	{
		std::vector<bool> visited;
		visited.resize(this->size, false);
		std::queue<Node<T>> q;
		q.push(start);
		//visited[start.nodeID] = true;

		while (!q.empty())
		{
			Node<T> crr = q.front();
			q.pop();

			for (const auto& node : adjecent[crr.nodeID])
			{
				if (node == end)
				{
					return true;
				}
				if (!visited[node.nodeID])
				{
					visited[node.nodeID] = true;
					q.push(node);
				}
			}
		}
		return false;
	}
};


int main ()
{
	Graph<int> graph(6);

	Node<int> t1{ 1,0 };
	Node<int> t2{ 2,1 };
	Node<int> t3{ 3,2 };
	Node<int> t4{ 4,3 };
	Node<int> t5{ 5,4 };
	Node<int> t6{ 6,5 };

	graph.addNode(1);
	graph.addNode(2);
	graph.addNode(3);
	graph.addNode(4);
	graph.addNode(5);
	graph.addNode(6);

	graph.addEdge(t1, t2);
	graph.addEdge(t1, t5);
	graph.addEdge(t2, t3);
	graph.addEdge(t2, t4);
	graph.addEdge(t3, t4);
	graph.addEdge(t5, t6);

	graph.BFS(t1);
	std::cout << std::endl;
	graph.DFS(t1);
	std::cout << std::endl;
	std::cout << graph.hasPath(t1, t4);

	std::cout << std::endl;
	graph.shortestWay(t1, t4);

	std::cout << std::endl;

	graph.allPaths(t1, t4);
}