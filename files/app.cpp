#include <iostream>
#include "Maps.hh"
int main(){
    //Maps map(100, 100, 10); 
    //map.fillRandomCities();

    Maps map("readtest.txt");
	std::vector<Cities> testVector = map.greedyPathFinder(2);
    map.coutCitiesList();
	map.setVectorList(testVector);
	std::cout << "\nNow after greedy path finder:\n";
	map.coutCitiesList();

    return 0;
}