#pragma once

namespace ariel{
#include <iostream>
using namespace std;

class Unit
{
public:
enum value{
	KM=0,//0- 1000 meter
	M=3,// 1= 100 cm
	CM=6,//2= 

	TON=1,//3- 1000
	KG=4,//4
	G=7,//5

	HOUR=2,//6
	MIN=5,//7
	SEC=8//8
};

	Unit(){};
	Unit(value x){v=x;}
	bool sameDim(value x){
		if(v%3 == x%3){return true;}
		return false;
	}
	value getV() const{return v;}
	void setV(value x){v=x;}
private:
value v;

};
}
