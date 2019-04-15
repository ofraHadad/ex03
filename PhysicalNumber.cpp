#include "PhysicalNumber.h"

using namespace std;
//using namespace ariel;

//----------------------------------------
// friend global binary operators
//---------------------------------


ariel::PhysicalNumber::PhysicalNumber(double x, Unit unit)
{
	setEmount(x);
	setUnitV(unit.getV());
}
bool ariel::operator==(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
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


double ariel::PhysicalNumber:: convert(Unit::value v) const
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

bool ariel::operator!=(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
	{
			throw std::out_of_range("The dimensions are diffrent");	
	//hariga not the same dim or false
	}

	if(c1.getEmount()!= c1.convert(c2.getUnitV()))
	{
		return true;
	}
	
	return false;

}

bool ariel::operator>=(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
	if(c1.getEmount()>= c2.convert(c1.getUnitV())){ return true;}
	else{return false;}
}

bool ariel::operator<=(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
{
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount()<= c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

bool ariel::operator>(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) {
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                 throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount() > c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

bool ariel::operator<(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) {
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }
        if(c1.getEmount() < c2.convert(c1.getUnitV())){ return true;}
        else{return false;}
}

//
const ariel::PhysicalNumber ariel::operator-(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
{
	if(!c1.getUnit().sameDim(c2.getUnitV()))
	{
		throw std::out_of_range("The dimensions are diffrent");
	}

	return ariel::PhysicalNumber(c1.getEmount()-c2.convert(c1.getUnitV()),c1.getUnit());
	
}

const ariel::PhysicalNumber ariel::operator+(const ariel::PhysicalNumber& c1, const ariel::PhysicalNumber& c2) 
{
        if(!c1.getUnit().sameDim(c2.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }

        return ariel::PhysicalNumber(c1.getEmount() + c2.convert(c1.getUnitV()),c1.getUnit());

}

//unary
const ariel::PhysicalNumber ariel::PhysicalNumber::operator-()  const
{
        return ariel::PhysicalNumber(-(this->getEmount()) , this->getUnit());
}

const ariel::PhysicalNumber ariel::PhysicalNumber::operator+() const
{
        return ariel::PhysicalNumber(this->getEmount() , this->getUnit());
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator+=(const ariel::PhysicalNumber& other) 
{
	if(!getUnit().sameDim(other.getUnitV()))
	{
		throw std::out_of_range("The dimensions are diffrent");
	}
	this->setEmount(this->getEmount()+other.convert(this->getUnitV()));
        return *this; // for call chaining
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator-=(const ariel::PhysicalNumber& other)
{

        if(!this->getUnit().sameDim(other.getUnitV()))
        {
                throw std::out_of_range("The dimensions are diffrent");
        }
        this->setEmount(this->getEmount() - other.convert(this->getUnitV()));
        return *this; // for call chaining
}

  // prefix increment:
ariel::PhysicalNumber& ariel::PhysicalNumber::operator++()
{
        this->setEmount((this->getEmount())+1);
        return *this;
}

    // postfix increment:
const ariel::PhysicalNumber ariel::PhysicalNumber::operator++(int dummy_flag_for_postfix_increment) 
{
        ariel::PhysicalNumber copy = *this;
         this->setEmount((this->getEmount())+1);
      return copy; 
}

ariel::PhysicalNumber& ariel::PhysicalNumber::operator--()
{
        this->setEmount((this->getEmount())-1);
        return *this;
}

    // postfix increment:
const ariel::PhysicalNumber ariel::PhysicalNumber::operator--(int dummy_flag_for_postfix_increment)
{
        ariel::PhysicalNumber copy = *this;
         this->setEmount((this->getEmount())-1);
      return copy;
}

ostream& ariel::operator<< (ostream& os, const ariel::PhysicalNumber& c) {
 
  //equivalent to:
   
    os << c.getEmount()<<c.getUnit().values[c.getUnitV()];
     return os;
}


static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
   char actualChar;
    input >> actualChar;
    if (!input) return input;

    if (actualChar!=expectedChar) 
        // failbit is for format error
        input.setstate(ios::failbit);
    return input;
}

void ariel:: PhysicalNumber:: getNumber(istream& input)
{
	double val=0;
	double afterP=0;
	bool negative=false;
	char ch = input.get();
	if (ch == EOF)
		return;
	if (isdigit(ch)|| ch == '-')
	{
		if(ch == '-')
		{
			negative= true;
		}
		else
		{
			val = ch - '0';
		}
		for (;;)
		{
			ch = input.get();
			if (!isdigit(ch))
				break;
			val *= 10;
			val += ch - '0';
		}
		if(ch=='.')
		{
			for (int i=10;;i=i*10)
			{
				ch = input.get();
				if (!isdigit(ch))
					break;
				afterP= ch-'0';
				afterP /=i;
					
					
				val += afterP;
			}
		}
		if(negative)
			val=(-1)*val;
    // do something with val
	}
	
	
	this->setEmount(val);
	//return input;
}	

void ariel:: PhysicalNumber:: getString(istream& input)
{
	
	string unit="";
	for (;;)
	{
		char ch = input.get();
		if (ch == EOF)
			return;
	
		if (ch >= 'a' && ch <= 'z')
		{
			unit +=ch;
		}
		else
			break;
		
	}
	
	
	this->setUnit(Unit(unit));
	//return input;
}	


//istream& getTipe(istream& input, ariel::PhysicalNumber& c)
//{
	

istream& ariel::operator>> (istream& input, ariel::PhysicalNumber& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------
   double new_re;
   string unit;
	//c.getNumber(input);
	
	//c.getString(input);
    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> new_re)) ||
         (!(input >> unit)) )  {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    }
	else 
	{
       c.setEmount(new_re);
	   c.setUnit(unit);
    }

    return input;
}

