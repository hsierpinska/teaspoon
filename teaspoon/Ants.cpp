#include "Ants.hh"
#define Q 200 //const that is needed to calculate how much pheromones ant left
Ants::Ants(float _a, float _b) {
	a = _a;
	b = _b;
	distanceTravelled = 0;
	pheromonesLeft = 0;
	pathTravelled = {};
}	

void Ants::setA(float _a) {
	a = _a;
}

void Ants::setB(float _b) {
	b = _b;
}

float Ants::getA() {
	return a;
}
float Ants::getB() {
	return b;
}

float Ants::getDistanceTravelled() {
	return distanceTravelled;
}

std::vector<Cities> Ants::getPathTravelled() {
	return pathTravelled;
}

float Ants::getPheromonesLeft() {
	return pheromonesLeft;
}

void Ants::pathFinder(std::vector<std::vector<float>> &pheromonesMatrix, std::vector<std::vector<float>> &distanceMatrix, unsigned int start, std::vector<Cities> &citiesList) {
	// blah blah blah
	// ant will look for path
	// remembering path
	// and pheromones it left
	// AND how much distance it took
	// 
	Cities city = citiesList[start];
	pathTravelled.push_back(city);
	double probability;
	for (int x = 0; x < pheromonesMatrix[0].size(); x++) { //idk if matrix should be with pointer * or not

	}
}
bool Ants::isCityNeibourOnPath(Cities cityI, Cities cityJ) {
	for (int i = 0; i < pathTravelled.size()-1; i++) {
		if ((pathTravelled[i].getName() == cityI.getName() && pathTravelled[i + 1].getName() == cityJ.getName()) ||
			(pathTravelled[i + 1].getName() == cityI.getName() && pathTravelled[i].getName() == cityJ.getName()))//if they're neibours
		{
			return true;
		}
	}
	return false;
}
