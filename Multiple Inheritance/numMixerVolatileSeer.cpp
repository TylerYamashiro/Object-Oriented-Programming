//AUTHOR: Tyler Yamashiro
//FILENAME: numMixerVolatileSeer.cpp
//DATE: 5/15/18
//REVISION HISTORY: VERSION 1.0
//PLATFORM(compiler,version):
/*DESCRIPTION:
 *  This class is a number mixer as well as  a numMixerVolatileSeer
 *  It inherits both of the
 * Parents functionality I will describe both aspects in terms of the functions
 * Inherited by its parents.  The functionality of the two does not affect the
 * other including active states. I.E. The numMixer functionality can be
 * inactive BUT the volatileSeer functionality may still be active.
 * NumMixer:
 *  At the begining when the object is initiated.
 *  the default maximum amount of numbers is 10.  A parameter can be passed
 *  into the constructor to increase the pool of numbers created
 *  additionally  These numbers are stored in an array.
 *  The object starts in a mixed state return all odd and even
 *  numbers when pinged.
 *  When the object is pinged if the state is odd it returns all odd numbers.
 *  If even it returns all even numbers as an array. If the object
 *  is active it will
 *  return the numbers as an array if it is not active return null.
 *  The state of the object can be changed to even, odd, and mixed
 *  by calling the appropriate member functions.
 *  The state change is counted and the user can
 *  call a function to get the number of times the
 *  state of the object has changed.
 *volatileSeer:
 * returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.  THe request can be rejected randomly.  The messege
 * returned can also be changed.  This class is a derived class
 * of the seer class.
 */

 /*ASSUMPTIONS:
  * NumMixer:
  *   The object is active and in state mix when initiated.
  *   The way the state changes is not random
  *   but by programmer choice.  The object has a max threshHold of 10
  *   pings after 10 pings the object becomes inactive.
  *   The initial number pool will be held in an array
  *   with a default of 10 numbers.
  *   When pinged in mix state will return all numbers in the pool.
  *volatileSeer:
  *   Seer has a set default default message
      The object has a internally generated way to toggle off and on.
  */
  /*Class Invariant:
   *NumMixer:
   * Pool of numbers is stable unless seed is changed when
   * constructor is called. When inactive ping returns null.
   * When active ping returns an integer array.  Object can be
   * re-created to have active again.
   *volatileSeer
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
  * NumMIxer:
  * The default seed can be changed using POOLSEED const int. The
  * default threshHold can be changed using THRESHMAX.  The default
  * number pool size can be changed by changing STORELENGTH.  The number
  * generator is located in buildStore() and is a basically a fibbanacci
  * sequence that starts at the seed given. Active determined by comparing
  * threshHold and THRESHMAX in isActive()
  *volatileSeer:
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

#include "numMixerVolatileSeer.h"
//Description: Default constrctor for the object.  Creates
//the array to hold numbers and fills it using buildStore()
//It also sets the magic number to determine seer
//functionality toggling.
//The rejectRandGen variable using a default value
//the default is given as DEFAULTREGECTGEN.
//Precondition: A numMixerVolatileSeer object is to be made
//Postcondition: A numMixerVolatileSeer object is made
numMixerVolatileSeer::numMixerVolatileSeer():
numMixerSeer(),volatileSeer(){}
//DESCRIPTION:Constructor for the class must take in a unsigned int
//that can be used to set the magicNumber variable.  Instanciates all the
//variables that are declared and checks to see if the paramater is valid
//if not valid a default magic number will be set
//The user must also  input an int argument to change the seed
//of the origonal pool of numbers the number must be greater
//than zero as well as give an rejectGen variable wich will
//seed the rejection varaible
//PreconditonConstructor with three arguments are callled
//Postconditon:Object is created with
numMixerVolatileSeer::numMixerVolatileSeer(int seed,unsigned int magicNum,
  unsigned int rejectGen):numMixerSeer(seed, magicNum),
  volatileSeer(rejectGen,magicNum){}
  //Description: Copy Constructor for the class takes in by reference
  //a numMixeVolatileSeer object and creates a copy of it
  //Preconditon: A numMixeSeer objects exists to be passed in
  //Postcondition: A new copy of the numMixerSeer object is created
numMixerVolatileSeer::numMixerVolatileSeer(const numMixerVolatileSeer&
  original): numMixerSeer(original),volatileSeer(original){}
  //Description:Overloaded assignement operator for the class.
  //Creates a copy of the numMixerVolatileSeer object on the right
  //side of the assignment operator and copies its values
  //and state to the numMixerVolatileSeer object on the left
  //Precondtion:Two numMixerVolatileSeer objects exist that are different
  //Postcondition: The numMixerVolatileSeer object on the left becomes
  //a copy of the right
numMixerVolatileSeer& numMixerVolatileSeer::operator=
(const numMixerVolatileSeer& rhs){
  if(this != &rhs){
    magicNumber = rhs.magicNumber;
    stateSeer = rhs.stateSeer;
    message = rhs.message;
    magicCounter = rhs.magicCounter;
    rejectRandGen = rhs.rejectRandGen;
    userLength = rhs.userLength;
    seedPool = rhs.seedPool;
    delete[] store;
    store = new int[userLength];
    threshHold = rhs.threshHold;
    currentState = rhs.currentState;
    stateChangeCounter = rhs.stateChangeCounter;
    for (unsigned int i = 0; i < userLength; i++)
    {
        store[i] = rhs.store[i];
      }
  }
  return *this;
}
    //Description: Deallocates the dynamic array created.
numMixerVolatileSeer::~numMixerVolatileSeer(){
  //delete[] store;
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
std::string numMixerVolatileSeer::Request(){
  return volatileSeer::Request();
 }

 //Description: Placeholder for replaceRequest
 void numMixerVolatileSeer::replaceRequest(std::string replacement){
   volatileSeer::replaceRequest(replacement);
 }
