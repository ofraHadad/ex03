#pragma once
#include <iostream>

#include "Unit.h"
namespace ariel{


//using namespace std;

class PhysicalNumber {

private:

    Unit unit;
    double amount;
    void setUnit(ariel::Unit u){unit= u;}
    void setEmount( double x){ amount=x;}
    void setUnitV(Unit:: value x){ unit.setV(x);}
public:

    PhysicalNumber(double x, Unit unit);
    const PhysicalNumber operator-() const ;
    const PhysicalNumber operator+() const ;
    // Logical NOT
//    bool operator!() const ;
    
//    const PhysicalNumber operator+(const PhysicalNumber& other) const;

    PhysicalNumber& operator+=(const PhysicalNumber& other);

    PhysicalNumber& operator-=(const PhysicalNumber& other);

    PhysicalNumber& operator++() ;
   
    const PhysicalNumber operator++(int dummy_flag_for_postfix_increment) ;
    PhysicalNumber& operator--() ;

    const PhysicalNumber operator--(int dummy_flag_for_postfix_increment) ;

    friend const PhysicalNumber operator- (const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend const PhysicalNumber operator+ (const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator==(const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator!=(const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator>=(const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator<=(const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator>(const PhysicalNumber& c1, const PhysicalNumber& c2);
    friend bool operator<(const PhysicalNumber& c1, const PhysicalNumber& c2); 
   //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend ostream& operator<< (ostream& os, const PhysicalNumber& c);
    friend istream& operator>> (istream& is, PhysicalNumber& c);
    //------------------------------------

    double getEmount() const{return amount;}
    Unit getUnit () const{ return unit;}
    Unit:: value getUnitV() const{ return unit.getV();}

    double convert(ariel::Unit::value u) const;//use with the same dim
};
 
};





