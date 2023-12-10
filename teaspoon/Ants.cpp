#include "Ants.hh"
#define Q 30 //const that is needed to calculate how much pheromones ant left
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

long double Ants::getDistanceTravelled() {
	return distanceTravelled;
}

std::vector<Cities> Ants::getPathTravelled() {
	return pathTravelled;
}

long double Ants::getPheromonesLeft() {
	return pheromonesLeft;
}

void Ants::pathFinder(std::vector<std::vector<long double>> &pheromonesMatrix, std::vector<std::vector<long double>> &distanceMatrix, unsigned int start, std::vector<Cities> &citiesList) {
	// blah blah blah
	// ant will look for path
	// remembering path
	// and pheromones it left
	// AND how much distance it took
	// 
	Cities city = citiesList[start];
	pathTravelled = {};
	pathTravelled.push_back(city);
	int lCity = start; //last visited city

	std::vector<Cities> tmp_cities;
	std::vector<double> tmp_prob;
	long double probability;


	std::uniform_real_distribution<double> unif(0,1);
	std::default_random_engine re;
	long double tmp_rand;
	int i;

	distanceTravelled = 0;
	for (int x = 0; x < pheromonesMatrix[0].size()-1; x++) { 
		tmp_cities = {};
		tmp_prob = {};
		probability = 0;
		for (int y = 0; y < pheromonesMatrix[0].size(); y++){
			if (!(std::find(pathTravelled.begin(), pathTravelled.end(), citiesList[y]) != pathTravelled.end())) {//if city wasnt already visited
				probability += (pow(pheromonesMatrix[lCity][y], a) * pow(distanceMatrix[lCity][y], b));//sum of every path 
			}
		}
		for (int y = 0; y < pheromonesMatrix[0].size(); y++) {
			if (!(std::find(pathTravelled.begin(), pathTravelled.end(), citiesList[y]) != pathTravelled.end())) {//if city wasnt already visited
				tmp_prob.push_back((pow(pheromonesMatrix[lCity][y],a) * pow(distanceMatrix[lCity][y],b)) / probability);
				tmp_cities.push_back(citiesList[y]);//list of cities we choose from
			}
		}
		
		tmp_rand = unif(re);
		i = 0;
		while ((tmp_rand -= tmp_prob[i])>0) {//geting random path, sum of all floats in tmp_prob should be equal 1
			i++;
		}
		//if (i >= tmp_prob.size()) {//in case sum of floats are not equal 1 but 1.00001 or 0.99999 or smth and tmp_rand is 1
		//	i--;
		//}
		pathTravelled.push_back(tmp_cities[i]);
		distanceTravelled += distanceMatrix[lCity]
			[
				std::find(citiesList.begin(), citiesList.end(), tmp_cities[i]) - citiesList.begin()
			];
		lCity = std::find(citiesList.begin(),citiesList.end(),tmp_cities[i]) - citiesList.begin();//remembering index of last city
	}
	distanceTravelled += distanceMatrix[lCity][start]; //+ distance from last to 
	//how much ant left pheromones?
	pheromonesLeft = (long double) Q / distanceTravelled;
}
bool Ants::isCityNeibourOnPath(Cities cityI, Cities cityJ) {
	for (int i = 0; i < pathTravelled.size()-1; i++) {
		if ((pathTravelled[i] == cityI && pathTravelled[i + 1] == cityJ) ||
			(pathTravelled[i + 1] == cityI && pathTravelled[i] == cityJ))//if they're neibours
		{
			return true;
		}
	}
	return false;
}
