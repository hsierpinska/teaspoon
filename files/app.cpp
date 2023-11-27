#include <iostream>
#include "Maps.hh"
int main(){
    
    Maps map("readtest.txt");
    map.coutCitiesList();
	std::cout << "\nGreedy path finder:"<< map.greedyPathFinder(0)<<"\n";
    //map.coutSortedList();
    /*
    Maps mapaxD(100, 100, 42);
    mapaxD.fillRandomCities();
    std::cout << "\nGreedy path finder:" << mapaxD.greedyPathFinder(1) << "\n";
    */
    return 0;
}