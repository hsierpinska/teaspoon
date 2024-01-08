#pragma once
#include "../files/Cities.hh"
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <time.h>

class Ants
{
protected:
	float a; //alpha
	float b; //beta
	long double distanceTravelled; //distance travelled in one iteration, we dont want setters, we will set values ONLY in pathFinder
	std::vector<Cities> pathTravelled; //path we got in one iteration, no setter as above
	long double pheromonesLeft; //how much we left pheromones on this iteration, no setter as above
public:
	Ants(float _a, float _b);
	void setA(float _a);
	void setB(float _b);
	float getA();
	float getB();
	long double getDistanceTravelled();
	std::vector<Cities> getPathTravelled();
	long double getPheromonesLeft();
	void pathFinder(std::vector<std::vector<long double>> &pheromonesMatrix, std::vector<std::vector<long double>> &distanceMatrix, unsigned int start, std::vector<Cities> &citiesList, unsigned int iteration); //mmm stinky, do you know da wae? 
	bool isCityNeibourOnPath(Cities cityI, Cities cityJ);
};

