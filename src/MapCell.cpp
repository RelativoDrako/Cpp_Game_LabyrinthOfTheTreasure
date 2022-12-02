#include<iostream>
#include "MapCell.h"
using namespace std;

MapCell::MapCell()
{
    Id=5;
}

bool MapCell::IsBlocked()
{
    if(Id=='1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

MapCell::~MapCell(){}
