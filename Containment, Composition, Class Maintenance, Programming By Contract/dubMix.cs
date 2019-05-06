//AUTHOR: Tyler Yamashiro
//FILENAME: dubMix.cs
//DATE: 4/19/18
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
 *
 * Interface Invariant: dubMix object:
 * Intantiation may use parameters but does not require it.  If a parameter
 * is passed it must be a positive integer.  Integers are returned
 * via and integer array. State of the object can be changed via setters
 * for both the dubMixer states mentioned and numMixer states contained
 * in the dubMixer. The default state is First and Mix states can
 * be set and do not change on their own.
 * 
 * 
 * Implementation Invariant: dubMix object:
 * The number of required numMixers can be changed via NUMBEROFMIXERS
 * const int.  All states can be set by the user and do not change on 
 * their own.
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p2
{
    class dubMix
    {
        private enum Control { First, Second, Interleaved, FCatS };
        private Control ctl;
        private const int NUMBEROFMIXERS = 2;
        private numMixer[] arr;
        //DESCRIPTION: Pings the first object in the array of type 
        //numMixer.  It returns the result as an integer array.
        //It will return null if the array pinged is not active
        //or there are no numbers to complete the request
        private int[] pingFirst()
        {
            int[] pingArr;
            pingArr = arr[0].ping();
            return pingArr;
        }
        //DESCRIPTION: Pings the second object in teh array of
        //type numMixer. It returns the result as an integer array.
        //It will return null if the array pinged is not active
        //or there are no numbers to complete the request
        private int[] pingSecond()
        {
            int[] pingArr;
            pingArr = arr[1].ping();
            return pingArr;

        }
        //DESCRIPTION: Pings both numMixers and stores the results in 
        //integer arrays. The results are inserted into a third
        //array alternating between the first and second object.
        //If an array runs out of items to insert the other array
        //inserts until it is finished. The new array is returned.
        private int[] pingInter()
        {
            int[] pingArr1;
            int[] pingArr2;
            int arr1Count = 0;
            int arr2Count = 0;
            pingArr1 = arr[0].ping();
            pingArr2 = arr[1].ping();
            int[] interArr = new int[pingArr1.Length +
                                     pingArr2.Length];
            for (int i = 0; i < interArr.Length; i++)
            {
                if (arr1Count < pingArr1.Length &&
                    arr2Count < pingArr2.Length)
                {
                    if (i % 2 == 0)
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
                else if (arr1Count < pingArr1.Length)
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
            return interArr;
        }
        //DESCRIPTION:Pings the first and second numMixer and stores
        //the result into respective integer arrays.  Then both are
        //copied into a third array and duplicates are eliminated.  
        //The resulting array is returned by the function.
        private int[] pingCat()
        {
            int[] pingArr1 = arr[0].ping();
            int[] pingArr2 = arr[1].ping();
            int[] catArr = new int[pingArr1.Length +
                                     pingArr2.Length];
            Array.Copy(pingArr1, catArr, pingArr1.Length);
            Array.Copy(pingArr2, 0, catArr, pingArr1.Length, pingArr2.Length);
            int[] pingArr = catArr.Distinct().ToArray();
            return pingArr;
        }
        //DESCRIPTION: The default constructor.  It creates an array of
        //size NUMBERMIXERS and fills them with new numMixer objects
        //The enum type variable ctl is insantiated to 'First'
        //Postcondition: State of object is in 'First' two numMixer
        //objects are stored in an array. Each numMixer object
        //starts in the Mix state.
        public dubMix()
        {
            ctl = Control.First;
            arr = new numMixer[NUMBEROFMIXERS];
            for (int i = 0; i < NUMBEROFMIXERS; i++)
            {
                arr[i] = new numMixer();
            }
        }
        //DESCRIPTION: The argument constructor.  It creates an array of
        //size NUMBERMIXERS and fills them with new numMixer objects.
        //The argument passed in by the user determines the size of the
        //initial pool of numbers generated by each numMixer object.
        //The size must be greater than zero in order to garuntee proper
        //operation and results.
        //The enum type variable ctl is insantiated to 'First'
        //Precondition:Constructer called with and unsigned integer
        //as an argument.  Where argument is greater than zero.
        //Postcondition: State of object is in 'First' two numMixer
        //objects with integer pools of mixSize are stored in an array.
        //Each start in the Mix state.
        public dubMix(uint mixSize)
        {
            ctl = Control.First;
            arr = new numMixer[NUMBEROFMIXERS];
            for (int i = 0; i < NUMBEROFMIXERS; i++)
            {
                arr[i] = new numMixer(mixSize);
            }
        }
        //DESCRIPTION: The Copy Constructor takes a dubMix object as a 
        //parameter and creates a deep copy of that object.  The
        //state and the numMixer objects in the array along with each
        //ones state is copied into the new object
        //Precondition: A dubMixer object must exist to be passed in .
        //PostCondition: A new dubMix object is created that is in an
        //identical state as the parameter dubMix object.
        public dubMix(dubMix param)
        {
            ctl = param.ctl;
            arr = new numMixer[NUMBEROFMIXERS];
            for(int i = 0; i < NUMBEROFMIXERS; i++)
            {
                arr[i] = new numMixer(param.arr[i]);
            }
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
        //not fufilled ping() will return null.
        public int[] ping()
        {
                int[] returnPing;
                if (ctl == Control.First)
                {
                    if (arr[0].isActive())
                    {
                        return (returnPing = pingFirst());
                    }
                    else
                        return null;
                }
                if (ctl == Control.Second)
                {
                    if (arr[1].isActive())
                    {
                        return (returnPing = pingSecond());
                    }
                    else
                        return null;
                }
            if (ctl == Control.Interleaved)
            {
                if (arr[0].isActive() && arr[1].isActive())
                {
                    return (returnPing = pingInter());
                }
                else
                {
                    return null;
                }
            }
            else
            {
                if (arr[0].isActive() && arr[1].isActive())
                {
                    return (returnPing = pingCat());
                }
                else
                {
                    return null;
                }
            }
        }
        //DESCRIPTION: Set the emum Control ctl variable to 
        //state 'First'
        public void setFirst()
        {
            ctl = Control.First;
        }
        //DESCRIPTION: Set the emum Control ctl variable to 
        //state 'Second'
        public void setSecond()
        {
            ctl = Control.Second;
        }
        //DESCRIPTION: Set the emum Control ctl variable to 
        //state 'Interleaved'
        public void setInter()
        {
            ctl = Control.Interleaved;
        }
        //DESCRIPTION: Set the emum Control ctl variable to 
        //state 'FCatS'
        public void setCat()
        {
            ctl = Control.FCatS;
        }
        //DESCRIPTION: Sets the state of both numMixer objects
        //in the numMixer array to Odd
        public void setOdd()
        {
            for (int i = 0; i < arr.Length; i++)
                arr[i].setStateOdd();
        }
        //DESCRIPTION: Sets the state of both numMixer objects
        //in the numMixer array to Even
        public void setEven()
        {
            for (int i = 0; i < arr.Length; i++)
                arr[i].setStateEven();
        }
        //DESCRIPTION: Sets the state of both numMixer objects
        //in the numMixer array to Mix
        public void setMix()
        {
            for (int i = 0; i < arr.Length; i++)
                arr[i].setStateMix();
        }
    }
}
