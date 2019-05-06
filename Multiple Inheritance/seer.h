//AUTHOR: Tyler Yamashiro
//FILENAME: seer.h
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
/*INTERFACE INVARIANT:
 * The constructor may take unsigned int greater than zero
 * and less than ten as an argument.  If the argument is not
 * valid the constructor will replace it with the default
 * magicNumber value.
 * If the object is in an off state it will return the
 * empty string.
 * If in on state the message will be returned.
 */
#include <string>
#pragma once
class seer{
protected:
  const constexpr static char* OFFSTATESTRING = "";
  const static unsigned int SINGLEDIGITCHECK = 10;
  const static int ZERO = 0;
  const constexpr static char*
    DEFAULTMESSAGE = "I can't actually see the future.";
  const static unsigned int DEFAULTMAGICNUM = 3;
  bool stateSeer;
  unsigned int magicNumber;
  std::string message;
  unsigned int magicCounter;

public:
  //DESCRIPTION:Constructor for the seer class assigns a defaut
  //magic number
  //POSTCONDITION: seer object is created and values are set
  seer();

  //DESCRIPTION:Constructor for the seer class must take in a unsigned int
  //that can be used to set the magicNumber variable.  Instanciates all the
  //variables that are declared and checks to see if the paramater is valid
  //if not valid a default magic number will be set
  //POSTCONDITION: seer object is created and values are set
  seer(unsigned int magicNum);

  //Description:Copy Constructor for the seer class creates a new object
  //that is a copy of the seer object passed into the copy constructor
  //Precondition:A seer object exists to be copied
  //Postcondition: A seer object that is an exact copy of the object passed
  //in is created.
  seer(const seer& prevSeer);
  //Description:Overloaded assignment operator for the  seer class
  //creates a copy of the right and side of the assignment operator
  //and makes the left side a copy
  //Precondition:Two seer objects exist one to be copied and
  //one to be copied to
  //PostCondition:The information and state of the seer object on the
  //left hand side becomes the same as the seer object on the right
  //hand side
  seer& operator=(const seer& rhs);
  //Description: destructor for the seer class. There is no virtual
  //memory but is callled as virtual in case derived classes want
  //to overwrite it
  //Precondition:Seer object exists
  //Postcondition:Reclaims resources of the seer object.
  virtual ~seer();
  //DESCRIPTION: Pings the object with a request.  The
  //object returns either the message or an empty string
  //based on whether it is on or off respectively.
  //The object turns on and off every nth request where
  //n is equal to the magicNumber variable
  //PostCondtition:Either the message or empty string is
  //returned and the state may flip between on and off
  //dependent on magicNumber.
  virtual std::string Request();

  //Description: Holder for ReplaceVoid function to support heterogenous
  //collections
  virtual void replaceRequest(std::string replacement);


};
