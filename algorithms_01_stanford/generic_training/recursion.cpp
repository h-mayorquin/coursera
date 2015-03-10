// Small program to test recursion
#include<iostream>


using std::cout;
using std::endl;

int factorial(int n){

  // Good, so it works the idea is just to provide a way that your function 
  // escape from it 
  int result = 1; 
  if( n > 0){
    result = n * factorial( n - 1);
  }
  else{
    result = result;
  }

  return result; 
}


int main()
{
  int n = 6; //Number to calculate factorial
  int result; 
 
  result = 1; // Intialize result 

  for(int i=n; i > 0; --i){
    result = result * i; 
  }

  cout << "The loop gives " << result << endl;
  cout << "The function gives " << factorial(n) << endl;


  return 0;
}
