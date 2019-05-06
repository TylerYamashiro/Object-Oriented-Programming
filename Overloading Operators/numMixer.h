//AUTHOR: Tyler Yamashiro
//FILENAME: numMixer.h
//DATE: 5/15/18
//REVISION HISTORY: VERSION 1.0
//PLATFORM(compiler,version):
/*DESCRIPTION:
 *  This class is a number mixer at the begining when the object is initiated
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
 */

 /*ASSUMPTIONS: The object is active and in state mix when initiated.
  * The way the state changes is not random
  * but by programmer choice.  The object has a max threshHold of 10
  * pings after 10 pings the object becomes inactive.
  * The initial number pool will be held in an array
  * with a default of 10 numbers.
  * When pinged in mix state will return all numbers in the pool.
  */
  /*Class Invariant: numMixer:
   * Pool of numbers is stable unless seed is changed when
   * constructor is called. When inactive ping returns null.
   * When active ping returns an integer array.  Object can be
   * re-created to have active again.
   The +, +=, - , -=, =, ==, and != operations
   *are supported through the class.  The +, +=, -, -= operators affect the
   *numMixer object initial number pool by adding or subtracting the
   *each number in the pool with the corresponding number in the other
   *object.  The == and != compare the two numMixer objects and return
   *true or false based on if the pools of both objects are identical or not.
   *Only numMixer Objects may be used with the overloaded operators
   *This is done to prevent mix mode operations and keep encapsulation.
   */
   /* Interface Invariant: numMixer:
    * Instantiation does not require any arguments.  An optional argument
    * exists named seed that can spawn a different pool of numbers than
    * the default.  In the argument constructor 2 arguments can be passed.
    * the first is the size of the initial pool of numbers the second
    * is the seed for generation. An inactive object will not become
    * active again.  Inactive objects return null.  Object states
    * for Odd, Even and Mix may be set by the user using given setter
    * functions. State is Mix by default
    * Integers are returned via integer arrays.
    The +, +=, - , -=, =, ==, and != operations
    *are supported through the class.  The +, +=, -, -= operators affect the
    *numMixer object initial number pool by adding or subtracting the
    *each number in the pool with the corresponding number in the other
    *object.  The == and != compare the two numMixer objects and return
    *true or false based on if the pools of both objects are identical or not.
    */

#pragma once
using namespace std;
class numMixer{
protected:
  //Private class members=-------------------------------------
  //default seed for generating number pool
  const static int POOLSEED = 1;
  const static int THRESHMAX = 10;
  const static int STORELENGTH = 10;
  //seed used for numbers generated by the build store object
  int seedPool;
  int threshHold;
//  int* result;
  int stateChangeCounter;
  int* store;
  //int* returnPing;
  enum State { Odd, Even, Mix };
  State currentState;
  //the length of the array that holds the starting number
  //designated by user
  unsigned int userLength;

  //Description: Fills the array that acts as a pool of numbers with
  //a fibbonacci sequence like functions that uses the seed
  //provided or a default seed as beginning point
  //Precondtion: A array has been successfully created as part of
  //the numMixer object that has greater than zero capacity
  //Postcondition: The array is filled with seeded numbers
  void buildStore();

  //Description: Increments the threshHold variable.
  void incThreshHold();

  //Description: Depending on state of the object return odd, even,
  //or mixed integers from the number pool.
  //via an integer pointer that pionts to dynamic
  //array.  If the object is not active
  //return null. If there are no evens or are no odds returns null.
  //Precondition: Array filled with integers exists as a pool of integers
  //Postcondition: Array is returned depending on the state
  //of the object or null is returned if the ping is to return nothing
  //or fail
  int* returnPingHelper(int& getSize);



public:


  //Description: Default constrctor for the object.  Creates
  //the array to hold numbers and fills it using buildStore()
  //Precondition: A numMixer object is to be made
  //Postcondition: A numMixer object is made
  numMixer();
  //Description:   The user can input an int argument to change the seed
  //of the origonal pool of numbers
  //Precondition: Seed must be greater than zero
  //Postcondition: Object will have an array with integers according to
  //a provided or default seed
  numMixer(int seed );


  //Description: Copy Constructor that takes a numMixer object as
  //an argument and copies its number pool, state, and threshHold
  //Precondition: A numMixer object exists and is to be copied
  //PostCondition: A copy of the numMixer object is created
  numMixer(const numMixer& prevNumMixer);


  //Description: Overloaded assingment operator that
  //takes two existing numMixer objects and makes the left hand
  //side equal to the right hand side via deep Copy
  //Preconditon: Two numMixer objects exists
  //Postcondition:Will make a copy of the object to the right of
  //the assignment operator using the object to the left.
  numMixer& operator=(const numMixer& rhs);

  //Description:Overloaded Addition Operator:  Each element of the
  //inital starting poolis added  to the corresponding element of the numMixer
  //object on the other side of the operator.
  //Precondition:Both objects must be numMixer objects
  //Postcondition:Copy is returned that has a pool whos elements
  //is the sum of both elements in the argument pools.
  numMixer operator+(const numMixer& b);
  //Description:Overloaded Addition Assignment Operator:  Each element of the
  //inital starting pool is added to the corresponding element of the numMixer
  //object on the other side of the operator. Replacest the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be numMixer objects
  //Postcondition:Left side object pool is replaced with a  pool whos elements
  //is the sum of both elements in the argument pools.
  numMixer& operator+=(numMixer& b);
  //Description:Overloaded Subtraction Operator:  Each element of the
  //inital starting pool is
  //subtracted to the corresponding element of the numMixer
  //object on the other side of the operator.
  //Precondition:Both objects must be numMixer objects
  //Postcondition:Copy is returned that has a pool whos elements
  //is the subtraction of both elements in the argument pools.
  numMixer operator-(const numMixer& b);
  //Description:Overloaded subtraction Assignment Operator: 
  //Each element of the
  //inital starting pool is subtracted from the corresponding
  // element of the numMixer
  //object on the other side of the operator. Replacest the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be numMixer objects
  //Postcondition:Left side object pool is replaced with a  pool whos elements
  //is the subtraction of both elements in the argument pools.
  numMixer& operator-=(const numMixer& b);
  //Description: Compares all elements in the pool and checks if they are
  //identical.  If all elements are identical true is returned else false.
  //Precondition:NumMixer object on both sides of the operator
  //Postcondition:True false value returned based on if the Pool is identical
  bool operator==(const numMixer& b);
  //Description: Compares all elements in the pool and checks if they are not
  //identical.  If all elements are not identical true is returned else false.
  //Precondition:NumMixer object on both sides of the operator
  //Postcondition:True false value returned based on if the Pool is identical
  bool operator!=(const numMixer& b);

  //Description: Destructor for the numMixer class reclaims allocated memory
  //at the addresses not returned by the ping() function.   The ownership of
  //the memory returned by the ping function is transfered when the ping
  //function returns and the deallocation of that memory is the
  //responsibility of the application programmer.
  virtual~numMixer();

  //Description: Calls return ping to return an array of ints
  //depending on the state of the object.  Increases the threshold by one
  //and returns the result of returnPing.  If the object is inactive it
  //returns NULL  The user must track the returned pointer that stores
  //address of the array in memory in order to delete it to prevent memory
  // leaks this must be done with each ping call.  The user must also then
  //call delete for each ping called.  Takes in an adress of an int in to
  //return the size of the ping by reference
  //Precondition: An array of numbers exists and is filled with integers
  //Postcondition: Reclaims memory of previous ping call and
  //returns a pointer to the newly allocated memory for an integer array
  int* ping(int& getSize);

  //Description: Set the currentStat to Odd and increment the
  //stateChangeCounter
  void setStateOdd();

  //Description: Set the currentState to Mix and increment the
  //stateChangeCounte
  void setStateEven();

  //Description: Set the currentState to Mix and increment the
  //stateChangeCounter
  void setStateMix();

  //Description: Returns the number of times the state has changed.
  int returnStateCount();

  //Description: Returns a bool based of in the threshHold
  //is greater than or equal to the maximum threshHold
  bool isActive();

};
