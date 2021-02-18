#pragma once
#define DOCTEST_CONFIG_IMPLEMENT

#include "doctest.h"
#include "Map.h"

std::ifstream in("map.txt");
Map map(in);

TEST_CASE("Read Graph From File TEST")
{

}

TEST_CASE("addNode test")
{

}

TEST_CASE("addEdge test")
{

}

TEST_CASE("hasPath Test")
{
	
	CHECK(map.hasPath("node1", "node2") == 1);
	CHECK(map.hasPath("node1", "node3") == 1);
	CHECK(map.hasPath("node2", "node3") == 1);
	CHECK(map.hasPath("node2", "node1") == 0);
	CHECK(map.hasPath("node3", "node1") == 0);
	CHECK(map.hasPath("node3", "node2") == 0);
}