//AUTHOR: Tyler Yamashiro
//FILENAME: multiMix.h
//DATE: 5/29/18
//REVISION HISTORY:Version 1.0
/*DESCRIPTION:The multiMix class can hold zero to many
 * numMixer objects. This object can change states from Odd, Even, and Mix.
 * When pinged multiMix will return all integers from all numMixer
 * objects stored within it that meet the qualifications of each state.
 * Odd will return odd integers, Even will return even integers, and
 * Mix will return a mix of odd and even integers that are non prime. Objects of
 * type numMixer can also be added or removed from the multiMix object.
 */
 /*ASSUMPTIONS: The multiMix object will be compiled with the numMixer
  * class in order to work. multiMix objects are in Mix state by default
  * Assumes that user inputed amount of object will not be too much for
  * memory.
  */
  /*Class Invariant: multiMix:
   * This object instantiates empty by default.  If numMixer objects are
   * desired supply an unsigned int as a parameter into the constructor.
   * All states can be set manually and do not transition on their own.
   * The default state is Mix.  This state can be changed with setter
   * functions implemented below.
   * Inactive numMixer objects will not
   * contribute to ping output. Objects added will be added to the end
   * of the list. Pinging an empty multiMix object will result in null
   * as well as pinging a multiMix object with only inactive numMixer
   * objects will be null.
   *The +, +=, - , -=, =, ==, and != operations
   *are supported through the class.  The +, +=, -, -= operators affect the
   *numMixer objects number pools by adding or subtracting the
   *each number in the pool with the corresponding number in the other
   *object within the multiMix object.
    *Only multiMix Objects may be used with the overloaded operators
    *This is done to prevent mix mode operations and keep encapsulation
    The == and != compare the two multiMix objects and return
   *true or false based on if the pools of both object's numMixer objects
   *are identical or not.
   *Only multiMix Objects may be used with the overloaded operators
   *The overloaded operators with the exception of the assignement
   *Operator may only be used if the multiMIx object contains at leas
   *One numMixer object.
   * Interface Invariant: multiMix:
   * Instantiation does not require any parameters by default however
   * the object will start empty. A parameter may be passed as an
   * unsigned int in order to create object filled with n
   * numMixer objects where n is the parameter provided.
   * removeAt() requires there to be objects and have an int parameter
   * it will return true on success and false on failure.  Add has
   * an optional parameter that will insert the specified amount of
   * objects into the multiMix object when given and unsigned int.
   * Integers are returned via and integer array.
   *The overloaded operators with the exception of the assignement
   *Operator may only be used if the multiMIx object contains at leas
   *One numMixer object.
   */
#include "numMixer.h"
#include <vector>

class multiMix{
private:
  std::vector<numMixer> *list;
  enum State{Odd, Even, Mix};
  State currentState;
  const unsigned int DEFAULTARGAMOUNT = 1;
  const int NONPRIME = 2;

public:
  //DESCRIPTION:The default constructor for the multiMix object
  //that sets the state of the object to Mix. The object starts
  //without any numMixer objects by default
  //It also initializes the List of type numMixer.
  //PostCondition:multiMix object state is Mix
  multiMix();
  //DESCRIPTION:The argunemt constructor for the multiMix class.
  //This acceps an unsigned integer and starts the object with
  //that amount of numMixer objects stored in the list.
  //The current state is also by default in Mix
  //Precondition:Valid unsigned integer as a parameter
  //PostCondition: State of object is in mix as well
  //as the number of numMixer objects created as defined
  //by the argument.
  multiMix(unsigned int amountnumMixers);
  //DESCRIPTION: The Copy Constructor takes a multiMix object as a
  //parameter and creates a deep copy of that object.  The
  //state and the numMixer objects in the vector along with each
  //ones state is copied into the new object
  //Precondition: A multiMixer object must exist to be passed in .
  //PostCondition: A new multiMix object is created that is in an
  //identical state as the parameter multiMix object.
  multiMix(const multiMix& param);
  //Description: Overloaded assingment operator that
  //takes two existing multiMix objects and makes the left hand
  //side equal to the right hand side via deep Copy
  //Preconditon: Two multiMixer objects exists
  //Postcondition:Will make a copy of the object to the right of
  //the assignment operator using the object to the left.
  multiMix& operator= (const multiMix& rhs);
  //Description:Overloaded Addition Operator:  Each element of the
  //inital starting pool is added  to the corresponding element of the numMixer
  //objects in the other multiMix object on the other side of the operator
  //Precondition:Both objects must be multiMix objects who both hold
  //at least one numMixer object.
  //Postcondition:copy of a multiMix object is returned whos held numMIxer
  //objects have each element summed with the corresponding numMixer
  //objects in the other multiMix object.
  multiMix operator+(const multiMix& b);
  //Description:Overloaded Addition Assignment Operator:  Each element of the
  //inital starting pool is added to the corresponding element of the numMixer
  //objects in the multiMix object  on the other side of the operator.
  //Replacest the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be multiMix objects who hold at least
  //one numMixer object
  //Postcondition:Left hand side held numMixer objects pools are replaced
  //with the new values of the addition of the right hand and left hand side
  //held numMixer objects.
  multiMix& operator +=(const multiMix& b);
  //Description:Overloaded Subtraction Operator:  Each element of the
  //inital starting pool is subtracted from the
  //corresponding element of the numMixer
  //objects in the other multiMix object on the other side of the operator
  //Precondition:Both objects must be multiMix objects who both hold
  //at least one numMixer object.
  //Postcondition:copy of a multiMix object is returned whos held numMIxer
  //objects have each element subtracted with the corresponding numMixer
  //objects in the other multiMix object.
  multiMix operator-(const multiMix& b);
  //Description:Overloaded Subtraction Assignment Operator:
  //Each element of the
  //inital starting pool is subtracted from
  //the corresponding element of the numMixer
  //objects in the multiMix object  on the other side of the operator.
  //Replaces the object on the
  //left hand side with the new values.
  //Precondition:Both objects must be multiMix objects who both hold at least
  //one numMixer object.
  //Postcondition:Left hand side held numMixer objects pools are replaced
  //with the new values of the subtraction
  // of the right hand and left hand side
  //held numMixer objects.
  multiMix& operator-=(const multiMix& b);
  //Description: Compares all elements in the pools
  //of held numMixer objects  and checks if they are
  //identical.  If all elements are identical true is returned else false.
  //Precondition:numMix object on both sides of the operator
  //Postcondition:True false value returned based on if the
  //pools of corresponding held numMix objects are identical.
  bool operator ==( const multiMix& b);
  //Description: Compares all elements in the pools
  //of held numMixer objects  and checks if they are not
  //identical.  If any elements are not identical true is returned else false.
  //Precondition:multiMix object on both sides of the operator
  //Postcondition:True false value returned based on if the
  //pools of corresponding held numMix objects are identical.
  bool operator !=( const multiMix& b);
  //Description:The destructor for the multiMix Class deallocates the
  //memory of the dynamic vector
  //Precondition:dubMix has a vector
  //Postcondition:Deallocates vector memory
  ~multiMix();
  //DESCRIPTION:Adds a single numMIxer object to the Multimix
  //sets state of numMixer to match rest.
  //Precondition:Multimix object exists
  //Postcondition: A numMixer object is added to the multiMix object
  void add_back();

  //DESCRIPTiON:Removes a numMixer object from multiMix at
  //the back of the object.
  //Precondition: NumMixer object exists
  //PostCondition: Last numMixer object in the multiMix object is removed
  void remove_back();

  //DESCRIPTION:Set the current state of object to Odd
  //PostCondition:Object now in state Odd
  void setStateOdd();

  //DESCRIPTION:Set the current state of object to Even
  //PostCondition:Object now in state Even
  void setStateEven();
  //DESCRIPTION:Set the current state of object to Mix
  //PostCondition:Object now in state Mix
  void setStateMix();
  //DESCRIPTION:Retuns a bool depending on
  //whether or not the multiMix is empty
  //true is returned if the object is empty
  //false if the object is not empty
  bool isEmpty();

  //DESCRIPTION:Returns an array of integers based on the current state
  //of the multiMix object. Will return ping results from each numMixer
  //object in multiMix as long as it is active.  Odd numbers will be
  //returned if the state is Odd, even for Even, and mix for Mix
  //The user must track the memory of the returned array
  //Precondition:In order for its contents for be returned a numMixer
  //object must be active. The state will be Odd, Even, or Mix.
  //Postcondition:ping() will return the results of all valid
  //numMixer objects in respect to multiMix current stat of Odd,
  //Even, or Mix. If no integers are returned ping() will return null;
  //The getSize parameter is passed by referenced and returns
  //the size of the returned array.
  int* ping(int& getSize);
};
