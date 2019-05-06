//AUTHOR: Tyler Yamashiro
//FILENAME: numMixer.cs
//DATE: 4/9/18
//REVISION HISTORY: VERSION 1
//PLATFORM(compiler,version): 
/*DESCRIPTION:
 *  This class is a number mixer at the begining when the object is initiated
 *  the default maximum amount of numbers is 10.  A parameter can be passed into the constructor to
 *  increase the pool of numbers created.  These numbers are stored in an array.  
 *  The object starts in a mixed state return all odd and even numbers when pinged.
 *  When the object is pinged if the state is odd it returns all odd numbers.
 *  If even it returns all even numbers as an array. If the object is active it will
 *  return the numbers as an array if it is not active return null.
 *  The state of the object can be changed to even, odd, and mixed by calling
 *  the appropriate member functions.  The state change is counted and the user can 
 *  call a function to get the number of times the state of the object has changed.
 */
 /*ASSUMPTIONS: The object is active and in state mix when initiated.  The way the state changes is not random
  * but by programmer choice.  The object has a max threshHold of 10 pings after 10 pings the object becomes
  * inactive.  The initial number pool will be held in an array with a default of 10 numbers.  When pinged in mix
  * state will return all numbers in the pool.
  */
using System;

public class numMixer
{
    //Private class members
    private const int RANDOMMIN = 1;
    private const int RANDOMMAX = 200;
    private const int EVENMOD = 2;
    private int threshHold = 0;
    private int[] result;
    private const int THRESHMAX = 10;
    private bool odd = false;
    private bool even = false;
    private bool mix = true;
    private int stateChangeCounter = 0;
    private int[] store;
    private const int STORELENGTH = 10;
    //the length of the array that holds the starting number designated by user
    private int userLength;
    //Description: Fills the array that acts as a pool of numbers with
    //a default minimum value of zero and maximum of 200
    //Precondtion: A array has been successfully created as part of the numMixer object
    //Postcondition: The array is filled with random numbers
    
    //Description: The destructor for the numMixer object reclaims resources
    //Precondition: A numMixer object exists
    //PostCondition: The numMixer object no longer exists
    ~numMixer() { }
    //Description: Returns a bool based of in the threshHold is greater than
    //or equal to the maximum threshHold
    private bool checkActive()
    {
        return (threshHold < THRESHMAX);
    }
    private void buildStore()
    {
        Random number = new Random();

        for (int i = 0; i < store.Length; i++)
        {
            store[i] = number.Next(RANDOMMIN, RANDOMMAX);
        }
    }
    //Description: Depending on state of the object return odd, even, or mixed 
    //integers from the number pool.  If the object is not active return null. 
    //If there are no evens or are no odds returns null.
    //Precondition: Array filled with integers exists
    //Postcondition: Array is returned depending on the state of the object or
    //null is returned.
    private int[] returnPingHelper()
    {
        int oddCount = 0;
        int evenCount = 0;
        int indexCount = 0;
        for (int i = 0; i < store.Length; i++)
        {
            if (store[i] % EVENMOD == 0)
                evenCount++;
            else
                oddCount++;
        }
        if (odd)
        {
            result = new int[oddCount];
            for (int i = 0; i < store.Length; i++)
            {
                if (store[i] % EVENMOD == 1)
                {
                    result[indexCount] = store[i];
                    indexCount++;
                }
            }
        }
        else if (even)
        {
            result = new int[evenCount];
            for (int i = 0; i < store.Length; i++)
            {
                if (store[i] % EVENMOD == 0)
                {
                    result[indexCount] = store[i];
                    indexCount++;
                }
            }
        }
        else
        {
            result = new int[store.Length];
            for (int i = 0; i < store.Length; i++)
            {
                result[i] = store[i];
            }
        }

        if (checkActive())
            {
                return result;
            }
        else{
            return null;
            }
    }
    //Description: Increments the threshHold variable
    private void incThreshHold() 
    {
        threshHold++;
    }
    //Description: Sets the odd bool to true and increments the state change counter
    private void setStateOddHelper()
    {
        odd = true;
        even = false;
        mix = false;
        stateChangeCounter++;
    }
    //Description: Sets the even bool to true and increments the state change counter
    private void setStateEvenHelper()
    {
        odd = false;
        even = true;
        mix = false;
        stateChangeCounter++;
    }
    //Description: sets the mix bool to true and increments the state change counter
    private void setStateMixHelper()
    {
        odd = false;
        even = false;
        mix = true;
        stateChangeCounter++;
    }
    //Description: Returns the number of times the state has changed.
    private int returnStateChangeCount()
    {
        return stateChangeCounter;
    }
    
    
    //Pubic class members

    //Description: Default constrctor for the object.  Creates
    //the array to hold numbers and fills it using buildStore()
    //Precondition: A numMixer object is to be made
    //Postcondition: A numMixer object is made
    public numMixer()
	{
        store = new int[STORELENGTH];
        buildStore();
        userLength = STORELENGTH;
	}
    //Description: Constructor that takes a custom length that
    //determines the size of the number pool.  THe array
    //is filled with random ints
    //Precondition: numMixer object is to be made with an array
    //of size customLength. The array is filled with random ints
    public numMixer(int customLength)
    {
        userLength = customLength;
        store = new int[customLength];
        buildStore();
    }
    //Description: Copy Constructor that takes a numMixer object as
    //an argument and copies its number pool, state, and threshHold
    //Precondition: A numMixer object exists and is to be copied
    //PostCondition: A copy of the numMixer object is created
    public numMixer(numMixer prevNumMixer)
    {
        userLength = prevNumMixer.userLength;
        store = new int[userLength];
        threshHold = prevNumMixer.threshHold;
        odd = prevNumMixer.odd;
        even = prevNumMixer.even;
        mix = prevNumMixer.mix;
        stateChangeCounter = prevNumMixer.stateChangeCounter;
        for(int i = 0; i < userLength; i++)
        {
            store[i] = prevNumMixer.store[i];
        }

    }
    //Description: Calls return ping to return an array of ints
    //depending on the state of the object.  Increases the threshold by one
    //and returns the result of returnPing.  If the object is inactive it 
    //returns NULL.
    //Precondition: An array of numbers exists and is filled with integers
    public int[] ping()
    {
        int[] returnPing;
        incThreshHold();
        returnPing = returnPingHelper();
        return returnPing;
    }
    //Description: Calls setStateOddHelper and sets the object to odd
    public void setStateOdd()
    {
        setStateOddHelper();
    }
    //Description: Calls setStateEvenHelper and sets the object to even 
    public void setStateEven()
    {
        setStateEvenHelper();
    }
    //Description: Calls setStateMixHelper and sets teh object to mix
    public void setStateMix()
    {
        setStateMixHelper();
    }
    //Description: Calls returnStageChangeCount and returns the amount
    //of times the state of the object has changed
    public int returnStateCount()   
    {
        return returnStateChangeCount();
    }
    //Description: Calls checkActive and returns whether or not the object
    //is still active
    public bool isActive()
    {
        return checkActive();
    }
}
