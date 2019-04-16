#pragma once

namespace ariel{
#include <iostream>
using namespace std;

class Unit
{
public:
enum value{
	KM=0,//0- 1000 meter
	M=3,// 3= 100 cm
	CM=6,//6= 

	TON=1,//1- 1000
	KG=4,//4
	G=7,//7

	HOUR=2,//2
	MIN=5,//5
	SEC=8//8
};

	Unit(){};
	Unit(value x){v=x;}
	//use for valid inpunt
	Unit(string s)
	{
		if(s=="[km]")
			setV(KM);
		else if(s=="[m]")
			setV(M);
			
		else if(s=="[cm]")
			setV(CM);
		else if(s=="[ton]")
			setV(TON);
		else if(s=="[kg]")
			setV(KG);
		else if(s=="[g]")
			setV(G);
		else if(s=="[hour]")
			setV(HOUR);
		else if(s=="[min]")
			setV(MIN);
		else if(s=="[sec]")
			setV(SEC);		
	}	
			
	bool sameDim(value x){
		if(v%3 == x%3){return true;}
		return false;
	}
	value getV() const{return v;}
	void setV(value x){v=x;}
	char values[9][10]={"[km]","[ton]","[hour]","[m]","[kg]","[min]","[cm]","[g]","[sec]"};
private:
	value v;

};
};
