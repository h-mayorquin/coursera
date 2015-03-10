#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;


long brute_force_inv(vector<int> &array){
  long number_of_inv = 0;
  int n = array.size();
  
  for(int i=0; i < n; ++i){
    for(int j=0; j <i; j++){
      if(array[i] < array[j]){
	++number_of_inv;
      }
    }

    cout << "steps to go=" << (n - i) << endl; 
    cout << "inversions so far " << number_of_inv << endl; 
  }
  return number_of_inv;
}



int main(){
  
  cout << "This code will order an array using quicksort" << endl;
  srand(time(NULL)); // Initialize the random number 

  vector<int> array; 
  std::vector<int>::iterator iter;

  // read the file 
  ifstream infile("IntegerArray.txt");
  int read; 
  while(infile >> read){
    array.push_back(read);
  }
  long number_of_inv;
  number_of_inv  = brute_force_inv(array);

  cout << number_of_inv;

  
  return 0;
}
