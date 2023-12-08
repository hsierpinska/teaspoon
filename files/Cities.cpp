#include "Cities.hh"


Cities::Cities(unsigned int _x, unsigned int _y,std::string _name)
{
    x = _x;
    y = _y;
    name = _name;
}

Cities::~Cities()
{
}

bool Cities::operator==(const Cities& rhs) {
    if (this->name == rhs.name && this->x == rhs.x && this->y == rhs.y) {
        return true;
    }
    else {
        return false;
    }
}

unsigned int Cities::getX(){
    return x;
}

unsigned int Cities::getY(){
    return y;
}

std::string Cities::getName(){
    return name;
}

void Cities::setX(unsigned int _x) {
    x = _x;
}
void Cities::setY(unsigned int _y) {
    y = _y;
}
void Cities::setName(std::string _name) {
    name = _name;
}