//AUTHOR: Tyler Yamashiro
//FILENAME:p5.cpp
//DAte 5/29/18
//REVISION HISTORY: V 1.0
/*DESCRIPTION:
Test driver for numMixer.cpp mulitMix.cpp and dubMix.cpp.  This is
designed to test the functionality of the overloaded
assignement operators in each class.
The overloaded operators are the: +, +=, -, -=, =, ==,!= operators.These are
supported throughout each of the classes.
Only the dubMix and multiMix classes are openly tested since the
functionality of the overloaded operators of those two classes
are depended on the functionality of the matching operator in the numMIxer
class. If the dubMix and multiMix overloaded operators work then the
numMixer operators also work.  There are six functions each that test
a different pair of operators.  + and +=, - and -= , == and != for the dubMix
and multi mix classes.  The assignement operator is tested throughout.
The tests are the same for both objects.  The results are printed to the screen.
*/
#include "dubMix.h"
#include "multiMix.h"
#include <iostream>
using namespace std;

//Description: Creates Two dubMix objecs and uses the Assignement
//operator to create two identical objects then tests the addition
//and the addition assignement operators printing the results to the
//screen.
void testPlusOperatorDubMixer(){
  cout<<"----------------TESTING PLUS OPERATOR----------------" <<endl;
  dubMix t1;
  dubMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"Testing Overloaded Plus Operator"<< endl;
  dubMix t3 = t1+ t2;
  int* t3ResultHolder;
  int t3Size;
  t1ResultHolder = t1.ping(t1Size);
  t3ResultHolder=t3.ping(t3Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Sum Obj:"<< endl;
  for(int i = 0; i < t3Size; i++)
    cout << t3ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t3ResultHolder;

  //===============================================================
  cout <<"Testing Overloaded Plus Equals Operator"<< endl;
  t1+= t2;
  t1ResultHolder = t1.ping(t1Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
}
//Description: Creates Two dubMix objecs and uses the Assignement
//operator to create two identical objects then tests the subtraction
//and the subtractionassignement operators printing the results to the
//screen.
void testMinusOperatorDubMixer(){
  cout<<"---------------TESTING MINUS OPERATOR----------------" << endl;
  dubMix t1;
  dubMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"Testing Overloaded Minus Operator"<< endl;
  dubMix t3 = t1- t2;
  int* t3ResultHolder;
  int t3Size;
  t1ResultHolder = t1.ping(t1Size);
  t3ResultHolder=t3.ping(t3Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Subtracted Obj:"<< endl;
  for(int i = 0; i < t3Size; i++)
    cout << t3ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t3ResultHolder;

  //===============================================================
  cout <<"Testing Overloaded Minus Equals Operator"<< endl;
  t1-= t2;
  t1ResultHolder = t1.ping(t1Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
}
//Description: Creates Two multiMix objecs and uses the Assignement
//operator to create two identical objects then tests the addition
//and the addition assignement operators printing the results to the
//screen.
void testPlusOperatorMultiMixer(){
cout<<"----------------TESTING PLUS OPERATOR----------------" <<endl;
  multiMix t1;
  t1.add_back();
  multiMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"Testing Overloaded Plus Operator"<< endl;
  multiMix t3 = t1+ t2;
  int* t3ResultHolder;
  int t3Size;
  t1ResultHolder = t1.ping(t1Size);
  t3ResultHolder=t3.ping(t3Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Sum Obj:"<< endl;
  for(int i = 0; i < t3Size; i++)
    cout << t3ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t3ResultHolder;

  //===============================================================
  cout <<"Testing Overloaded Plus Equals Operator"<< endl;
  t1+= t2;
  t1ResultHolder = t1.ping(t1Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
}
//Description: Creates Two multiMix objecs and uses the Assignement
//operator to create two identical objects then tests the subtraction
//and the subtraction assignement operators printing the results to the
//screen.
void testMinusOperatorMultiMixer(){
cout<<"----------------TESTING Minus OPERATOR----------------" <<endl;
  multiMix t1;
  t1.add_back();
  multiMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"Testing Overloaded Plus Operator"<< endl;
  multiMix t3 = t1- t2;
  int* t3ResultHolder;
  int t3Size;
  t1ResultHolder = t1.ping(t1Size);
  t3ResultHolder=t3.ping(t3Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Sum Obj:"<< endl;
  for(int i = 0; i < t3Size; i++)
    cout << t3ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
  delete[] t3ResultHolder;

  //===============================================================
  cout <<"Testing Overloaded Plus Equals Operator"<< endl;
  t1-= t2;
  t1ResultHolder = t1.ping(t1Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  delete[] t1ResultHolder;
}
//Description: Creates Two multiMix objecs and uses the Assignement
//operator to create two identical objects then tests the equals to
//and the not equals to operators printing the results to the
//screen.
void testComparisonDubMix(){
  cout<<"----------------TESTING COMPARISON OPERATORS----------------" <<endl;
  dubMix t1;
  dubMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;

  //===============================================================
  cout <<"----Testing Equal to Operator----"<< endl;
  if(t1 == t2)
    cout <<"Obj 1 and Obj 2 are equal." << endl;
  else if(t1 != t2)
    cout <<"Obj1 and Obj 2 not equal. " << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"---Testing Not Equal to Operator---"<< endl;
  t1+= t2;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder = t2.ping(t2Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  cout <<"---Testing Not Equal to Operator---"<< endl;
  if(t1 == t2)
    cout <<"Obj 1 and Obj 2 are equal." << endl;
  else if(t1 != t2)
    cout <<"Obj1 and Obj 2 not equal. " << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
}
//Description: Creates Two multiMix objecs and uses the Assignement
//operator to create two identical objects then tests the equals to
//and the not equals to assignement operators printing the results to the 
//screen.
void testComparisonMultiMix(){
  cout<<"----------------TESTING COMPARISON OPERATORS----------------" <<endl;
  multiMix t1;
  t1.add_back();
  multiMix t2;
  t2 = t1;
  cout<<"Obj 2 is a copy of Obj 1 via Overloaded Assignemnt Operator "<< endl;
  int* t1ResultHolder;
  int* t2ResultHolder;
  int t1Size;
  int t2Size;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder=t2.ping(t2Size);
  cout<<"Testing Overloaded Assignement Operator Result" << endl;
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;

  //===============================================================
  cout <<"----Testing Equal to Operator----"<< endl;
  if(t1 == t2)
    cout <<"Obj 1 and Obj 2 are equal." << endl;
  else if(t1 != t2)
    cout <<"Obj1 and Obj 2 not equal. " << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
  //===============================================================
  cout <<"---Testing Not Equal to Operator---"<< endl;
  t1+= t2;
  t1ResultHolder = t1.ping(t1Size);
  t2ResultHolder = t2.ping(t2Size);
  cout<<"Object 1: "<< endl;
  for(int i = 0; i < t1Size; i++)
    cout << t1ResultHolder[i] << ' ';
  cout << endl;
  cout <<"Object 2:"<< endl;
  for(int i = 0; i < t2Size; i++)
    cout << t2ResultHolder[i] << ' ';
  cout << endl;
  cout <<"---Testing Not Equal to Operator---"<< endl;
  if(t1 == t2)
    cout <<"Obj 1 and Obj 2 are equal." << endl;
  else if(t1 != t2)
    cout <<"Obj1 and Obj 2 not equal. " << endl;
  delete[] t1ResultHolder;
  delete[] t2ResultHolder;
}
int main(){
  cout <<"======NOW TESTING DUBMIXER OPERATORS=======" <<endl;
  testPlusOperatorDubMixer();
  testMinusOperatorDubMixer();
  testComparisonDubMix();
  cout << endl;
  cout <<"======NOW TESTING MULTIMIX OPERATORS========" <<endl;
  testPlusOperatorMultiMixer();
  testMinusOperatorMultiMixer();
  testComparisonMultiMix();
}
