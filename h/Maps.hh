#pragma once
#include "Cities.hh"
#include <vector>
#include <string>
#include <random>
#include <time.h>
#include <cmath>
#include <fstream>

class Maps
{
private:
    std::vector<Cities> citiesList;
    long double spaceBetween(Cities cStart, Cities cEnd); //It's a suprise tool that will help us later
    bool isRepeated(Cities city);
public:

    unsigned int MAX_X;
    unsigned int MAX_Y;
    unsigned int NUM_OF_CITIES;

    Maps(unsigned int x, unsigned int y, unsigned int noc);
    //Maps(std::string filename);
    ~Maps();
    void addCity(Cities city);
    void fillRandomCities();
    void coutCitiesList();
    std::vector<Cities> greedyPathFinder(unsigned int start);
	void setVectorList(std::vector<Cities> list);
    static void readMap(std::string filename, Maps &map);
    //static void readMap(std::string filename);
};


