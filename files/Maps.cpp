#include "Maps.hh"
#include <fstream>
#include <cstdlib>

Maps::Maps(unsigned int x, unsigned int y, unsigned int noc) :MAX_X(x), MAX_Y(y), NUM_OF_CITIES(noc)
{
    std::cout << "New map created.\nMax X: " << MAX_X << "\nMax Y: " << MAX_Y << "\nNumber of cities: " << NUM_OF_CITIES << "\n";

}

Maps::Maps(const Maps& other) {

    std::cout << "Map created out of already existing\n";
    MAX_X = other.MAX_X;
    MAX_Y = other.MAX_Y;
    NUM_OF_CITIES = other.NUM_OF_CITIES;
    citiesList = other.citiesList;

}

Maps& Maps::operator=(const Maps& other) {
    std::cout << "Map copied";
    MAX_X = other.MAX_X;
    MAX_Y = other.MAX_Y;
    NUM_OF_CITIES = other.NUM_OF_CITIES;
    citiesList = other.citiesList;
    return *this;
}

Maps::Maps(std::string filename)
{
    std::ifstream infile(filename);
    int id, x, y, i, num_of_cities;
    int max_x = 0;
    int max_y = 0;
    std::string firstLine;
    std::getline(infile, firstLine);
    num_of_cities = atoi(firstLine.c_str());

    while (infile >> id >> x >> y)
    {

        (x > max_x) ? max_x = x : 0;
        (y > max_y) ? max_y = y : 0;

    }
    
    infile.close();
    //ponownie trzeba przeczytaæ plik, mamy ju¿ wyznaczone max_x i max_y
    MAX_X = max_x;
    MAX_Y = max_y;
    NUM_OF_CITIES = num_of_cities;
    std::ifstream infile1(filename);
    std::getline(infile1, firstLine);
    while (infile1 >> id >> x >> y) //pomija pierwsz¹ linijkê
    {   
        //std::cout << "id: " << id << " x: " << x << " y: " << y << std::endl;
        auto c = Cities(x, y, std::to_string(id));
        addCity(c);

    }

}



Maps::~Maps()
{
}

long double Maps::spaceBetween(Cities cStart, Cities cEnd) {
    long double space = long double(sqrt(pow((long double(cStart.getX()) - long double(cEnd.getX())), 2) + pow(long double((cStart.getY()) - long double(cEnd.getY())), 2)));//sqrt((x1-x2)^2 + (y1-y2)^2)
    //std::cout << "Space between "<< cStart.getName() <<" and "<< cEnd.getName()<<":" << space << std::endl; //you can check if it works urself, just uncomment.
    return space;
}

void Maps::addCity(Cities city){
    if(NUM_OF_CITIES > unsigned int(citiesList.size())){
        citiesList.push_back(city);
    }
    else{
        std::cout<<"No more space for new city.\n";
    }
}

void Maps::fillRandomCities(){
    std::default_random_engine generator(unsigned int(time(NULL))); //random numbers generator
    std::uniform_int_distribution<unsigned int> distributionX(1,MAX_X); //diffrent distributions for each X and Y
    std::uniform_int_distribution<unsigned int> distributionY(1,MAX_Y);
    int citiesOnMap = int(citiesList.size()); //getting it before for since it would broke there
    //generator.seed(time(NULL));
    std::ofstream outfile("test.txt");
    outfile << NUM_OF_CITIES << std::endl;
    for(unsigned int i = 0; i < NUM_OF_CITIES-citiesOnMap; i++){ //filling up cities list
       
        unsigned int randX = distributionX(generator);
        unsigned int randY = distributionY(generator);
        std::string name = std::to_string(i+1); //Name: City (number of i in for), you can add 2 strings to get 1 string :o
        
        Cities c(randX,randY,name);
        if (isRepeated(c)) {
            while (isRepeated(c)) {
                randX = distributionX(generator);
                randY = distributionY(generator);
                c = Cities(randX, randY, name);
            }
        }
        
        outfile << name << " " << randX << " " << randY << std::endl;
        citiesList.push_back(c);
        
    }
    outfile.close();
    spaceBetween(citiesList[0],citiesList[1]);
}

void Maps::coutCitiesList(){
    for(auto c : citiesList){
        std::cout<<c.getName()<<"\t\tx: "<<c.getX()<<"\t\ty: "<<c.getY()<<"\n";
    }
}

std::vector<Cities> Maps::greedyPathFinder(unsigned int start){//basically pushing start at the end and then closest one,
    //repeat closest one with ignoring that are sorted
    std::vector<Cities> list;//empty list to return if something is wrong and to not touch original list
    if (start < NUM_OF_CITIES) {
        if (citiesList.size() != NUM_OF_CITIES) {
            std::cout << "Error. Not enough cities on map.\n";
        }
        else {
            list = citiesList;
            
			list.push_back(list[start]);//start at the end
			list.erase(list.begin()+start);

			for (unsigned int i = 0; i < NUM_OF_CITIES - 1; i++) {//
				unsigned int closestIndex = 0; //setting 1st as closest
				long double d, closestDistance = spaceBetween(list[NUM_OF_CITIES - 1], list[0]);
				for (unsigned int j = 1; j < NUM_OF_CITIES - 1 - i; j++) {//testing rest
					if ((d=spaceBetween(list[NUM_OF_CITIES - 1], list[j])) < closestDistance) {//if its closer then remember closest one
						closestIndex = j;
						closestDistance = d;
					}
				}
				list.push_back(list[closestIndex]); //push back closest one
				list.erase(list.begin() + closestIndex); //and erase
			}

            return list;
        }
    }
    else {
        std::cout << "Error. City index out of range.\n";
    }
    return list;
}

void Maps::setVectorList(std::vector<Cities> list) {
	if (list.size() != NUM_OF_CITIES) {
		std::cout << "Error. Not enough cities in list.\n";
	}
	else {
		citiesList = list;
	}
}

bool Maps::isRepeated(Cities city) {
    int x = city.getX();
    int y = city.getY();
    int citiesOnMap = int(citiesList.size());
    for (unsigned int i = 0; i < citiesOnMap; i++) {
        if (citiesList[i].getX() == x && citiesList[i].getY() == y)
            return true;
    }
    return false;
}
