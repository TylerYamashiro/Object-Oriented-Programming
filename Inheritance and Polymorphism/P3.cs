//AUTHOR:Tyler Yamashiro
//FILENAME: P3.cs
//DATE:4/30/18
//VERSION 1.0
//DESCRIPTION:TEST DRIVER to test the functins of the seer class
//and its derived classes volatileSeer and tmSeer
//This creates a heterogenous collection from the base class seer
//and tests each one by calling the same function on each.
//In this we test the request function of each object as well as
//the message replacement in volatileSeer, and the case mixing
//in tmSeer.  We also test the request rejection in volatileSeer and
//the max state change cycles in tmSeer.
//ASSUMPTIONS:All class objects needed are compiled with this object
//CLASS INVARIANT:
//The number of testing rounds for the collection is given by
//the const int TESTROUNDS.
//The numer of objects created is given by the NUMBERCLASSES variable
//The Collection consists of one seer object, one volatileSeer, and one
//tmSeer.
//INTERFACE INVARIANT:
//In this case the test is programed to run 7 times inorder
//to demonstrate the functions of all 3 objects
//the first object is the seer, second the valatileSeer,
//the third is the tmSeer.
//IMPLEMENTATION INVARIANT:
//To change the number of rounds or objects created chage
//the const variables.  If the number of objects created
//change the instanciaion function getObj may also have
//to change.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p3
{
    class P3
    {
        const int NUMBERCLASSES = 3;
        const int TESTROUNDS = 7;
        const int SEERINT = 0;
        const int VOLATILEINT = 1;
        const int TMINT = 2;
        //DESCRIPTION:Returns a seer base or derived class object
        //based on the integer passed into the integer passed into
        //the function.  
        //Precondition:integer for determining what class to return
        //Postcondition:A class object of seer or inherited from seer
        //is returned.
        static public seer getObj(int version)
        {
            if (version % NUMBERCLASSES == SEERINT)
                return new seer();
            else if (version % NUMBERCLASSES == VOLATILEINT)
                return new volatileSeer();
            else if (version % NUMBERCLASSES == TMINT)
                return new tmSeer();
            else
                throw new IndexOutOfRangeException("Bad Condition");

        }
        //DESCRIPTION:Tests the request function of each object in 
        //the collectin. Looks for the empty string signifying object
        //is off string and REJECTED signifying the object has 
        //rejected the request.  Prints the results to the string
        //Seer then volatileSeer then tmSeer is the order of printing
        //for each call.
        //Precondition:seer array passed in as an argument
        //PostCondition: returned reesult of each object printed
        //to the screen.
        static public void testRequest(seer[] arr)
        {
            string temp;
            Console.WriteLine("Now testing output of request" +
                " from each object in array:");
            for(int i = 0; i < arr.Length; i++)
            {
                temp = arr[i].Request();
                if (temp == "")
                {
                    Console.WriteLine("Object is off");
                }
                else if (temp == "REJECTED")
                {
                    Console.WriteLine("Request was Rejected");
                }
                else
                    Console.WriteLine(temp);
            }
        }
        //DESCRiPTiON:Tests the replaceRequest function in the 
        //volatileSeer objects in the array.
        //Precondition:seer type array as a parameter for the class
        //Postcondition:Replaces the message in any seer objects in 
        //the colelction.
        static public void changeMessage(seer[] arr)
        {
            Console.WriteLine("Now replacing the message in volatileSeer" +
                " class objects.");
            for(int i = 0; i < arr.Length; i++)
            {
                if(arr[i] is volatileSeer)
                {
                    string replacement = "This is a replacement.";
                    volatileSeer temp = arr[i] as volatileSeer;
                    temp.replaceRequest(replacement);
                }
            }

        }
        //DESCRIPTION: Main driver of the class.  Creates an 
        //array of type seer and calls getObject(); to fill the 
        //array. Then runs same sets of test on the array 7 times
        //or the amount specified by TESTROUNDS to ensure complete
        //testing
        //Postcondition:Announces which test round it is currently.
        static void Main(string[] args)
        {
            seer[] testArray = new seer[NUMBERCLASSES];
            for (int i = 0; i < NUMBERCLASSES; i++)
            {
                testArray[i] = getObj(i);
            }
            for (int i = 0; i < TESTROUNDS; i++)
            {
                Console.WriteLine("TEST ROUND " + i + ":");
                testRequest(testArray);
                changeMessage(testArray);
                testRequest(testArray);
                Console.WriteLine("");
            }
            Console.ReadLine();

        }
    }
}
