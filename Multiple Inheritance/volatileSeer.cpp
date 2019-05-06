//AUTHOR: Tyler Yamashiro
//FILENAME: volatileSeer.cpp
//DATE:5/15/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION:
 * Ths is a class called volatileSeer that returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.  THe request can be rejected randomly.  The messege
 * returned can also be changed.  This class is a derived class
 * of the seer class.
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
 * Request can be rejected.
 * Message can be overwritten
 */
/*IMPLEMENTATION INVARIANT:
 * The default magicNumber variable is set using
 * the DEFAULTMAGICNUM const.
 * The defaulet regectGen value is set using
 * DEFAULTREJECTGEN.
 * The default message when object is rejected is
 * set in REJECTED const variable.
 * The default message and the string returned
 * during off state can be changed by changing
 * the corresponding const string variables.
 */
#include "volatileSeer.h"

//DESCRITPTION: Creates the volatileSeer object which is a derived class
//of the seer class.  It is initialized in the same way setting the
//rejectRandGen variable using a default value
//the default is given as DEFAULTREGECTGEN.
//PostCondition:Create volatileSeer object
volatileSeer::volatileSeer(): seer()
{
    rejectRandGen = DEFAULTREJECTGEN;
}

//DESCRITPTION: Creates the volatileSeer object which is a derived class
//of the seer class.  It is initialized in the same way with the addition
//of a new argument rejectGen which is used to seed the rejection
//mechanism the default is given as DEFAULTREGECTGEN.
//Preconditon:User must provide rejectGen and magicNumber
//variables.
//PostCondition:Create volatileSeer object
volatileSeer::volatileSeer(unsigned int rejectGen,
unsigned int magicNum) : seer(magicNum)
{
  rejectRandGen = rejectGen;
}

//DESCRIPTION: Copy constructor for the volatileSeer object.
//utilizes the parent copy constructor as well as
//copies the rejectRandGen variable from origonal object
//Precondition: A volatileSeer object exists
//Postconditin: An copy of the origonal volatileSeer object is created
volatileSeer::volatileSeer(const volatileSeer& original):seer(original)
{
    rejectRandGen = original.rejectRandGen;
}

//Description:Overloaded assignment operator for the
//volatileSeer class
//creates a copy of the right and side of the assignment operator
//and makes the left side a copy
//Precondition:Two seer objects exist one to be copied and
//one to be copied to
//PostCondition:The information and state of the seer object on the
//left hand side becomes the same as the tmSeer object on the right
//hand side
volatileSeer& volatileSeer::operator=(const volatileSeer& rhs)
{
  if(this != &rhs){
  magicNumber = rhs.magicNumber;
  stateSeer = rhs.stateSeer;
  message = rhs.message;
  magicCounter = rhs.magicCounter;
  rejectRandGen = rhs.rejectRandGen;
  }
  return *this;
  }

  //DESCRIPTION: Takes an string argument and replaces the current
  //message
  //Precondtion:Argument string to replace current string
  //PostCondition: message variable changed to that of argument
void volatileSeer::replaceRequest(std::string replacement)
{
    message = replacement;
}

//DESCRIPTION: Pings the object with a request.  The
//object returns either the message or an empty string
//based on whether it is on or off respectively.
//The object turns on and off every nth request where
//n is equal to the magicNumber variable.
//May reject a request and return "REJECTED"
//PostCondtition:Either the message or empty string is
//returned and the state may flip between on and off
//dependent on magicNumber. May return REJECTED
//if the request is rejected.
 std::string volatileSeer::Request()
{
    if (magicCounter % rejectRandGen == ZERO)
    {
        magicCounter++;
        return REJECTED;
    }
    return seer::Request();
}
