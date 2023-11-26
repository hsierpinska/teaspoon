#include <iostream>
#include "Maps.hh"
int main(){
    Maps map(100, 100, 10); 
   
    
    //std::cout << "Test\n"; //helper in debugging
    map.fillRandomCities();
    map.coutCitiesList();
    
	//std::vector<Cities> testVector = map.greedyPathFinder(2);
    
    map.readMap("readtest.txt", map);
    std::cout << "po wczytaniu:" << std::endl;
    map.coutCitiesList();
	//map.setVectorList(testVector);
	//std::cout << "\nNow after greedy path finder:\n";
	//map.coutCitiesList();

    return 0;
}