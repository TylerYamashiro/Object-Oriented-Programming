//AUTHOR: Tyler Yamashiro
//FILENAME: p1.cs
//DATE: 4/10/18
//REVISION HISTORY: Version 1
//PLATFORM(compiler,version):
/*DESCRIPTION: This is a driver file to test the numMixer class functionality. Two numMixer objects will
 * be created one is the origonal the other is a copy made through the copy constructor.  The driver 
 * sets the state of the object to mix then odd then even and pings it each time printing the results to
 * the consol.  After 3 pings it checks the number of state changes by calling the state change counter.
 * Finally it pings the object until its max ping thresh hold is attained and checks to see if the 
 * object is still active or not. It repeats the process using a object with a pool size given by the user
 */
 /*ASSUMPTIONS: Uses System, System.IO and System.Text in order to print to consol.  The only input is the 
  * Consol.Readline() at the end to prevent the consol from immediately closing.  This driver assumes the 
  * class will always generate both even and odd numbers when creating its number pool. It uses the numMixer
  * class in order to run.  This also assumes that the PINGTILLTHRESHHOld value is calculated correctly
  * in order to test the active or inactive states of the object. The size of the user simulated
  * parameter for the constructor is a minimum of 15 and a maximum of 20 to make sure argument is reasonable
  * it can be increased or decreased however.
  */
using System;
using System.IO;
using System.Text;
    class p1
    {   //Abritrary number of number of pings remaining till threshHold is hit. Based on how many times 
        //oject has been pinged already
        const int PINGTILLTHRESHHOLD = 7;
        //Minimum of random function
        const int RANDOMMIN = 15;
        //Maximum of random function
        const int RANDOMMAX = 20;
        //Description: Sets the state of the object to Mix then pings the object and stores the
        //returned array then prints it to the consol to check the result.
        //Precondition: A numMixer object exists and has numbers in its pool
        //PostCondition: numMixer object is now in Mix state.
        public static void testMixPing(numMixer testObj)
        {
            Console.WriteLine("Now Testing the set mix state and ping functions.");
            testObj.setStateMix();
            int[] mixTestResult = testObj.ping();
            for(int i = 0; i < mixTestResult.Length; i++)
            {
                Console.WriteLine(mixTestResult[i]);
            }
            Console.WriteLine(' ');
        }
        //Description: Sets the state of the object to Odd then pings the object and stores the
        //returned array then prints it to the consol to check the result.
        //Precondition: A numMixer object exists and has odd numbers in its pool
        //PostCondition: numMixer object is now in Odd state.
        public static void testOddPing(numMixer testObj)
        {
            Console.WriteLine("Now Testing the set odd state and ping functions.");
            testObj.setStateOdd();
            
            int[] oddTestResult = testObj.ping();
            for(int i = 0; i < oddTestResult.Length; i++)
            {
                Console.WriteLine(oddTestResult[i]);
            }
            Console.WriteLine(' ');
        }
        //Description: Sets the state of the object to Even then pings the object and stores the
        //returned array then prints it to the consol to check the result.
        //Precondition: A numMixer object exists and has Even numbers in its pool
        //PostCondition: numMixer object is now in Even state.
        public static void testEvenPing(numMixer testObj)
        {
            Console.WriteLine("Now Testing the set even state and ping functions.");
            testObj.setStateEven();
            int[] evenTestResult = testObj.ping();
            for(int i = 0; i < evenTestResult.Length; i++)
            {
                Console.WriteLine(evenTestResult[i]);
            }
            Console.WriteLine(' ');
        }           
        //Description: Calls the returnStateCount() method from the object and stores the
        //returned integer into the stateCount variable which is printed to the screen.
        //Precondition:Object exists to be passed in as a parameter
        public static void testStateCounter(numMixer testObj)
        {
            Console.WriteLine("Now testing the State Counter");
            int stateCount = testObj.returnStateCount();
            Console.WriteLine(stateCount);
            Console.WriteLine(' ');
            
        }
        //Description: Calls the copy constructor on the parameter object and
        //copies it to itself.  Then runs the tests for mix, even, and odd pings.
        //Also runs the testStateCounter and the result should be the origonals
        //state counter plus the number of pings in this test(3).
        public static void testCopyConstructor(numMixer testObj)
        {
            numMixer testObj2 = new numMixer(testObj);
            Console.WriteLine("These are the values of the new copied object using copy constructor.");
            Console.WriteLine(' ');
            testMixPing(testObj2);
            testOddPing(testObj2);
            testEvenPing(testObj2);
            testStateCounter(testObj2);
        }
        //Description: Tests if the object is active initially.  Then pings the object until its threshHold
        //is reached then tests to see if the object is still active.  It also tests the ping for a null response
        //since it will return null when pinged if inactive.
        //PreCondition:Object exists and is active.
        //PostCondition:Object becomes inactive.
        public static void testisActive(numMixer testObj)
        {   
            Console.WriteLine("Testing isActive and testing return of ping when object not active");
            if(testObj.isActive())
                Console.WriteLine("Object is Active");
            else
                Console.WriteLine("Object not Active");
            Console.WriteLine("Now reaching threshHold");
            for(int i = 0; i < PINGTILLTHRESHHOLD; i++)
            {
                testObj.ping();
            }
            if(!testObj.isActive())
                Console.WriteLine("Object not Active");
            else
                Console.WriteLine("Object is Active");
            if(testObj.ping() == null)
                Console.WriteLine("Ping returned Null object not active");
            Console.WriteLine(' ');
        }
        //Description: The main driver for the program. Calls the functions above in order to test the functionality 
        //of the numMixer class. A random int is created to simulate user given parameter in the constructor as well
        //as creating a numMixer object using a default constructor.
        //Precondition: Linked with numMixer.cs so it can create objects and test the class
        //Postcondition: Two numMixer constructors are called and objects created in Main()
        static void Main()
        {  
            Random number = new Random();
            numMixer testObj1 = new numMixer();
            numMixer testObj3 = new numMixer(number.Next(RANDOMMIN,RANDOMMAX));
            testMixPing(testObj1);
            testOddPing(testObj1);
            testEvenPing(testObj1);
            testStateCounter(testObj1);
            testCopyConstructor(testObj1);
            testisActive(testObj1);
            Console.WriteLine("----------------------------------------------------------------------------------------");
            Console.WriteLine("Now testing object with user defined pool size");
            testMixPing(testObj3);
            testOddPing(testObj3);
            testEvenPing(testObj3);
            testStateCounter(testObj3);
            testCopyConstructor(testObj3);
            testisActive(testObj3);
            Console.ReadLine();
        }
    }
