#pragma once
#include "../files/Maps.hh"
#include "Ants.hh"
class AntHills :
    public Maps
{
private:
    std::vector<std::vector<float>> pheromonesMatrix;
    std::vector<std::vector<float>> distanceMatrix;
    unsigned int iteration;
    unsigned int bestIteration;
    float distance;
    float bestDistance;
    std::vector<Cities> path;
    std::vector<Cities> bestPath;

public:
    AntHills(std::string filename);
    void thePathFinder(unsigned int start);
    unsigned int getBestIteration();
    float getBestDistance();
    std::vector<Cities> getBestPath();

};

