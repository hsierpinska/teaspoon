#pragma once
#include "../files/Cities.hh"
#include <vector>
#include <cmath>

class Ants
{
private:
	float a; //alpha
	float b; //beta
	float distanceTravelled; //distance travelled in one iteration, we dont want setters, we will set values ONLY in pathFinder
	std::vector<Cities> pathTravelled; //path we got in one iteration, no setter as above
	float pheromonesLeft; //how much we left pheromones on this iteration, no setter as above
public:
	Ants(float _a, float _b);
	void setA(float _a);
	void setB(float _b);
	float getA();
	float getB();
	float getDistanceTravelled();
	std::vector<Cities> getPathTravelled();
	float getPheromonesLeft();
	void pathFinder(std::vector<std::vector<float>> &pheromonesMatrix, std::vector<std::vector<float>> &distanceMatrix, unsigned int start, std::vector<Cities> &citiesList); //mmm stinky, do you know da wae? 
	bool isCityNeibourOnPath(Cities cityI, Cities cityJ);
};

