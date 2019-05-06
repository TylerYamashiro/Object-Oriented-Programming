//AUTHOR: Tyler Yamashiro
//FILENAME: seer.cs
//DATE:4/30/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION:
 * Ths is a class called seer that returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.
 */
/*CLASS INVARIANT:
 * The magicNumber is a stable unsigned int that is greater than
 * zero and less than ten.
 * The class automatically generates a stable message upon 
 * creation.
 * The class will toggle between on or off every magicNumber 
 * value turns.
 * An off object will return an empty string an on object
 * will return the message.
 */
/*INTERFACE INVARIANT:
 * The constructor may take unsigned int greater than zero
 * and less than ten as an argument.  If the argument is not
 * valid the constructor will replace it with the default 
 * magicNumber value.
 * If the object is in an off state it will return the 
 * empty string.
 * If in on state the message will be returned.
 */
/*IMPLEMENTATION INVARIANT:
 * The default magicNumber variable is set using 
 * the DEFAULTMAGICNUM const. 
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
    class seer
    {
        protected bool stateSeer;
        protected uint magicNumber;
        protected string message;
        private const uint SINGLEDIGITCHECK = 10;
        protected uint magicCounter;
        protected const string DEFAULTMESSAGE = "I can't actually see the future.";
        protected const uint DEFAULTMAGICNUM = 3;
        protected const string OFFSTATESTRING = "";
        //DESCRIPTION:Constructor for the seer class can take in a unsigned int
        //that can be used to set the magicNumber variable.  Instanciates all the 
        //variables that are declared and checks to see if the paramater is valid
        //POSTCONDITION: seer object is created and values are set
        public seer(uint magicNum = DEFAULTMAGICNUM)
        {
            if (magicNum < SINGLEDIGITCHECK && magicNum > 0)
                magicNumber = magicNum;
            else
                magicNumber = DEFAULTMAGICNUM;
            magicCounter = 0;
            stateSeer = true;
            message = DEFAULTMESSAGE;

        }
        //DESCRIPTION:Takes a seer type object as a parameter and copies its values
        //into a new created seer object
        //Precondition:seer object exists to be passed into the copy constructor
        //Postcondition: A new seer object is created with the same values and 
        //states as the parameter object
        public seer(seer origonal)
        {
            stateSeer = origonal.stateSeer;
            magicNumber = origonal.magicNumber;
            magicCounter = origonal.magicNumber;
            message = origonal.message;
        }
        //DESCRIPTION: Pings the object with a request.  The 
        //object returns either the message or an empty string
        //based on whether it is on or off respectively.  
        //The object turns on and off every nth request where
        //n is equal to the magicNumber variable
        //PostCondtition:Either the message or empty string is 
        //returned and the state may flip between on and off
        //dependent on magicNumber.
        public virtual string Request()
        {
            if (magicCounter % magicNumber == 0 && magicCounter != 0)
                stateSeer ^= true;

            if (stateSeer)
            {
                magicCounter++;
                return message;
            }
            else
            {
                magicCounter++;
                return OFFSTATESTRING;
            }
          
        }



    }
}  