#include "../teaspoon/AntHills.hh"
int main(){
    /*
    Maps map("readtest.txt");
    map.coutCitiesList();
	std::cout << "\nGreedy path finder:"<< map.greedyPathFinder(0)<<"\n";
    */

    //map.coutSortedList();
    
    /*
    Maps mapaxD(100, 100, 42);
    mapaxD.fillRandomCities();
    std::cout << "\nGreedy path finder:" << mapaxD.greedyPathFinder(1) << "\n";
    */

    //ant time
    AntHills test("test.txt");
    test.thePathFinder(1);
    std::cout << "Ant distance: "<< test.getBestDistance() <<std::endl;
    std::cout << "Greedy distance: " << test.greedyPathFinder(1) << std::endl;
    return 0;
}