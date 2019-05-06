//AUTHOR: Tyler Yamashiro
//FILENAME: p2.cs
//DATE: 4/19/18
//REVISION HISTORY: Version 1.0
/*Description:This driver tests the multiMix and dubMix classes
 * three objects from each are created one from the classes
 * default constructor, one from the argument constructor, and one from
 * the copy constructor.  These three are stored in a list of their
 * respective types.  A for loop is called in order to put them all 
 * through the same testing and compare the results.  The
 * testing is printed to the console and labeled.
 */
 /*ASSUMPTIONS:The only user input there is pressing the enter key 
  * at the end of the program to exit. Lists from the System are
  * used to store the objects being tested. The values used are
  * constants rather than randomly generated so that future users
  * can test the classes with precicion. Reacts to the class
  * error handling as its own.
  */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace p2
{
    class p2
    {
        const int POOLSIZE = 10;
        //number of test objects
        const int TESTOBJSCOUNT = 3;
        //number of arguments for multiMix
        const int MULTIARG = 3;
        const int FIRSTOBJ = 0;
        const int SECONDOBJ = 1;
        const int THIRDOBJ = 3;
        //--Functions to test dubMix--------------------------------------
        //DESCRIPTION:Pings a dubMixer object passed in as a parameter
        //and prints the results to the console. Checks for null if so
        //simply returns.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: Results of the ping are printed to the console
        public static void testPingDub(dubMix testObj)
        {
            int[] pingResult;
            pingResult = testObj.ping();
            Console.WriteLine("Ping has returned:");
            if (pingResult == null)
                return;
            for(int i = 0; i < pingResult.Length; i++)
            {
                Console.WriteLine(pingResult[i]);
            }

        }
        //DESCRIPTION: Set the dubMix object to First and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to First.
        public static void testFirstStateDub(dubMix testObj)
        {
            Console.WriteLine("Testing 'First' state:");
            testObj.setFirst();
            testPingDub(testObj);
        }
        //DESCRIPTION: Set the dubMix object to Second and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to Second.
        public static void testSecondStateDub(dubMix testObj)
        {
            Console.WriteLine("Testing 'Second' state:");
            testObj.setSecond();
            testPingDub(testObj);

        }
        //DESCRIPTION: Set the dubMix object to Interleaved and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to Interleaved.
        public static void testInterleavedStateDub(dubMix testObj)
        {
            Console.WriteLine("Testing 'Interleaved' state:");
            testObj.setInter();
            testPingDub(testObj);
        }//DESCRIPTION: Set the dubMix object to FCatS and calls
         //testPing fucntion.  Prints test name to the console.
         //PreCondition: testObj is passed as a parameter
         //PostCondition: State changed to FCatS
        public static void testCatStateDub(dubMix testObj)
        {
            Console.WriteLine("Testing 'Cat' state:");
            testObj.setCat();
            testPingDub(testObj);
        }
        //DESCRIPTION: Set the numMixers objects to Odd and calls
        //testPing fucntion. For visibility pings in First state.
        //Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State of numMixer objects to Odd.
        public static void testOddStateDub(dubMix testObj)
        {
            Console.WriteLine("Now testing Odd state:");
            testObj.setOdd();
            testObj.setFirst();
            testPingDub(testObj);
        }
        //DESCRIPTION: Set the numMixers objects to Even and calls
        //testPing fucntion. For visibility pings in First state.
        //Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State of numMixer objects to Even
        public static void testEvenStateDub(dubMix testObj)
        {
            Console.WriteLine("Now testing Even state:");
            testObj.setEven();
            testObj.setFirst();
            testPingDub(testObj);
        }
        //DESCRIPTION: Set the numMixers objects to Mix and calls
        //testPing fucntion. For visibility pings in First state.
        //Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State of numMixer objects to Mix.
        public static void testMixStateDub(dubMix testObj)
        {
            Console.WriteLine("Now testing Even state:");
            testObj.setMix();
            testObj.setFirst();
            testPingDub(testObj);
        }
        // DESCRIPTION: Returns a List of type dubMix that
        //contains 3 dubMix objects.  These are created using
        //the Default,Argument, and Copy constructors.
        //PostCondition:List of dubMix objects is created
        //and returned.
        public static List<dubMix> createTestListDub()
        {
            List<dubMix> returnList= new List<dubMix>();
            dubMix defaultDub = new dubMix();
            dubMix argsDub = new dubMix(POOLSIZE);
            dubMix copyDub = new dubMix(argsDub);

            returnList.Add(defaultDub);
            returnList.Add(argsDub);
            returnList.Add(copyDub);
            return returnList;
        }


        //-Functions to test multiMix--------------------------------

        //DESCRIPTION:Pings all the numMix object and prints the 
        //results to the console. Will return if the ping returns null.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: Results of the ping are printed to the console
        public static void testPingMulti(multiMix testObj)
        {

            int[] pingResult;
            pingResult = testObj.ping();
            if (pingResult == null)
                return;
            Console.WriteLine("Ping has returned:");
            for (int i = 0; i < pingResult.Length; i++)
            {
                Console.WriteLine(pingResult[i]);
            }
        }
        //DESCRIPTION: Set the multiMix object to Odd and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to Odd.
        public static void testStateOddMulti(multiMix testObj)
        {
            Console.WriteLine("Now testing Odd state for " +
                "multiMix:");
            testObj.setStateOdd();
            testPingMulti(testObj);
        }
        //DESCRIPTION: Set the multiMix object to Even and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to Even.
        public static void testStateEvenMulti(multiMix testObj)
        {
            Console.WriteLine("Now testing Even state for " +
                "multiMix:");
            testObj.setStateEven();
            testPingMulti(testObj);
        }
        //DESCRIPTION: Set the multiMix object to Mix and calls
        //testPing fucntion.  Prints test name to the console.
        //PreCondition: testObj is passed as a parameter
        //PostCondition: State changed to Mix.
        public static void testStateMixMulti(multiMix testObj)
        {
            Console.WriteLine("Now testing Mix state for " +
                "multiMix:");
            testObj.setStateMix();
            testPingMulti(testObj);
        }
        //DESCRPIPTION:Gives the empty status before the add and then
        //adds one numMixer object to multiMix objec then gives empty
        //status again.
        //Precondition:testObj is passed as a parameter
        //PostCondition:A numMixer object is added to the multiMix 
        //object and empyt status is printed to the console.
        public static void testAddMulti(multiMix testObj)
        {
            if (testObj.isEmpty())
                Console.WriteLine("Old:multiMix object is empty.");
            else
                Console.WriteLine("Old:multiMix object not empty.");

            testObj.add();
            Console.WriteLine("added.");

            if (testObj.isEmpty())
                Console.WriteLine("New:multiMix object is empty.");
            else
                Console.WriteLine("New:multiMix object not empty.");

        }
        //DESCRPIPTION:Gives the empty status before the remove and then
        //removes one numMixer object to multiMix objec then gives empty
        //status again.
        //Precondition:testObj is passed as a parameter
        //PostCondition:A numMixer object is removed from the multiMix 
        //object and empyt status is printed to the console.
        public static void testRemoveMulti(multiMix testObj)
        {
            int removeFirst = 0;
            if (testObj.isEmpty())
                Console.WriteLine("Old:multiMix object is empty.");
            else
                Console.WriteLine("Old:multiMix object not empty.");

            testObj.removeAt(removeFirst);
            Console.WriteLine("object removed");

            if (testObj.isEmpty())
                Console.WriteLine("New:multiMix object is empty.");
            else
                Console.WriteLine("New:multiMix object not empty.");
        }
        // DESCRIPTION: Returns a List of type multiMix that
        //contains 3 multiMix objects.  These are created using
        //the Default,Argument, and Copy constructors.
        //PostCondition:List of multiMix objects is created
        //and returned.
        public static List<multiMix> createTestListMulti()
        {
            List<multiMix> returnList = new List<multiMix>();
            multiMix defaultMulti = new multiMix();
            multiMix argsMulti = new multiMix(MULTIARG);
            multiMix copyMulti = new multiMix(argsMulti);

            returnList.Add(defaultMulti);
            returnList.Add(argsMulti);
            returnList.Add(copyMulti);
            return returnList;
        }
        //DESCRIPTION:Tests the default constructor object of multiMix
        //since it starts with zero numMixer objects. Calls the 
        //Add and remove test functions to test Add,Remove, and isEmpty
        //methods from the multiMix class.
        //Precondition:testObj is passed in and is empty
        //PostCondition: Will have a single numMixer object for further
        //testing.
        public static void testDefaultMulti(multiMix testObj)
        {
            Console.WriteLine("Now testing Default multiMix object");
            Console.WriteLine("Note: Object starts empty.");
            testAddMulti(testObj);
            testRemoveMulti(testObj);
            testAddMulti(testObj);
        }
        //DESCRIPTION: Main driver function for the program. Declares the
        //Lists for dubMix and multiMix then calls the test functions
        //to put all objects in the list through the same test. Prints
        //to the screen formatting and labeling between each object test
        //for better readability in the console.
        //PostCondition: Output printed to the console
        static void Main()
        {
            //declare list and set equal to the return value
            //of createTestListDub
            List<dubMix> dubList = createTestListDub();
            for(int i = 0; i < dubList.Count; i++)
            {
                if(i == FIRSTOBJ)
                {
                    Console.WriteLine("Testing default Constructed Object");
                }
                else if(i == SECONDOBJ)
                {
                    Console.WriteLine("----------------------------------");
                    Console.WriteLine("Testing argument Constructed Object");
                }
                else
                {
                    Console.WriteLine("----------------------------------");
                    Console.WriteLine("Testing copy Constructed Object");
                }
                //Test for dubMix
                testFirstStateDub(dubList[i]);
                testSecondStateDub(dubList[i]);
                testInterleavedStateDub(dubList[i]);
                testCatStateDub(dubList[i]);
                testOddStateDub(dubList[i]);
                testEvenStateDub(dubList[i]);
                testMixStateDub(dubList[i]);
            }
            //declare list and set equal to the return value
            //of createTestListMulti
            List<multiMix> multiList = createTestListMulti();
            for(int i = 0; i < multiList.Count; i++)
            {
                if(i == FIRSTOBJ)
                {
                    //special test for first object.
                    testDefaultMulti(multiList[i]);
                }
                else if(i == SECONDOBJ)
                {
                    Console.WriteLine("----------------------------------");
                    Console.WriteLine("Testing argument Constructed Object");
                }
                else
                {
                    Console.WriteLine("----------------------------------");
                    Console.WriteLine("Testing copy Constructed Object");
                }
                //Test for each object
                testStateOddMulti(multiList[i]);
                testStateEvenMulti(multiList[i]);
                testStateMixMulti(multiList[i]);
            }
            //Keep output on console until user enters keystroke.
            Console.ReadLine();
        }

    }
}
