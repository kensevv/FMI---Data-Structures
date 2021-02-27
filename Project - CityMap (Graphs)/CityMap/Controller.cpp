#include "Controller.h"

Controller::Controller(std::ifstream& in) : map(Map(in))
{
    this->currentPosition = map.getGraphAdjacent()[0].begin()->first;
}

const std::string& Controller::location()
{
    return this->currentPosition.location;
}

void Controller::changeLocation(const std::string& node)
{
    Node newPosition = map.findNode(node);
    if (newPosition.location != "" && newPosition.nodeID != -1)
    {
        this->currentPosition = newPosition;
    }
    else
    {
        std::cout << "Location " << node << " not found!" << std::endl;
    }
}

void Controller::hasPath(const std::string& destination)
{
    bool hasPath = this->map.hasPath(this->currentPosition.location, destination, closedCrossRoads);
    if (hasPath)
    {
        std::cout << "There is path from " << this->currentPosition.location << " to " << destination << std::endl;
    }
    else
    {
        std::cout << "There is NO path from " << this->currentPosition.location << " to " << destination << std::endl;
    }
}

void Controller::threeShortestWays(const std::string& destination)
{
    std::vector<std::vector<Node>> threeShortestPaths = map.ThreeShortestWays(this->currentPosition.location, destination, closedCrossRoads);

    if (threeShortestPaths.empty())
    {
        std::cout << "No path found!" << std::endl;
        return;
    }

    for (const auto& path : threeShortestPaths)
    {
        for (const auto& node : path)
        {
            std::cout << node.location << " ";
        }
        std::cout << std::endl;
    }
}

void Controller::move(const std::string& destination)
{
    std::vector<std::vector<Node>> threeShortestPaths;
    threeShortestPaths = this->map.ThreeShortestWays(this->currentPosition.location, destination, this->closedCrossRoads);
    if (threeShortestPaths.size() == 0)
    {
        std::cout << "No path found from " << this->currentPosition.location << " to " << destination 
            << ".\n Current position has not been changed." << std::endl;
    }
    else
    {
        std::cout << "The shortest path found from " << this->currentPosition.location << " to " << destination << " around closed Xroads is:\n";
        for (const auto& node : threeShortestPaths[0])
        {
            std::cout << node.location << " ";
        }
        std::cout << std::endl;
        this->currentPosition = map.findNode(destination);
        std::cout << "Current position has been set to " << destination << ".\n";
    }
}

void Controller::openCrossRoad(const std::string& node)
{
    int index = -1;
    for (size_t i = 0; i < this->closedCrossRoads.size(); i++)
    {
        if (this->closedCrossRoads[i].location == node)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        this->closedCrossRoads.erase(closedCrossRoads.begin() + index);
    }
    else
    {
        std::cout << node << " is not closed!" << std::endl;
    }
}

void Controller::closeCrossRoad(const std::string& node)
{
    Node crossRoadToClose = map.findNode(node);
    if (crossRoadToClose.location != "" && crossRoadToClose.nodeID != -1)
    {
        this->closedCrossRoads.push_back(crossRoadToClose);
    }
    else
    {
        std::cout << "Location " << node << " not found!" << std::endl;
    }
}

void Controller::closed()
{
    for (size_t i = 0; i < closedCrossRoads.size(); i++)
    {
        std::cout << closedCrossRoads[i].location << "; ";
    }
    std::cout << std::endl;
}

void Controller::tour()
{
    //TODO
}
