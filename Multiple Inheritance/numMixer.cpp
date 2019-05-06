//AUTHOR: Tyler Yamashiro
//FILENAME: numMixer.cpp
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
   *
   * Implementation Invariant: numMIxer:
   * The default seed can be changed using POOLSEED const int. The
   * default threshHold can be changed using THRESHMAX.  The default
   * number pool size can be changed by changing STORELENGTH.  The number
   * generator is located in buildStore() and is a basically a fibbanacci
   * sequence that starts at the seed given. Active determined by comparing
   * threshHold and THRESHMAX in isActive()
   *
   */
#include "numMixer.h"

//Description: Returns a bool based of in the threshHold
//is greater than or equal to the maximum threshHold
bool numMixer::isActive()
{
    return (threshHold < THRESHMAX);
}

//Description: Fills the array that acts as a pool of numbers with
//a fibbonacci sequence like functions that uses the seed
//provided or a default seed as beginning point
//Precondtion: A array has been successfully created as part of
//the numMixer object that has greater than zero capacity
//Postcondition: The array is filled with seeded numbers
 void numMixer::buildStore()
{
    int oldNum = seedPool;
    int currentNum = seedPool;
    int nextNum;
    for (unsigned int i = 0; i < userLength; i++)
    {
        nextNum = currentNum + oldNum;
        oldNum = currentNum;
        currentNum = nextNum;
        store[i] = nextNum;
    }
}

//Description: Increments the threshHold variable.
void numMixer::incThreshHold()
{
   threshHold++;
}

//Description: Depending on state of the object return odd, even,
//or mixed integers from the number pool.
//via an integer pointer that pionts to dynamic
//array.  If the object is not active
//return null. If there are no evens or are no odds returns null.
//Precondition: Array filled with integers exists as a pool of integers
//Postcondition: Array is returned depending on the state
//of the object or null is returned if the ping is to return nothing
//or fail
int* numMixer::returnPingHelper(int& getSize)
{
    int oddCount = 0;
    int evenCount = 0;
    int indexCount = 0;
    int* helpResult;
    int* returnSize = &getSize;
    for (unsigned int i = 0; i < userLength; i++)
    {
        if (store[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    if (currentState == Odd)
    {
        helpResult = new int[oddCount];
        *returnSize = evenCount;
        for (unsigned int i = 0; i < userLength; i++)
        {
            if (store[i] % 2 == 1)
            {
                helpResult[indexCount] = store[i];
                indexCount++;
            }
        }
    }
    else if (currentState == Even)
    {
        helpResult= new int[evenCount];
        *returnSize = evenCount;
        for (unsigned int i = 0; i < userLength; i++)
        {
            if (store[i] % 2 == 0)
            {
                helpResult[indexCount] = store[i];
                indexCount++;
            }
        }
    }
    else
    {
        helpResult = new int[userLength];
        *returnSize = userLength;
        for (unsigned int i = 0; i < userLength; i++)
        {
            helpResult[i] = store[i];
        }
    }
    if (isActive())
    {

        return helpResult;
    }
    else
    {
      *returnSize = 0;
        return nullptr ;
    }
}

//Description: Default constrctor for the object.  Creates
//the array to hold numbers and fills it using buildStore()
//Precondition: A numMixer object is to be made
//Postcondition: A numMixer object is made
numMixer::numMixer()
{
    seedPool = POOLSEED;
    store = new int[STORELENGTH];
    userLength = STORELENGTH;
    threshHold = 0;
    stateChangeCounter = 0;
    buildStore();

}

//Description:   The user can input an int argument to change the seed
//of the origonal pool of numbers
//Precondition: NumMixer object is to be made with an array
//of size customLength in order to store numbers
//the parameter must be more than 0.  The seed must also
//be greater than zero.
//Postcondition: Object will have an array with integers according to
//a provided or default seed
numMixer::numMixer(int seed )
{
    seedPool = seed;
    if (seed <= 0)
    {
        seedPool = POOLSEED;
    }
    store = new int[STORELENGTH];
    userLength = STORELENGTH;
    threshHold = 0;
    stateChangeCounter = 0;
    buildStore();
}

//Description: Constructor that takes a custom length that
//determines the size of the number pool. The user can
//also fill an optional argument to change the seed
//of the origonal pool of numbers
//Precondition: NumMixer object is to be made with an array
//of size customLength in order to store numbers
//the parameter must be more than 0.  The seed must also
//be greater than zero.
//Postcondition: Object will have an array of user
//designated size filled with integers according to
//a provided or default seed
numMixer::numMixer(int seed, unsigned int customLength)
{

    seedPool = seed;
    if (seed <= 0)
    {
        seedPool = POOLSEED;
    }
    userLength = customLength;
    store = new int[customLength];
    threshHold = 0;
    stateChangeCounter = 0;
    buildStore();
}

//Description: Copy Constructor that takes a numMixer object as
//an argument and copies its number pool, state, and threshHold
//Precondition: A numMixer object exists and is to be copied
//PostCondition: A copy of the numMixer object is created
numMixer::numMixer(const numMixer& prevNumMixer)
{
    userLength = prevNumMixer.userLength;
    seedPool = prevNumMixer.seedPool;
    store = new int[userLength];
    threshHold = prevNumMixer.threshHold;
    currentState = prevNumMixer.currentState;
    stateChangeCounter = prevNumMixer.stateChangeCounter;
    for (unsigned int i = 0; i < userLength; i++)
    {
        store[i] = prevNumMixer.store[i];
    }

}

//Description: Overloaded assingment operator that
//takes two existing numMixer objects and makes the left hand
//side equal to the right hand side via deep Copy
//Preconditon: Two numMixer objects exists
//Postcondition:Will make a copy of the object to the right of
//the assignment operator using the object to the left.
numMixer& numMixer::operator=(const numMixer& rhs){
  if(this != &rhs){
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
//Description: Destructor for the numMixer class reclaims allocated memory
//at the addresses not returned by the ping() function.   The ownership of
//the memory returned by the ping function is transfered when the ping
//function returns and the deallocation of that memory is the
//responsibility of the application programmer.
numMixer::~numMixer(){
  delete[] store;
}
//Description: Calls return ping to return an array of ints
//depending on the state of the object.  Increases the threshold by one
//and returns the result of returnPing.  If the object is inactive it
//returns NULL  The user must track the returned pointer that stores
//address of the array in memory in order to delete it to prevent memory
// leaks this must be done with each ping call.  The user must also then
//call delete for each ping called.
//Precondition: An array of numbers exists and is filled with integers
//Postcondition: Reclaims memory of previous ping call and
//returns a pointer to the newly allocated memory for an integer array
int* numMixer::ping(int& getSize)
{
    incThreshHold();
    //returnPing = returnPingHelper();
    return returnPingHelper(getSize);
}

//Description: Set the currentStat to Odd and increment the
//stateChangeCounter
void numMixer::setStateOdd()
{
    currentState = Odd;
    stateChangeCounter++;
}

//Description: Set the currentState to Mix and increment the
//stateChangeCounte
void numMixer::setStateEven()
{
    currentState = Even;
    stateChangeCounter++;
}

//Description: Set the currentState to Mix and increment the
//stateChangeCounter
void numMixer::setStateMix()
{
    currentState = Mix;
    stateChangeCounter++;
}

//Description: Returns the number of times the state has changed.
int numMixer::returnStateCount()
{
    return stateChangeCounter;
}
