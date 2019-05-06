//AUTHOR: Tyler Yamashiro
//FILENAME: tmSeer.cs
//DATE:4/30/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION:
 * Ths is a class called tmSeer that returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The message returned will have arbritary casing based on seed.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.  The object can only be toggled k times where k equals
 * the maxCycles variable.  This class is a derived class of the 
 * seer class. If object cycles too many times it will turn off
 * and be in permanent off state.
 */
/*CLASS INVARIANT:
 * The magicNumber is a stable unsigned int that is greater than
 * zero and less than ten.
 * The class automatically generates an unstable message upon 
 * creation.
 * The class will toggle between on or off every magicNumber 
 * value turns.
 * An off object will return an empty string an on object
 * will return the message.
 * The message when requested may have characters change its
 * case arbitrarily.
 * If the on off cycles exeed the limit the object is put
 * in off state permanently.
 */
/*INTERFACE INVARIANT:
 * The constructor may take unsigned int greater than zero
 * and less than ten as an argument.  If the argument is not
 * valid the constructor will replace it with the default 
 * magicNumber value.
 * It also takes a second argument that can be used to set
 * the number of max cycles.
 * If the object is in an off state it will return the 
 * empty string.
 * If in on state the message will be returned.
 * The message may have arbritary casing in its characters
 */
/*IMPLEMENTATION INVARIANT:
 * The default magicNumber variable is set using 
 * the DEFAULTMAGICNUM const. 
 * The default maxCycle variable is set using
 * the  DEFAULTMAXCYCLES.
 * The magicNumber is used to seed which characters
 * in the string is case flipped.
 * Case is fipped by turning the string into a char array
 * and flipping the casing of random chars determined by
 * magicNum. Then char array is turned back into a string
 * The default message and the string returned
 * during off state can be changed by changing
 * the corresponding const string variables.
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p3
{
    class tmSeer: seer
    {
        private uint maxCycles;
        private const uint DEFAULTMAXCYCLES = 5;
        private uint cycleCount;
        //DESCRITPTION: Creates the tmSeer object which is a derived class
        //of the seer class.  It is initialized in the same way with the addition
        //of a new argument cycles which sets the value of the maxCycles variable.
        //PostCondition:Create tmSeer object 
        public tmSeer(uint magicNum = DEFAULTMAGICNUM,
                      uint cycles = DEFAULTMAXCYCLES): base(magicNum)
        {
            maxCycles = cycles;
            cycleCount = 0;
        }
        //DESCRIPTION: Copy constructor of the tmSeer object utilizes the 
        //seer object that it is derived from and also copies its unique
        //variables
        //PRECONDITION: A tmSeer object exists as an argument
        //POSCTCONDITION: Objects states and values are copied and new object 
        //with those are created.
        public tmSeer(tmSeer origonal): base(origonal)
        {
            maxCycles = origonal.maxCycles;
            cycleCount = origonal.cycleCount;
        }
        //DESCRIPTION: Pings the object with a request.  The 
        //object returns either the message or an empty string
        //based on whether it is on or off respectively.  
        //The object turns on and off every nth request where
        //n is equal to the magicNumber variable.
        //After a predetermined number amount of cycles the
        //Request ill return the off state string and set
        //state of object to off.  Caseing of the message may also
        //change since the caseMix method is called.
        //PostCondtition:Either the message or empty string is 
        //returned and the state may flip between on and off
        //dependent on magicNumber and number of cycles passed.
        public override string Request()
        {
            if(cycleCount >= maxCycles)
            {
                stateSeer = false;
                return OFFSTATESTRING;
            }
            cycleCount++;
            message = caseMix(message);
            return base.Request();
        }
        //DESCRIPTION:Takes a string as an argument and change the casing 
        //of the string. The string will be the message data member since
        //the method is private and is only used to alter the message
        //Postcondition: Message is altered with flipped casing on random 
        //characters in the string.
        private string caseMix(string mixCandidate)
        {
            char[] temp = mixCandidate.ToCharArray();
            for(int i = 0; i < temp.Length; i++)
            {
                if( i % magicNumber == 1 || i % magicNumber == 2)
                {
                    if (Char.IsUpper(temp[i]))
                    {
                        temp[i] = Char.ToLower(temp[i]);
                    }
                    else if(Char.IsLower(temp[i]))
                    {
                        temp[i] = Char.ToUpper(temp[i]);
                    }
                }
            }
             return new string(temp);
            
        }

    }
}
