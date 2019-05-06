//AUTHOR: Tyler Yamashiro
//FILENAME: seer.cpp
//DATE:5/15/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION:
 * Ths is a class called seer that returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.
 */
/*CLASS INVARIANT:
 * The magicNumber is a stable unsigned int that is greater than
 * zero and less than ten.
 * The class automatically generates a stable message upon
 * creation.
 * The class will toggle between on or off every magicNumber
 * value turns.
 * An off object will return an empty string an on object
 * will return the message.
 */
/*IMPLEMENTATION INVARIANT:
 * The default magicNumber variable is set using
 * the DEFAULTMAGICNUM const.
 * The default message and the string returned
 * during off state can be changed by changing
 * the corresponding const string variables.
 */
#include "seer.h"
//DESCRIPTION:Constructor for the seer class can take in a unsigned int
//that can be used to set the magicNumber variable.  Instanciates all the
//variables that are declared and checks to see if the paramater is valid
//POSTCONDITION: seer object is created and values are set
seer::seer(){
    magicNumber = DEFAULTMAGICNUM;
    magicCounter = 0;
    stateSeer = true;
    message = DEFAULTMESSAGE;
}

//DESCRIPTION:Constructor for the seer class can take in a unsigned int
//that can be used to set the magicNumber variable.  Instanciates all the
//variables that are declared and checks to see if the paramater is valid
//if not valid a default magic number will be set
//POSTCONDITION: seer object is created and values are set
seer::seer(unsigned int magicNum){
    if (magicNum < SINGLEDIGITCHECK && magicNum > ZERO)
        magicNumber = magicNum;
    else
        magicNumber = DEFAULTMAGICNUM;
    magicCounter = 0;
    stateSeer = true;
    message = DEFAULTMESSAGE;

}

//Description:Copy Constructor for the seer class creates a new object
//that is a copy of the seer object passed into the copy constructor
//Precondition:A seer object exists to be copied
//Postcondition: A seer object that is an exact copy of the object passed
//in is created.
seer::seer (const seer& prevSeer){
  magicNumber = prevSeer.magicNumber;
  stateSeer = prevSeer.stateSeer;
  message = prevSeer.message;
  magicCounter = prevSeer.magicCounter;
}

//Description:Overloaded assignment operator for the  seer class
//creates a copy of the right and side of the assignment operator
//and makes the left side a copy
//Precondition:Two seer objects exist one to be copied and
//one to be copied to
//PostCondition:The information and state of the seer object on the
//left hand side becomes the same as the seer object on the right
//hand side
seer& seer::operator=(const seer& rhs){
  if(this != &rhs){
  magicNumber = rhs.magicNumber;
  stateSeer = rhs.stateSeer;
  message = rhs.message;
  magicCounter = rhs.magicCounter;
  }
  return *this;
}

//Description: destructor for the seer class. There is no virtual
//memory but is callled as virtual in case derived classes want
//to overwrite it
//Precondition:Seer object exists
//Postcondition:Reclaims resources of the seer object.
seer::~seer(){}

//DESCRIPTION: Pings the object with a request.  The
//object returns either the message or an empty string
//based on whether it is on or off respectively.
//The object turns on and off every nth request where
//n is equal to the magicNumber variable
//PostCondtition:Either the message or empty string is
//returned and the state may flip between on and off
//dependent on magicNumber.
std::string seer::Request()
{
    if (magicCounter % magicNumber == ZERO && magicCounter != ZERO)
        stateSeer ^= true;
    if (stateSeer)
    {
        magicCounter++;
        return message;
    }
    else
    {
        magicCounter++;
        return OFFSTATESTRING;
    }

}

void seer::replaceRequest(std::string replacement){}
