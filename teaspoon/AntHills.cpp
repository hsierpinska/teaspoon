#include "AntHills.hh"
#define START_PHEROMONES 0.2f
#define ITERATIONS 100
#define ANT_QUANTITY 29
#define P_E 0.1f // PHEROMON_EVAPORATION in range (0,1) 
AntHills::AntHills(std::string filename) : Maps(filename) {
    bestDistance = 0;
    for (unsigned int x = 0; x < NUM_OF_CITIES; x++) {//filling matrix with basic values
        bestPath.push_back(citiesList[x]);
        pheromonesMatrix.push_back({});
        distanceMatrix.push_back({});
        for (unsigned int y = 0; y < NUM_OF_CITIES; y++) {
            pheromonesMatrix[x].push_back(START_PHEROMONES);
            distanceMatrix[x].push_back(spaceBetween(citiesList[x],citiesList[y]));//filling matrix with distances between all cities so we dont have to it later
        }
    }
    for (unsigned int y = 0; y < NUM_OF_CITIES-1; y++) {
        bestDistance += distanceMatrix[y][y+1];//filling with first distance we can get since we dont know what worst option could be
    }
    bestDistance += distanceMatrix[0][NUM_OF_CITIES - 1];
    iteration = 0;
    bestIteration = 0;
}
void AntHills::thePathFinder(unsigned int start) {
    //welp I need to do it at some point
    iteration = 0;

    std::vector<Ants> ants;//vector of ants we'll be using
    long double tmp;
    long double pheromones;
    unsigned int tmp_start;
    for (int i = 0; i < ANT_QUANTITY; i++) {//pushing here vector of ants
        ants.push_back(Ants(1.2, 1));
    }
    for (unsigned int i = 0; i < ITERATIONS; i++) {//iteration
        for (unsigned int a = 0; a < ANT_QUANTITY; a++) {//ant
            tmp_start = a;
            while (tmp_start >= NUM_OF_CITIES) {
                tmp_start -= NUM_OF_CITIES;
            }
            
            ants[a].pathFinder(pheromonesMatrix, distanceMatrix, tmp_start, citiesList);
            
            if ((tmp = ants[a].getDistanceTravelled()) < bestDistance) {
                bestDistance = tmp;
                bestIteration = iteration;
                bestPath = ants[a].getPathTravelled();
            }
            std::cout << i << " " << tmp << std::endl;
        }
        //let's update pheromones matrix
        for (unsigned int x = 0; x < NUM_OF_CITIES; x++) {
            for (unsigned int y = 0; y < NUM_OF_CITIES; y++) {
                pheromones = 0;
                for (unsigned int a = 0; a < ANT_QUANTITY; a++) {
                    if (ants[a].isCityNeibourOnPath(citiesList[x],citiesList[y])) {
                        pheromones += ants[a].getPheromonesLeft();
                    }
                }
                pheromonesMatrix[x][y] = (1 - P_E) * pheromonesMatrix[x][y]+ pheromones; //P_E is const lost of pheromones after time
            }
        }
        iteration++;
    }
}
unsigned int AntHills::getBestIteration() {
    return bestIteration;
}
long double AntHills::getBestDistance() {
    return bestDistance;
}
std::vector<Cities> AntHills::getBestPath() {
    return bestPath;
}
