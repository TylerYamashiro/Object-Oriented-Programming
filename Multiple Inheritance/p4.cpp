//AUTHOR: Tyler Yamashiro
//FILENAME: p4.cpp
//DATE: 5/15/18
//REVISION HISTORY: Version 1
//PLATFORM(compiler,version):g++
/*DESCRiPTION:The main for the driver program p4.cpp. The program
//creates a hetergenous collection of numMixerSeer objects.
//The collection is put through tests where the same functions
//are called and the results printed to the screen.  The "seer" functionality
//of the object is tested in the first part which vary depending on
//inherited seer type.
//The second half test the numMixer part of the object testing all the
//pings and its states.  The two inherited functionalities are independent
//from each other so the functionality state changes do not affect each other
//The testing is set into functions where the number of classes can
//be changed by changing the NUMBERCLASSES constant
//The test rounds for the first half may also be changed. The other constants
//should not be altered.
*/
 /*ASSUMPTIONS:
  * class will always generate both even and odd numbers when creating its number pool. It uses the numMixer
  * class in order to run.  This also assumes that the PINGTILLTHRESHHOld value is calculated correctly
  * in order to test the active or inactive states of the object. The size of the user simulated
  * parameter for the constructor is a minimum of 15 and a maximum of 20 to make sure argument is reasonable
  * it can be increased or decreased however.
  */
  //CLASS INVARIANT:
  //The number of testing rounds for the collection is given by
  //the const int TESTROUNDS.
  //The numer of objects created is given by the NUMBERCLASSES variable
  //The Collection consists of one numMixerSeer object,
  // one numMixerVolatileSeer, and one numMixerTmSeer
  //INTERFACE INVARIANT:
  //In this case the test is programed to run 7 times inorder
  //to demonstrate the functions of all 3 objects
  //the first object is the seer, second the valatileSeer,
  //the third is the tmSeer.
  //In the second half the numMixer object is run through ping and active tests
  //for each object in the collection
  //IMPLEMENTATION INVARIANT:
  //To change the number of rounds or objects created chage
  //the const variables.  If the number of objects created
  //change the instanciaion function getObj may also have
  //to change.
#include "numMixerVolatileSeer.h"
#include "numMixerSeer.h"
#include "numMixerTmSeer.h"
#include <iostream>
#include <typeinfo>
#include <array>
const static int NUMBERCLASSES = 3;
const static int TESTROUNDS = 4;
const static int NUMMIXSEER = 0;
const static  int NMVOLATSEER= 1;
const static int  NMTMSEER = 2;
const int PINGTILLTHRESHHOLD = 7;
//Minimum of random function
const int RANDOMMIN = 15;
//Maximum of random function
const int RANDOMMAX = 20;
//DESCRIPTION:Returns a numMixerSeer base or derived class object
//based on the integer passed into the integer passed into
//the function.
//Precondition:integer for determining what class to return
//Postcondition:A class object of numMixerSeer or inherited
// from numMixerSeer is returned.
numMixerSeer* getObj(int version){
  if (version % NUMBERCLASSES == NUMMIXSEER)
      return new numMixerSeer;
  else if (version % NUMBERCLASSES == NMVOLATSEER)
      return new numMixerVolatileSeer;
  else if (version % NUMBERCLASSES == NMTMSEER)
      return new numMixerTmSeer;
  else
    return nullptr;
  }

  //DESCRIPTION:Tests the request function of each object in
  //the collectin. Looks for the empty string signifying object
  //is off string and REJECTED signifying the object has
  //rejected the request.  Prints the results to the string
  //numMixerSeer then numMixerVolatileSeer then
  //numMixerTmSeer is the order of printing
  //for each call.
  //Precondition:seer array passed in as an argument
  //PostCondition: returned reesult of each object printed
  //to the screen.
  void testRequest(numMixerSeer** arr)
  {
      std::string temp;
      std::cout << "Now testing output of request";
      std::cout << "  from each object in array:" << std::endl;
      for(int i = 0; i < NUMBERCLASSES; i++)
      {
          temp = arr[i]->Request();
          if (temp == "")
          {
              std::cout << "Object is off" << std::endl;
          }
          else if (temp == "REJECTED")
          {
              std::cout << "Request was Rejected" << std::endl;
          }
          else
            std::cout << temp << std::endl;
      }
  }
  //DESCRiPTiON:Tests the replaceRequest function in the
  //numMixerVolatileSeer objects in the array.
  //Precondition:seer type array as a parameter for the class
  //Postcondition:Replaces the message in any seer objects in
  //the colelction.
  void changeMessage(numMixerSeer** arr)
  {
      std::cout <<"Now replacing the message in numMixervolatileSeer";
      std::cout << " class objects." << std::endl;
      for(int i = 0; i < NUMBERCLASSES; i++)
      {
      //  numMixerVolatileSeer *t = dynamic_cast<numMixerVolatileSeer *>
        //(arr[i]);

          //if(t != nullptr)
        //  {
              std::string replacement = "This is a replacement.";
              arr[i]->replaceRequest(replacement);
          //}
      }

  }
  //Description: Sets the state of the object to Mix then pings the object and stores the
  //returned array then prints it to the consol to check the result.
  //Precondition: A numMixerSeer object exists and has numbers in its pool
  //PostCondition: numMixerSeer object is now in Mix state.
void testMixPing(numMixerSeer* testObj)
  {
      std::cout << "Now Testing the set mix state and ping functions." <<
      std::endl;
      int size = 0;
      testObj->setStateMix();
      int* mixTestResult = testObj->ping(size);
      for(int i = 0; i <size; i++)
      {
          std::cout << mixTestResult[i] << ", ";
      }
      std::cout << std::endl << std::endl;
      delete[] mixTestResult;
  }
  //Description: Sets the state of the object to Odd then pings the object and stores the
  //returned array then prints it to the consol to check the result.
  //Precondition: A numMixerSeer object exists and has odd numbers in its pool
  //PostCondition: numMixerSeer object is now in Odd state.
void testOddPing(numMixerSeer* testObj)
  {
    std::cout << "Now Testing the set odd state and ping functions." <<
    std::endl;
    int size = 0;
    testObj->setStateOdd();
    int* mixTestResult = testObj->ping(size);
    for(int i = 0; i < size; i++)
    {
        std::cout << mixTestResult[i] << ", ";
    }
    std::cout << std::endl << std::endl;
    delete[] mixTestResult;
  }
  //Description: Sets the state of the object to Even then pings the object and stores the
  //returned array then prints it to the consol to check the result.
  //Precondition: A numMixerSeer object exists and has Even numbers in its pool
  //PostCondition: numMixerSeer object is now in Even state.
  void testEvenPing(numMixerSeer* testObj)
  {
    std::cout << "Now Testing the set even state and ping functions." <<
    std::endl;
    int size = 0;
    testObj->setStateEven();
    int* mixTestResult = testObj->ping(size);
    for(int i = 0; i < size; i++)
    {
        std::cout << mixTestResult[i] << ", ";
    }
    std::cout << std::endl << std::endl;
    delete[] mixTestResult;
  }
  //Description: Calls the returnStateCount() method from the object and stores the
  //returned integer into the stateCount variable which is printed to the screen.
  //Precondition:Object exists to be passed in as a parameter
  void testStateCounter(numMixerSeer* testObj)
  {

      std::cout << "Now testing the State Counter" << std::endl;

      int stateCount = testObj->returnStateCount();
      std::cout <<stateCount << std::endl;
  }
  //Description: Tests if the object is active initially.  Then pings the object until its threshHold
  //is reached then tests to see if the object is still active.  It also tests the ping for a null response
  //since it will return null when pinged if inactive.
  //PreCondition:Object exists and is active.
  //PostCondition:Object becomes inactive.
void testisActive(numMixerSeer* testObj)
  {
      int size = 0;
      int* tempHolder;
      std::cout <<"Testing isActive and testing return of";
      std::cout << " ping when not active" << std::endl;
      if(testObj->isActive())
          std::cout <<"Object is Active" << std::endl;
      else
          std::cout <<"Object not Active" << std::endl;
      std::cout <<"Now reaching threshHold" << std::endl;
      for(int i = 0; i < PINGTILLTHRESHHOLD; i++)
      {
        tempHolder =  testObj->ping(size);
        delete[] tempHolder;

      }
      if(!testObj->isActive())
          std::cout <<"Object not Active" << std::endl;
      else
          std::cout <<"Object is Active" << std::endl;
      if(testObj->ping(size) == nullptr)
          std::cout <<"Ping returned Null object not active" << std::endl;
  }

//Description:The main for the driver program p4.cpp. The program
//creates a hetergenous collection of numMixerSeer objects.
//The collection is put through tests where the same functions
//are called and the results printed to the screen.  The "seer" functionality
//of the object is tested in the first part which vary depending on
//inherited seer type.
//The second half test the numMixer part of the object testing all the
//pings and its states.  The two inherited functionalities are independent
//from each other so the functionality state changes do not affect each other
//PostCondition: Prints the Results of the testing to the screen.
int main(){
  numMixerSeer* testArray[NUMBERCLASSES];
  for (int i = 0; i < NUMBERCLASSES; i++)
  {
      testArray[i] = getObj(i);
  }
  for (int i = 0; i < TESTROUNDS; i++)
  {
    std::cout<<"TEST ROUND ";
    std::cout <<  i;
    std::cout << ":" << std::endl;
      testRequest(testArray);
      changeMessage(testArray);
      testRequest(testArray);
      std::cout << endl;
  }

  std::cout << "Now Testing the NumMixer Component:" << std::endl;
  for(int j = 0; j < NUMBERCLASSES; j++){
    testMixPing(testArray[j]);
    testOddPing(testArray[j]);
    testEvenPing(testArray[j]);
    testisActive(testArray[j]);
  }

  for (int i = 0; i < NUMBERCLASSES; i++)
  {
      delete testArray[i];
  }

}
