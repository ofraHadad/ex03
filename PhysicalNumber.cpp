#include "PhysicalNumber.h"
using namespace std;
using namespace ariel;

//----------------------------------------
// friend global binary operators
//---------------------------------


PhysicalNumber:: PhysicalNumber(double x, Unit unit)
{
	setEmount(x);
	setUnitV(unit.getV());
}
bool operator==(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
	{
			throw std::out_of_range("The dimensions are diffrent");	
	//hariga not the same dim or false
	}

	if(c1.getEmount()== c1.convert(c2.getUnitV()))
	{
		return true;
	}
	
	return false;
}


double PhysicalNumber:: convert(Unit::value v) const
{
	if(v==0)
	{
		if(this->getUnitV()==0){return getEmount();}
		else if(this->getUnitV()==3){return getEmount()/1000;}
		else{return getEmount()/100000;}
	}

	else if(v==3)
	{
		 if(this->getUnitV()==0){return getEmount()*1000;}
                else if(this->getUnitV()==3){return getEmount();}
                else{return getEmount()/100;}
	}

	else if(v==6)
        {
                if(this->getUnitV()==0){return getEmount()*1000000;}
                else if(this->getUnitV()==3){return getEmount()*100;}
                else{return getEmount();}
        }

	else if(v==1)
	{
		if(this->getUnitV()==1){return getEmount();}
                else if(this->getUnitV()==4){return getEmount()/1000;}
                else{return getEmount()/1000000;}
        }

	else if(v==4)
        {
                if(this->getUnitV()==1){return getEmount()*1000;}
                else if(this->getUnitV()==4){return getEmount();}
                else{return getEmount()/1000;}
        }

	else if(v==7)
        {
                if(this->getUnitV()==1){return getEmount()*1000000;}
                else if(this->getUnitV()==4){return getEmount()*1000;}
                else{return getEmount();}
        }

	else if(v==2)
        {
                if(this->getUnitV()==2){return getEmount();}
                else if(this->getUnitV()==5){return getEmount()/60;}
                else{return getEmount()/3600;}
        }

	else if(v==5)
        {
                if(this->getUnitV()==2){return getEmount()*60;}
                else if(this->getUnitV()==5){return getEmount();}
                else{return getEmount()/60;}
        }

	else if(v==8)
        {
                if(this->getUnitV()==2){return getEmount()*3600;}
                else if(this->getUnitV()==5){return getEmount()*60;}
                else{return getEmount();}
        }
	else
	{
		throw std::out_of_range("not valid");
	}
}

bool operator!=(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
return true;
//    return (!(c1==c2));
}

bool operator>=(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
	if(c1.getEmount()>= c2.convert(c1.getUnitV())){ return true;}
	else{return false;}
}

bool operator<=(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount()<= c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

bool operator>(const PhysicalNumber& c1, const PhysicalNumber& c2) {
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount() > c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

bool operator<(const PhysicalNumber& c1, const PhysicalNumber& c2) {
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount() < c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

//
const PhysicalNumber operator-(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
	{
		throw std::out_of_range("The dimensions are diffrent");
	}

	return PhysicalNumber(c1.getEmount()-c2.convert(c1.getUnitV()),c1.getUnit());
	
}

const PhysicalNumber operator+(const PhysicalNumber& c1, const PhysicalNumber& c2) 
{
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }

        return PhysicalNumber(c1.getEmount() + c2.convert(c1.getUnitV()),c1.getUnit());

}

//unary
const PhysicalNumber PhysicalNumber:: operator-()  const
{
        return PhysicalNumber(-(this->getEmount()) , this->getUnit());
}

const PhysicalNumber PhysicalNumber::operator+() const
{
        return PhysicalNumber(this->getEmount() , this->getUnit());
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other) 
{
	if(!getUnit().sameDim(other.getUnitV()))
	{
		throw std::out_of_range("The dimensions are diffrent");
	}
	this->setEmount(this->getEmount()+other.convert(this->getUnitV()));
        return *this; // for call chaining
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
{

        if(!this->getUnit().sameDim(other.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }
        this->setEmount(this->getEmount() - other.convert(this->getUnitV()));
        return *this; // for call chaining
}

  // prefix increment:
PhysicalNumber& PhysicalNumber::operator++()
{
        this->setEmount((this->getEmount())+1);
        return *this;
}

    // postfix increment:
const PhysicalNumber PhysicalNumber::operator++(int dummy_flag_for_postfix_increment) 
{
        PhysicalNumber copy = *this;
         this->setEmount((this->getEmount())+1);
      return copy; 
}

PhysicalNumber& PhysicalNumber::operator--()
{
        this->setEmount((this->getEmount())-1);
        return *this;
}

    // postfix increment:
const PhysicalNumber PhysicalNumber::operator--(int dummy_flag_for_postfix_increment)
{
        PhysicalNumber copy = *this;
         this->setEmount((this->getEmount())-1);
      return copy;
}

ostream& operator<< (ostream& os, const PhysicalNumber& c) {
    return (os <<  'i');
    // equivalent to:
    // os << c._re << '+' << c._im << 'i';
    // return os;
}


static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
  /*  char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
   */ return input;
}

istream& operator>> (istream& input, PhysicalNumber& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------
/*    double new_re, new_im;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> new_re))                 ||
         (!getAndCheckNextCharIs(input,'+')) ||
         (!(input >> new_im))                 ||
         (!(getAndCheckNextCharIs(input,'i'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
       // c._re = new_re;
       // c._im = new_im;
    }
*/
    return input;
    //---------------------------------------------
}
