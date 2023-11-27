#pragma once
#include<iostream>
class Cities
{
private:
    unsigned int x;
    unsigned int y;
    std::string name;

public:
    Cities(unsigned int _x, unsigned int _y,std::string _name);
    ~Cities();
    unsigned int getX();
    unsigned int getY();
    void setX(unsigned int _x);
    void setY(unsigned int _y);
    void setName(std::string _name);
    std::string getName();

};
