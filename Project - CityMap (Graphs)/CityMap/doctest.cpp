#pragma once
#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "Map.h"


/*
(node1 0) -> (node2 1) -> (node3 2)
(node2 0) -> (node3 3)
(node3 0) -> (node4 4)
(node4 0)
*/

TEST_CASE("Read Graph From File + addnode + addedge TESTs")
{
	std::ifstream in("doctestMAP tests.txt");
	Map testmap(in);

	Node t1("node1", 0);
	Node t2("node2", 1);
	Node t3("node3", 2);
	Node t4("node4", 3);

	CHECK(testmap.getGraphAdjacent()[0].front().first == t1);
	CHECK(testmap.getGraphAdjacent()[1].front().first == t2);
	CHECK(testmap.getGraphAdjacent()[2].front().first == t3);
	CHECK(testmap.getGraphAdjacent()[3].front().first == t4);

	CHECK(testmap.getGraphAdjacent()[0].front().first.nodeID == 0);
	CHECK(testmap.getGraphAdjacent()[1].front().first.nodeID == 1);
	CHECK(testmap.getGraphAdjacent()[2].front().first.nodeID == 2);
	CHECK(testmap.getGraphAdjacent()[3].front().first.nodeID == 3);

	CHECK(testmap.getGraphAdjacent()[4].empty());

	int countNodesingraph = 0;
	for (const auto& node : testmap.getGraphAdjacent())
	{
		if (!node.empty())
		{
			countNodesingraph++;
		}
	}
	CHECK(countNodesingraph == 4);

	CHECK(testmap.getGraphAdjacent()[0].back().first.location == "node3");
	CHECK(testmap.getGraphAdjacent()[0].back().second == 2);
	CHECK(testmap.getGraphAdjacent()[0].size() == 3);
	
	CHECK(testmap.getGraphAdjacent()[1].back().first.location == "node3");
	CHECK(testmap.getGraphAdjacent()[1].back().second == 3);
	CHECK(testmap.getGraphAdjacent()[1].size() == 2);
	
	CHECK(testmap.getGraphAdjacent()[2].back().first.location == "node4");
	CHECK(testmap.getGraphAdjacent()[2].back().second == 4);
	CHECK(testmap.getGraphAdjacent()[2].size() == 2);

	CHECK(testmap.getGraphAdjacent()[3].size() == 1);

	for (size_t i = 4; i < testmap.getGraphAdjacent().size(); i++)
	{
		CHECK(testmap.getGraphAdjacent()[i].empty());
	}
}

TEST_CASE("hasPath Tests with / without closed roads given")
{
	std::ifstream in("doctestMAP tests.txt");
	Map testmap(in);
	//TESTS FOR NO CLOSED NODES
	CHECK(testmap.hasPath("node1", "node2") == 1);
	CHECK(testmap.hasPath("node1", "node3") == 1);
	CHECK(testmap.hasPath("node2", "node3") == 1);
	CHECK(testmap.hasPath("node2", "node1") == 0);
	CHECK(testmap.hasPath("node3", "node1") == 0);
	CHECK(testmap.hasPath("node3", "node2") == 0);
	CHECK(testmap.hasPath("node3", "node4") == 1);
	CHECK(testmap.hasPath("node4", "node1") == 0);
	CHECK(testmap.hasPath("node4", "node2") == 0);
	CHECK(testmap.hasPath("node4", "node3") == 0);
	CHECK(testmap.hasPath("node1", "node4") == 1);
	CHECK(testmap.hasPath("node2", "node4") == 1);

	Node t1("node1", 0);
	Node t2("node2", 1);
	Node t3("node3", 2);
	Node t4("node4", 3);

	//another test for adding edges
	testmap.addEdge(t4, t2, 5);
	testmap.addEdge(t2, t1, 5);
	/*
		new graph:

		(node1 0) -> (node2 1) -> (node3 2)
		(node2 0) -> (node3 3) -> (node1 5)
		(node3 0) -> (node4 4)
		(node4 0) -> (node1 5)
	*/
	CHECK(testmap.hasPath("node1", "node2") == 1);
	CHECK(testmap.hasPath("node1", "node3") == 1);
	CHECK(testmap.hasPath("node2", "node3") == 1);
	CHECK(testmap.hasPath("node2", "node1") == 1);
	CHECK(testmap.hasPath("node3", "node1") == 1);
	CHECK(testmap.hasPath("node3", "node2") == 1);
	CHECK(testmap.hasPath("node3", "node4") == 1);
	CHECK(testmap.hasPath("node4", "node1") == 1);
	CHECK(testmap.hasPath("node4", "node2") == 1);
	CHECK(testmap.hasPath("node4", "node3") == 1);
	CHECK(testmap.hasPath("node1", "node4") == 1);
	CHECK(testmap.hasPath("node2", "node4") == 1);

	//TESTS WITH CLOSED NODES
	std::vector<Node> closedRoads;
	closedRoads.push_back(t3);
	CHECK(testmap.hasPath("node1", "node3", closedRoads) == 0);
	CHECK(testmap.hasPath("node1", "node4", closedRoads) == 0);
	CHECK(testmap.hasPath("node2", "node4", closedRoads) == 0);
	CHECK(testmap.hasPath("node3", "node4", closedRoads) == 0);
	CHECK(testmap.hasPath("node4", "node3", closedRoads) == 0);
	CHECK(testmap.hasPath("node4", "node1", closedRoads) == 1);
	closedRoads.push_back(t1);
	CHECK(testmap.hasPath("node2", "node1", closedRoads) == 0);
	CHECK(testmap.hasPath("node2", "node3", closedRoads) == 0);
	CHECK(testmap.hasPath("node2", "node4", closedRoads) == 0);
	CHECK(testmap.hasPath("node4", "node2", closedRoads) == 1);
	CHECK(testmap.hasPath("node4", "node1", closedRoads) == 0);
	CHECK(testmap.hasPath("node4", "node3", closedRoads) == 0);
	closedRoads.push_back(t4);
	CHECK(testmap.hasPath("node4", "node2", closedRoads) == 0);
	CHECK(testmap.hasPath("node4", "node1", closedRoads) == 0);
	CHECK(testmap.hasPath("node1", "node4", closedRoads) == 0);
}

TEST_CASE("ThreeShortestWays Tests")
{
	std::ifstream in("doctestMAP tests.txt");
	Map testmap(in);
	Node t1("node1", 0);
	Node t2("node2", 1);
	Node t3("node3", 2);
	Node t4("node4", 3);
/*
node1 node2 1 node3 2
node2 node3 3
node3 node4 4
node4
*/
	//TESTS FOR NO CLOSED NODES
	std::vector<std::vector<Node>> paths = testmap.ThreeShortestWays("node1", "node4");
	std::vector<Node> correctPath1 = {t1,t3,t4}; // distance == 6
	std::vector<Node> correctPath2 = {t1,t2,t3,t4}; // distance == 8
	CHECK(paths[0] == correctPath1);
	CHECK(paths[1] == correctPath2);
	CHECK(paths.size() == 2);
	//CLOSING ROAD
	std::vector<Node> closedRoads;
	closedRoads.push_back(t2);
	paths = testmap.ThreeShortestWays("node1", "node4", closedRoads);
	CHECK(paths.size() == 1);
	CHECK(paths[0] == correctPath1);
	//ADDING LONGER / SHORTER CORRECT PATHS
	testmap.addEdge(t1, t4, 50); // longer than others, but direct for BFS
	paths = testmap.ThreeShortestWays("node1", "node4");
	std::vector<Node> correctPath3 = { t1,t4 }; // distance = 50
	CHECK(paths.size() == 3);
	CHECK(paths[0] == correctPath1);
	CHECK(paths[1] == correctPath2);
	CHECK(paths[2] == correctPath3);
	//CHECK IF RETURNS ONLY 3 PATHS
	testmap.addEdge(t2, t4, 7); // -> should be 2nd longest path.
	std::vector<Node> correctPath4 = { t1,t2,t4 }; // distance = 7
	paths = testmap.ThreeShortestWays("node1", "node4");
	CHECK(paths.size() == 3);
	CHECK(paths[0] == correctPath1);
	CHECK(paths[1] == correctPath4);
	CHECK(paths[2] == correctPath2);
}