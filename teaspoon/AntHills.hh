#pragma once
#include "../files/Maps.hh"

class AntHills :
    public Maps
{
private:
    std::vector<std::vector<long double>> pheromonesMatrix;
    std::vector<std::vector<long double>> distanceMatrix;
    unsigned int iteration;
    unsigned int bestIteration;
    long double bestDistance;
    std::vector<Cities> bestPath;

public:
    AntHills(std::string filename);
    void thePathFinder(unsigned int start);
    unsigned int getBestIteration();
    long double getBestDistance();
    std::vector<Cities> getBestPath();

};

