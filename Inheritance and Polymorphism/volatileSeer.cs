//AUTHOR: Tyler Yamashiro
//FILENAME: volatileSeer.cs
//DATE:4/30/18
//REVISION HISTORY: Version 1.0
/*DESCRIPTION:
 * Ths is a class called volatileSeer that returns a message when it is
 * requested the message is fixed to the DEFAULTMESSAGE variable.
 * The class has an on and off state which is toggled depending
 * on the magicNumber variable. Magic numbers may only be single
 * digits.  THe request can be rejected randomly.  The messege
 * returned can also be changed.  This class is a derived class
 * of the seer class.
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
 * Request can be rejected.
 * Message can be overwritten
 */
/*INTERFACE INVARIANT:
 * The constructor may take unsigned int greater than zero
 * and less than ten as an argument.  If the argument is not
 * valid the constructor will replace it with the default 
 * magicNumber value.
 * The constructor also may take a second parameter to seed when
 * requests are denied. If requests are denied it will return
 * the string REJECTED.
 * The message can be replaced using the replaceRequest() method
 * If the object is in an off state it will return the 
 * empty string.
 * If in on state the message will be returned.
 */
/*IMPLEMENTATION INVARIANT:
 * The default magicNumber variable is set using 
 * the DEFAULTMAGICNUM const.
 * The defaulet regectGen value is set using 
 * DEFAULTREJECTGEN.
 * The default message when object is rejected is
 * set in REJECTED const variable.
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
    class volatileSeer: seer
    {
        protected const string REJECTED = "REJECTED";
        private const uint DEFAULTREGECTGEN = 5;
        private uint rejectRandGen;
        //DESCRITPTION: Creates the volatileSeer object which is a derived class
        //of the seer class.  It is initialized in the same way with the addition
        //of a new argument rejectGen which is used to seed the rejection 
        //mechanism the default is given as DEFAULTREGECTGEN.
        //PostCondition:Create volatileSeer object 
        public volatileSeer(uint magicNum = DEFAULTMAGICNUM,
                            uint rejectGen = DEFAULTREGECTGEN): base(magicNum)
        {
            rejectRandGen = rejectGen;
        }
        //DESCRIPTION: Copy constructor for the volatileSeer object.
        //utilizes the parent copy constructor as well as 
        //copies the rejectRandGen variable from origonal object
        //Precondition: A volatileSeer object exists 
        //Postconditin: An copy of the origonal volatileSeer object is created
        public volatileSeer(volatileSeer origonal):base(origonal)
        {
            rejectRandGen = origonal.rejectRandGen;
        }
        //DESCRIPTION: Takes an string argument and replaces the current
        //message
        //PostCondition: message variable changed to that of argument
        public void replaceRequest(string replacement)
        {
            message = replacement;
        }
        //DESCRIPTION: Pings the object with a request.  The 
        //object returns either the message or an empty string
        //based on whether it is on or off respectively.  
        //The object turns on and off every nth request where
        //n is equal to the magicNumber variable.
        //May reject a request and return "REJECTED"
        //PostCondtition:Either the message or empty string is 
        //returned and the state may flip between on and off
        //dependent on magicNumber. May return REJECTED
        //if the request is rejected.
        public override string Request()
        {
            if (magicCounter % rejectRandGen == 0)
            {
                magicCounter++;
                return REJECTED;
            }
            return base.Request();
        }



    }
}
