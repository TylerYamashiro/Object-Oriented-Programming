//AUTHOR: Tyler Yamashiro
//FILENAME: multiMix.cpp
//DATE: 5/29/18
//REVISION HISTORY:Version 1.0
/*DESCRIPTION:The multiMix class can hold zero to many
 * numMixer objects. This object can change states from Odd, Even, and Mix.
 * When pinged multiMix will return all integers from all numMixer
 * objects stored within it that meet the qualifications of each state.
 * Odd will return odd integers, Even will return even integers, and
 * Mix will return a mix of odd and even integers that
 *are non prime. Objects of
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
   * Implementation Invariant:
   * The add() optional parameter can be adjusted using
   * DEFAULTARGAMOUNT const uint, it is currently set at 1.
   * Transitions are external and can be set by the  user.
   */
#include "multiMix.h"
//DESCRIPTION:The default constructor for the multiMix object
//that sets the state of the object to Mix. The object starts
//without any numMixer objects by default
//It also initializes the List of type numMixer.
//PostCondition:multiMix object state is Mix
multiMix::multiMix(){
  currentState = Mix;
  list = new vector<numMixer>;
}
//DESCRIPTION:The argunemt constructor for the multiMix class.
//This acceps an unsigned integer and starts the object with
//that amount of numMixer objects stored in the list.
//The current state is also by default in Mix
//Precondition:Valid unsigned integer as a parameter
//PostCondition: State of object is in mix as well
//as the number of numMixer objects created as defined
//by the argument.
multiMix::multiMix(unsigned int amountnumMixers){
  currentState = Mix;
    list = new vector<numMixer>;
    for(unsigned int i =0; i < amountnumMixers; i++)
      list->push_back(numMixer());
}
//DESCRIPTION: The Copy Constructor takes a multiMix object as a
//parameter and creates a deep copy of that object.  The
//state and the numMixer objects in the vector along with each
//ones state is copied into the new object
//Precondition: A multiMixer object must exist to be passed in .
//PostCondition: A new multiMix object is created that is in an
//identical state as the parameter multiMix object.
multiMix::multiMix(const multiMix& param){
  currentState = param.currentState;
  list = new vector<numMixer>;
  for(unsigned int i = 0; i < param.list->size();i++)
    list->push_back(param.list->at(i));
}
//Description: Overloaded assingment operator that
//takes two existing multiMix objects and makes the left hand
//side equal to the right hand side via deep Copy
//Preconditon: Two multiMixer objects exists
//Postcondition:Will make a copy of the object to the right of
//the assignment operator using the object to the left.
multiMix& multiMix::operator= (const multiMix& rhs){
  if(this != &rhs){
    delete list;
    list = new vector<numMixer>;
    currentState = rhs.currentState;
    for (unsigned int i = 0; i < rhs.list->size(); i++)
    {
          list->push_back(rhs.list->at(i));
    }
  }
return *this;
}
//Description:Overloaded Addition Operator:  Each element of the
//inital starting pool is added  to the corresponding element of the numMixer
//objects in the other multiMix object on the other side of the operator
//Precondition:Both objects must be multiMix objects who both hold
//at least one numMixer object.
//Postcondition:copy of a multiMix object is returned whos held numMIxer
//objects have each element summed with the corresponding numMixer
//objects in the other multiMix object.
multiMix multiMix::operator+(const multiMix& b){
  multiMix local(b);
  unsigned int min = list->size()<b.list->size()?
          list->size(): b.list->size();
  for(unsigned int i =0; i < min; i++)
    local.list->at(i) += list->at(i);
  return local;
}
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
multiMix& multiMix::operator+=(const multiMix& b){
  unsigned int min = list->size()<b.list->size()?
          list->size(): b.list->size();
  for(unsigned int i =0; i < min; i++)
    list->at(i) += b.list->at(i);
  return *this;
}
//Description:Overloaded Subtraction Operator:  Each element of the
//inital starting pool is subtracted from the
//corresponding element of the numMixer
//objects in the other multiMix object on the other side of the operator
//Precondition:Both objects must be multiMix objects who both hold
//at least one numMixer object.
//Postcondition:copy of a multiMix object is returned whos held numMIxer
//objects have each element subtracted with the corresponding numMixer
//objects in the other multiMix object.
multiMix multiMix::operator-(const multiMix& b){
  multiMix local(b);
  unsigned int min = list->size()<b.list->size()?
          list->size(): b.list->size();
  for(unsigned int i =0; i < min; i++)
    local.list->at(i) -= list->at(i);
  return local;
}
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
multiMix& multiMix::operator-=(const multiMix& b){
  unsigned int min = list->size()<b.list->size()?
          list->size(): b.list->size();
  for(unsigned int i =0; i < min; i++)
    list->at(i) -= b.list->at(i);
  return *this;
}
//Description: Compares all elements in the pools
//of held numMixer objects  and checks if they are
//identical.  If all elements are identical true is returned else false.
//Precondition:numMix object on both sides of the operator
//Postcondition:True false value returned based on if the
//pools of corresponding held numMix objects are identical.
  bool multiMix::operator ==(const multiMix& b){
    if(list->size() != b.list->size())
      return false;
    else{
      for(unsigned int i = 0; i < list->size(); i++)
        if(list->at(i)!= b.list->at(i))
          return false;
    }
    return true;
  }
  //Description: Compares all elements in the pools
  //of held numMixer objects  and checks if they are not
  //identical.  If any elements are not identical true is returned else false.
  //Precondition:multiMix object on both sides of the operator
  //Postcondition:True false value returned based on if the
  //pools of corresponding held numMix objects are identical.
    bool multiMix::operator !=( const multiMix& b){
      return!(*this == b);
    }
    //Description:The destructor for the multiMix Class deallocates the
    //memory of the dynamic vector
    //Precondition:dubMix has a vector
    //Postcondition:Deallocates vector memory
 multiMix::~multiMix(){
   delete list;
 }
 //DESCRIPTION:Adds a single numMIxer object to the Multimix
 //sets state of numMixer to match rest.
 //Precondition:Multimix object exists
 //Postcondition: A numMixer object is added to the multiMix object
void multiMix::add_back(){
    list->push_back(numMixer());
    if(currentState == Odd)
      list->back().setStateOdd();
    else if(currentState == Even)
      list->back().setStateEven();
    else
      list->back().setStateMix();
}

  //DESCRIPTiON:Removes a numMixer object from multiMix at
  //the back of the object.
  //Precondition: NumMixer object exists
  //PostCondition: Last numMixer object in the multiMix object is removed
void multiMix::remove_back(){
  if(list->size() != 0)
    list->pop_back();
}
//DESCRIPTION:Set the current state of object to Odd
//PostCondition:Object now in state Odd
void multiMix::setStateOdd(){
  currentState = Odd;
  for(unsigned int i =0; i < list->size(); i++)
    list->at(i).setStateOdd();
}
//DESCRIPTION:Set the current state of object to Even
//PostCondition:Object now in state Even
void multiMix::setStateEven(){
  currentState = Even;
  for(unsigned int i =0; i < list->size(); i++)
    list->at(i).setStateEven();
}
//DESCRIPTION:Set the current state of object to Mix
//PostCondition:Object now in state Mix
void multiMix::setStateMix(){
  currentState = Mix;
  for(unsigned int i =0; i < list->size(); i++)
    list->at(i).setStateMix();
}
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
int* multiMix::ping(int& getSize){
  if(list->size() == 0)
    return nullptr;
  std::vector<int> placeHolder;
  int* temp;
  int tempSize;
  for(unsigned int i = 0; i < list->size(); i++){
    temp = list->at(i).ping(tempSize);
    for(int j = 0; j < tempSize; j++){
      placeHolder.push_back(temp[j]);
    }
    delete[] temp;
  }
  int* returnArr = new int[placeHolder.size()];
  for(unsigned int i = 0; i < placeHolder.size(); i++){
    returnArr[i] = placeHolder[i];
    returnArr[i]*=NONPRIME;
  }
  getSize = placeHolder.size();
  return returnArr;
}
