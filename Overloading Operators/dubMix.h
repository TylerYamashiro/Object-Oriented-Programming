//AUTHOR: Tyler Yamashiro
//FILENAME: dubMix.h
//DATE:5/29/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION: This class called dubMix has two numMixer objects encapsulated
 * within it.  The dubMixer can be pinged and a response is returned based
 * on the state the object is in.  If in 'First' it will ping the first
 * numMixer object and return the result, 'Second' will ping the second,
 * 'Interleaved' will interleave the returned into a single array to
 * be returned, 'FCatS' will concatenate the first and second numMixer
 * objects and eliminate duplicate and return the results.  All results are
 * returned as an array.  Addition states are Odd, Even, and Mix which change
 * the result of the type of numbers returned makeing them Odd,Even and Mix
 * respectively.  By default the numMixer objects are in an Mix state as
 * according to the numMixer documentation.
 */
/*ASSUMPTIONS: It is assumed that the numMixer class is compiled with
 * this one in order to use its objects and methods.
 * dubMix is in the default Mix state when created.
 */
/*Class Invariant: dubMix object:
 * Depending on the active State of the numMixer objects
 * witin the numMixer objects pings to state described in the ping
 * functions may return null.  Creating a new instance of the dubMix
 * will refresh the state.  The enum Control states work with all the
 * numMixer States of Odd, Even and Mixed. Pings are returned via
 * integer arrays. The default state is First and Mix states can
 * be set and do not change on their own.
 The +, +=, - , -=, =, ==, and != operations
 *are supported through the class.  The +, +=, -, -= operators affect the
 *numMixer objects number pools by adding or subtracting the
 *each number in the pool with the corresponding number in the other
 *object within the dubMix object.
  *Only dubMix Objects may be used with the overloaded operators
  *This is done to prevent mix mode operations and keep encapsulation
  The == and != compare the two dubMix objects and return
 *true or false based on if the pools of both objects numMixer objects
 *are identical or not.
 *Only dubMix Objects may be used with the overloaded operators
 * Interface Invariant: dubMix object:
 * Intantiation may use parameters but does not require it.  If a parameter
 * is passed it must be a positive integer.  Integers are returned
 * via and integer array. State of the object can be changed via setters
 * for both the dubMixer states mentioned and numMixer states contained
 * in the dubMixer. The default state is First and Mix states can
 * be set and do not change on their own.
 *
 */
#include "numMixer.h"
#include <vector>
class dubMix{
private:
  enum Control { First, Second, Interleaved, FCatS };
  Control ctl;
  const int NUMBEROFMIXERS = 2;
  const int FIRSTMIXER = 0;
  const int SECONDMIXER = 1;
  const int EVENCHECK = 2;
  const int ZERO = 0;
  std::vector<numMixer> *arr;

  //DESCRIPTION: Pings the first object in the array of type
  //numMixer.  It returns the result as an integer array.
  //It will return null if the array pinged is not active
  //or there are no numbers to complete the request
  int* pingFirst(int& getSize);

  //DESCRIPTION: Pings the second object in teh array of
  //type numMixer. It returns the result as an integer array.
  //It will return null if the array pinged is not active
  //or there are no numbers to complete the request
  int* pingSecond(int& getSize);

  //DESCRIPTION: Pings both numMixers and stores the results in
  //integer arrays. The results are inserted into a third
  //array alternating between the first and second object.
  //If an array runs out of items to insert the other array
  //inserts until it is finished. The new array is returned.
  int* pingInter(int& getSize);

  //DESCRIPTION:Pings the first and second numMixer and stores
  //the result into respective integer arrays.  Then both are
  //copied into a third array and duplicates are eliminated.
  //The resulting array is returned by the function.
  int* pingCat(int& getSize);



public:
  //DESCRIPTION: The default constructor.  It creates an array of
  //size NUMBERMIXERS and fills them with new numMixer objects
  //The enum type variable ctl is insantiated to 'First'
  //Postcondition: State of object is in 'First' two numMixer
  //objects are stored in an array. Each numMixer object
  //starts in the Mix state.
  dubMix();
  //DESCRIPTION: The Copy Constructor takes a dubMix object as a
  //parameter and creates a deep copy of that object.  The
  //state and the numMixer objects in the array along with each
  //ones state is copied into the new object
  //Precondition: A dubMixer object must exist to be passed in .
  //PostCondition: A new dubMix object is created that is in an
  //identical state as the parameter dubMix object.
  dubMix(const dubMix& param);
  //Description: Overloaded assingment operator that
  //takes two existing dubMix objects and makes the left hand
  //side equal to the right hand side via deep Copy
  //Preconditon: Two dubMixer objects exists
  //Postcondition:Will make a copy of the object to the right of
  //the assignment operator using the object to the left.
  dubMix& operator=(const dubMix& rhs);
  //Description:Overloaded Addition Operator:  Each element of the
  //inital starting pool is added  to the corresponding element of the numMixer
  //objects in the other dubMix object on the other side of the operator
  //Precondition:Both objects must be dubMix objects
  //Postcondition:copy of a dubMix object is returned whos held numMIxer
  //objects have each element summed with the corresponding numMixer
  //objects in the other dubMix object.
  dubMix operator+(const dubMix& b);
  //Description:Overloaded Addition Assignment Operator:  Each element of the
  //inital starting pool is added to the corresponding element of the numMixer
  //objects in the dubMix object  on the other side of the operator.
  //Replacest the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be dubMix objects
  //Postcondition:Left hand side held numMixer objects pools are replaced
  //with the new values of the addition of the right hand and left hand side
  //held numMixer objects.
  dubMix& operator +=(const dubMix& b);
  //Description:Overloaded Subtraction Operator:  Each element of the
  //inital starting pool is subtracted from the
  //corresponding element of the numMixer
  //objects in the other dubMix object on the other side of the operator
  //Precondition:Both objects must be dubMix objects
  //Postcondition:copy of a dubMix object is returned whos held numMIxer
  //objects have each element subtracted with the corresponding numMixer
  //objects in the other dubMix object.
  dubMix operator-(const dubMix& b);
  //Description:Overloaded Subtraction Assignment Operator:
  //Each element of the
  //inital starting pool is subtracted from
  //the corresponding element of the numMixer
  //objects in the dubMix object  on the other side of the operator.
  //Replaces the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be dubMix objects
  //Postcondition:Left hand side held numMixer objects pools are replaced
  //with the new values of the subtraction
  // of the right hand and left hand side
  //held numMixer objects.
  dubMix& operator-=(const dubMix& b);
  //Description: Compares all elements in the pools
  //of held numMixer objects  and checks if they are
  //identical.  If all elements are identical true is returned else false.
  //Precondition:dubMix object on both sides of the operator
  //Postcondition:True false value returned based on if the
  //pools of corresponding held numMix objects are identical.
  bool operator ==(const dubMix& b);
  //Description: Compares all elements in the pools
  //of held numMixer objects  and checks if they are not
  //identical.  If any elements are not identical true is returned else false.
  //Precondition:dubMix object on both sides of the operator
  //Postcondition:True false value returned based on if the
  //pools of corresponding held numMix objects are identical.
  bool operator !=(const dubMix& b);
  //Description:The destructor for the dubMix Class deallocates the
  //memory of the dynamic vector
  //Precondition:dubMix has a vector
  //Postcondition:Deallocates vector memory
  ~dubMix();
  //DESCRIPTION:Calls the private ping helper functions based on
  //the state of the dubMixer object.  Returns the results of
  //the ping helper function.  The helper ping functions cover
  //the "First, Second, Interleaved, and FCatS" states.
  //The type of integers returned for example: Odd, Even, or Mix
  //can be set and is determined by the state of the numMixer
  //objects.
  //Precondition:The object must be in the 'First' state
  //as well as the first object in the numMixer array must
  //must be in an active state for the pingFirst() helper
  //to be called. For the pingSecond() function to be
  //called the state must be 'Second' and the second object
  //in the array be active.  For the pingInter() function
  //the state must be in 'Interleaved' and both the
  //first and second numMixer objects be active.
  //For the pingCat() function the state must be in 'FCatS'
  //and both numMixer objects in the array must be active.
  //PostCondition: The results of each helper function will
  //be returned by ping() in the form of an integer arrray
  //if each helper functions test passs. Only one helper
  //may will be called per ping() call.  If the state
  //of the dubMixer object is valid for example
  //currentState = 'First' however the active condition is
  //not fufilled ping() will return null.  The user must track and
  //deallocate the memory of the returned pointer.
  int* ping(int& getSize);

  //DESCRIPTION: Set the emum Control ctl variable to
  //state 'First'
  //PostCondition:Object set to First state.
  void setFirst();

  //DESCRIPTION: Set the emum Control ctl variable to
  //state 'Second'
  //PostCondition: Object set to second state
  void setSecond();
  //DESCRIPTION: Set the emum Control ctl variable to
  //state 'Interleaved'
  //Postcondition: sets state to Interleaved
  void setInter();

  //DESCRIPTION: Set the emum Control ctl variable to
  //state 'FCatS'
  //PostCondition:set state to FCatS
  void setCat();

  //DESCRIPTION: Sets the state of both numMixer objects
  //in the numMixer array to Odd
  //Postcondition:The numMixer objects in dubmixer are set to odd
  void setOdd();
  //DESCRIPTION: Sets the state of both numMixer objects
  //in the numMixer array to Even
  //PostCondition:The numMixer objects in dubMix are set to even
  void setEven();
  //DESCRIPTION: Sets the state of both numMixer objects
  //in the numMixer array to Mix
  //PostCondition:The numMixer objects in dubMix are set to Mix
  void setMix();
};
