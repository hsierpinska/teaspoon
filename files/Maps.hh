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
protected:
    std::vector<Cities> citiesList;
    std::vector<Cities> sortedList;
    long double spaceBetween(Cities cStart, Cities cEnd); //It's a suprise tool that will help us later
    bool isRepeated(Cities city);
    unsigned int MAX_X;
    unsigned int MAX_Y;
    unsigned int NUM_OF_CITIES;
public:


    Maps(unsigned int x, unsigned int y, unsigned int noc);
    Maps(const Maps& other);
    Maps& operator=(const Maps& other);
    Maps(std::string filename);

    ~Maps();
    void addCity(Cities city);
    void fillRandomCities();
    void coutCitiesList();
    void coutSortedList();
    long double greedyPathFinder(unsigned int start);
	void setVectorList(std::vector<Cities> list);
    

};


