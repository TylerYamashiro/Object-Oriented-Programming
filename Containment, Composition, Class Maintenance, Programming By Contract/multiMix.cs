//AUTHOR: Tyler Yamashiro
//FILENAME: multiMix.cs
//DATE: 4/19/18
//REVISION HISTORY:Version 1.0
/*DESCRIPTION:The multiMix class can hold zero to many
 * numMixer objects. This object can change states from Odd, Even, and Mix.
 * When pinged multiMix will return all integers from all numMixer
 * objects stored within it that meet the qualifications of each state.
 * Odd will return odd integers, Even will return even integers, and 
 * Mix will return a mix of odd and even integers.  Objects of
 * type numMixer can also be added or removed from the multiMix object.
 */
 /*ASSUMPTIONS: The multiMix object will be compiled with the numMixer
  * class in order to work. multiMix objects are in Mix state by default
  * Assumes that user inputed amount of object will not be too much for
  * memory.
  */
  /*Interface Invariant: multiMix:
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
   * 
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
   * 
   * Implementation Invariant:
   * The add() optional parameter can be adjusted using
   * DEFAULTARGAMOUNT const uint, it is currently set at 1.
   * Transitions are external and can be set by the  user.
   */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p2
{
    class multiMix
    {
        //List to hold numMixer objects
        List<numMixer> multiList;
        private enum State {Odd, Even, Mix};
        private const uint DEFAULTARGAMOUNT = 1;
        private State currentState;
        //DESCRIPTION:The default constructor for the multiMix object
        //that sets the state of the object to Mix. The object starts
        //without any numMixer objects by default
        //It also initializes the List of type numMixer.
        //PostCondition:multiMix object state is Mix
        public multiMix()
        {
            currentState = State.Mix;
            multiList = new List<numMixer>();
        } 
        //DESCRIPTION:The argunemt constructor for the multiMix class.
        //This acceps an unsigned integer and starts the object with 
        //that amount of numMixer objects stored in the list.
        //The current state is also by default in Mix
        //Precondition:Valid unsigned integer as a parameter
        //PostCondition: State of object is in mix as well
        //as the number of numMixer objects created as defined
        //by the argument.
        public multiMix(uint amountnumMixers)
        {
            currentState = State.Mix;
            multiList = new List<numMixer>();
            for(int i = 0; i < amountnumMixers; i++)
            {
                multiList.Add(new numMixer());

            }
        }
        //DESCRIPTION: The copy constructor for the multiMixer
        //class.  Takes a multiMix object as a parameter and 
        //Creates a copy of the object.
        //Precondition:A multiMix object must exist and be passed
        //as a parameter.  
        //Postcondition: A new identical multiMix object is created
        //the state is copied as well as the numMixer objects in 
        //the list and their states.
        public multiMix(multiMix param)
        {
            currentState = param.currentState;
            multiList = new List<numMixer>();
            for(int i = 0; i < param.multiList.Count; i++)
            {
                multiList.Add(new numMixer(param.multiList[i]));
            }

        }
        //DESCRIPTION:Has an optional argument that can 
        //be used to insert a specific amount of numMixer objects
        //to the multiMix object.  The default value without
        //a parameter is one.
        //Precondition:If an unsinged int is given and more than zero
        //Postcondition: The amount of numMixer objects specified
        //are created and added to the multiMix object.
        public void add(uint optAddAmount = DEFAULTARGAMOUNT)
        {
            for(int i = 0; i < optAddAmount; i++)
            {
                multiList.Add(new numMixer());
            }
        }
        //DESCRIPTiON:Removes a numMixer object from multiMix at a 
        //specific index.  In order to remove the first numMixer
        //object the int 0 should be passed in.  
        //Precondition: The integer passed in is not negative and
        //not larger than or equal to the number of objects held
        //by multiMix.
        //PostCondition: The object at the specified index is 
        //removed from the multiMix object. True is returned if 
        //successful false if unsuccessful.
        public bool removeAt(int index)
        {
            if (index < 0 || index >= multiList.Count)
                return false;
            else
            {
                multiList.RemoveAt(index);
                return true;
            }
        }
        //DESCRIPTION:Set the current state of object to Odd
        //PostCondition:Object now in state Odd
        public void setStateOdd()
        {
            currentState = State.Odd;
        }
        //DESCRIPTION:Set the current state of object to Even
        //PostCondition:Object now in state Even
        public void setStateEven()
        {
            currentState = State.Even;
        }
        //DESCRIPTION:Set the current state of object to Mix
        //PostCondition:Object now in state Mix
        public void setStateMix()
        {
            currentState = State.Mix;
        }
        //DESCRIPTION:Retuns a bool depending on 
        //whether or not the multiMix is empty 
        //true is returned if the object is empty
        //false if the object is not empty
        public bool isEmpty()
        {
            if (multiList.Count == 0)
            {
                return true;
            }
            else
                return false;
        }
        //DESCRIPTION:Returns an array of integers based on the current state
        //of the multiMix object. Will return ping results from each numMixer 
        //object in multiMix as long as it is active.  Odd numbers will be 
        //returned if the state is Odd, even for Even, and mix for Mix
        //Precondition:In order for its contents for be returned a numMixer
        //object must be active. The state will be Odd, Even, or Mix.
        //Postcondition:ping() will return the results of all valid
        //numMixer objects in respect to multiMix current stat of Odd,
        //Even, or Mix. If no integers are returned ping() will return null;
        public int[] ping()
        {
            List<int> returnList = new List<int>();
            if (multiList.Count > 0)
            {
                for (int i = 0; i < multiList.Count; i++)
                {
                    if (multiList[i].isActive())
                    {
                        returnList.AddRange(multiList[i].ping());
                    }
                }
                if(returnList.Count == 0)
                {
                    return null;
                }
                else
                {
                    return (returnList.ToArray());
                }
            }
            else
                return null;
        }



        

    }
}
