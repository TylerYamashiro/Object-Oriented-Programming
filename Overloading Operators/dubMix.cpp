//AUTHOR: Tyler Yamashiro
//FILENAME: dubMix.cpp
//DATE: 5/29/18
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

 * * Implementation Invariant: dubMix object:
  * The number of required numMixers can be changed via NUMBEROFMIXERS
  * const int.  All states can be set by the user and do not change on
  * their own.
 *
 */
#include "dubMix.h"
#include <cstring>
#include <iostream>
//DESCRIPTION: The default constructor.  It creates an array of
//size NUMBERMIXERS and fills them with new numMixer objects
//The enum type variable ctl is insantiated to 'First'
//Postcondition: State of object is in 'First' two numMixer
//objects are stored in an array. Each numMixer object
//starts in the Mix state.
dubMix::dubMix()
{
    ctl = First;
    arr = new vector<numMixer>;
    for (int i = 0; i < NUMBEROFMIXERS; i++)
    {
      arr->push_back(numMixer());
    }
}
//DESCRIPTION: The Copy Constructor takes a dubMix object as a
//parameter and creates a deep copy of that object.  The
//state and the numMixer objects in the array along with each
//ones state is copied into the new object
//Precondition: A dubMixer object must exist to be passed in .
//PostCondition: A new dubMix object is created that is in an
//identical state as the parameter dubMix object.
dubMix::dubMix(const dubMix& param){
  ctl = param.ctl;
  arr = new vector<numMixer>;
    arr->push_back(param.arr->front());
    arr->push_back(param.arr->back());
}
//Description: Overloaded assingment operator that
//takes two existing dubMix objects and makes the left hand
//side equal to the right hand side via deep Copy
//Preconditon: Two dubMixer objects exists
//Postcondition:Will make a copy of the object to the right of
//the assignment operator using the object to the left.
dubMix& dubMix::operator=(const dubMix& rhs){
  if(this != &rhs){
    ctl = rhs.ctl;
    delete arr;
    arr = new vector<numMixer>;
    arr->push_back(rhs.arr->front());
    arr->push_back(rhs.arr->back());
  }
  return *this;
}
//Description:Overloaded Addition Operator:  Each element of the
//inital starting pool is added  to the corresponding element of the numMixer
//objects in the other dubMix object on the other side of the operator
//Precondition:Both objects must be dubMix objects
//Postcondition:copy of a dubMix object is returned whos held numMIxer
//objects have each element summed with the corresponding numMixer
//objects in the other dubMix object.
dubMix dubMix::operator+(const dubMix& b){
  dubMix local(b);
  for(int i = 0; i < NUMBEROFMIXERS; i++)
    local.arr->at(i) += arr->at(i);
  return local;
}
//Description:Overloaded Addition Assignment Operator:  Each element of the
//inital starting pool is added to the corresponding element of the numMixer
//objects in the dubMix object  on the other side of the operator.
//Replacest the object on the
//left hand side with the new values.
//Precondition:Both objects must be dubMix objects
//Postcondition:Left hand side held numMixer objects pools are replaced
//with the new values of the addition of the right hand and left hand side
//held numMixer objects.
dubMix& dubMix::operator+=(const dubMix& b){
  for(int i = 0; i < NUMBEROFMIXERS; i++)
    arr->at(i)+= b.arr->at(i);
  return *this;
}
//Description:Overloaded Subtraction Operator:  Each element of the
//inital starting pool is subtracted from the
//corresponding element of the numMixer
//objects in the other dubMix object on the other side of the operator
//Precondition:Both objects must be dubMix objects
//Postcondition:copy of a dubMix object is returned whos held numMIxer
//objects have each element subtracted with the corresponding numMixer
//objects in the other dubMix object.
dubMix dubMix::operator-(const dubMix& b){
  dubMix local(b);
  for(int i = 0; i < NUMBEROFMIXERS; i++)
    local.arr->at(i) -= arr->at(i);
  return local;
}
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
dubMix& dubMix::operator-=(const dubMix& b){
  for(int i = 0; i < NUMBEROFMIXERS; i++)
    arr->at(i)-= b.arr->at(i);
  return *this;
}
//Description: Compares all elements in the pools
//of held numMixer objects  and checks if they are
//identical.  If all elements are identical true is returned else false.
//Precondition:dubMix object on both sides of the operator
//Postcondition:True false value returned based on if the
//pools of corresponding held numMix objects are identical.
bool dubMix::operator ==(const dubMix& b){
  for(int i =0; i < NUMBEROFMIXERS;i++){
    if(arr->at(i) !=  b.arr->at(i))
      return false;
  }
  return true;
}
//Description: Compares all elements in the pools
//of held numMixer objects  and checks if they are not
//identical.  If any elements are not identical true is returned else false.
//Precondition:dubMix object on both sides of the operator
//Postcondition:True false value returned based on if the
//pools of corresponding held numMix objects are identical.
bool dubMix::operator !=(const dubMix& b){
  return !(*this == b);
}
//Description:The destructor for the dubMix Class deallocates the
//memory of the dynamic vector
//Precondition:dubMix has a vector
//Postcondition:Deallocates vector memory
dubMix::~dubMix(){
  delete arr;
}
//DESCRIPTION: Pings the first object in the array of type
//numMixer.  It returns the result as an integer array.
//It will return null if the array pinged is not active
//or there are no numbers to complete the request
int* dubMix::pingFirst(int& getSize)
{
  int* pingArr;
  int holder;
  pingArr = arr->at(FIRSTMIXER).ping(holder);
  getSize = holder;
  return pingArr;
}
//DESCRIPTION: Pings the second object in teh array of
//type numMixer. It returns the result as an integer array.
//It will return null if the array pinged is not active
//or there are no numbers to complete the request
int* dubMix::pingSecond(int& getSize)
{
  int holder;
  int* pingArr;
  pingArr = arr->at(SECONDMIXER).ping(holder);
  getSize = holder;
  return pingArr;
}

//DESCRIPTION: Pings both numMixers and stores the results in
//integer arrays. The results are inserted into a third
//array alternating between the first and second object.
//If an array runs out of items to insert the other array
//inserts until it is finished. The new array is returned.
int* dubMix::pingInter(int& getSize)
{
    int*pingArr1;
    int*pingArr2;
    int arr1Count = 0;
    int arr2Count = 0;
    int arr1Size;
    int arr2Size;
    pingArr1 = pingFirst(arr1Size);
    pingArr2 = pingSecond(arr2Size);
    int interArrSize = arr1Size + arr2Size;
    int* interArr = new int[interArrSize];

    for (int i = 0; i < interArrSize; i++)
    {
        if (arr1Count < arr1Size &&
            arr2Count < arr2Size)
        {
            if (i % EVENCHECK == ZERO)
            {
                interArr[i] = pingArr1[arr1Count];
                arr1Count++;
            }
            else
            {
                interArr[i] = pingArr2[arr2Count];
                arr2Count++;
            }
        }
        else if (arr1Count < arr1Size)
        {
            interArr[i] = pingArr1[arr1Count];
            arr1Count++;
        }
        else
        {
            interArr[i] = pingArr2[arr2Count];
            arr2Count++;
        }

    }
    delete[] pingArr1;
    delete[] pingArr2;
    return interArr;
}
//DESCRIPTION:Pings the first and second numMixer and stores
//the result into respective integer arrays.  Then both are
//copied into a third array and duplicates are eliminated.
//The resulting array is returned by the function.
int* dubMix::pingCat(int& getSize)
{
    int arr1Size;
    int arr2Size;
    int* pingArr1 = arr->at(FIRSTMIXER).ping(arr1Size);
    int* pingArr2 = arr->at(SECONDMIXER).ping(arr2Size);
    int* catArr = new int[arr1Size + arr2Size];
    std::memcpy(catArr,pingArr1,sizeof(*pingArr1));
    std::memcpy(catArr+sizeof(*pingArr1),pingArr2,
                      sizeof(*pingArr2));
    return catArr;
}


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
int* dubMix::ping(int& getSize)
{
        int* returnPing;
        if (ctl == First)
        {
            if (arr->at(FIRSTMIXER).isActive())
            {
                return (returnPing = pingFirst(getSize));
            }
            else
                return nullptr;
        }
        if (ctl == Second)
        {
            if (arr->at(SECONDMIXER).isActive())
            {
                return (returnPing = pingSecond(getSize));
            }
            else
                return nullptr;
        }
    if (ctl == Interleaved)
    {
        if (arr->at(FIRSTMIXER).isActive() && arr->at(SECONDMIXER).isActive())
        {
            return (returnPing = pingInter(getSize));
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        if (arr->at(FIRSTMIXER).isActive() &&
        arr->at(SECONDMIXER).isActive())
        {
            return (returnPing = pingCat(getSize));
        }
        else
        {
            return nullptr;
        }
    }
}

//DESCRIPTION: Set the emum Control ctl variable to
//state 'First'
//PostCondition:Object set to First state.
void dubMix::setFirst()
{
    ctl = First;
}
//DESCRIPTION: Set the emum Control ctl variable to
//state 'Second'
//PostCondition: Object set to second state
void dubMix::setSecond()
{
    ctl = Second;
}
//DESCRIPTION: Set the emum Control ctl variable to
//state 'Interleaved'
void dubMix::setInter()
{
    ctl = Interleaved;
}
//DESCRIPTION: Set the emum Control ctl variable to
//state 'FCatS'
void dubMix::setCat()
{
    ctl = FCatS;
}
//DESCRIPTION: Sets the state of both numMixer objects
//in the numMixer array to Odd
void dubMix::setOdd()
{
    for (int i = 0; i < NUMBEROFMIXERS; i++)
        arr->at(i).setStateOdd();
}
//DESCRIPTION: Sets the state of both numMixer objects
//in the numMixer array to Even
void dubMix::setEven()
{
    for (int i = 0; i < NUMBEROFMIXERS; i++)
        arr->at(i).setStateEven();
}
//DESCRIPTION: Sets the state of both numMixer objects
//in the numMixer array to Mix
void dubMix::setMix()
{
    for (int i = 0; i < NUMBEROFMIXERS; i++)
        arr->at(i).setStateMix();
}
