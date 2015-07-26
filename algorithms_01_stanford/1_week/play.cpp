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

/* ********************************
Functions declarations
**********************************/ 

void print_vector(std::vector<int> vector, std::vector<int>::iterator iter);
vector<int> sample_without_replacement(int n);

vector<int> merge_routine(vector<int> left, vector<int> right){
    unsigned left_it = 0;
    unsigned right_it = 0; 
    unsigned vector_size;
    unsigned k = 0;

    vector_size = left.size() + right.size();

    vector<int> result(vector_size);
    
    cout << "Sizes " << vector_size << endl;

    while(left_it < left.size() && right_it < right.size()){

	// Left element smaller 
	if (left[left_it] < right[right_it]){
	    result[k] = left[left_it];
	    left_it++;
	}
	
	// Right element smaller 
	if (right[right_it] < left[left_it]){
	    result[k] = right[right_it];
	    right_it++;

	}

	// Increase result counter
	k++;
	
    }
    
    while()
  
    return result;


}

/* ********************************
Main program
**********************************/ 

int main(){
    // Declarations
    std::vector<int>::iterator iter;
    vector<int> array;
    vector<int> array1, array2; 
    
    
    cout << "Print this and that" << endl;

    array = {2, 1, 3, 4, 5, 11, 14, 12, 13};
    print_vector(array, iter);
    
    /*
    int n = 3; 
    array = sample_without_replacement(n);
    print_vector(array, iter);
    */

    array1 = {4, 5, 6};
    array2 = {1, 2, 3};
    cout << "Print vectors" << endl;
    print_vector(array1, iter);
    print_vector(array2, iter);
    
    array = merge_routine(array1, array2);
    print_vector(array, iter);

}

/* ********************************
Code of functions
**********************************/ 

// Print Utility

void print_vector(std::vector<int> vector, std::vector<int>::iterator iter){
  cout << string(10, '-') << endl;
  cout << "("; 
  for(iter = vector.begin(); iter != vector.end(); ++iter){
    cout << (*iter) << ", ";
  }
  cout << ")" << endl;
}

// Random arrays utility

vector<int> sample_without_replacement(int n){
  random_device rd;
  mt19937 gen(rd());
  vector<int> sequence;
  vector<int>::iterator iter;

  //file the sequence
  for(int i=0; i<n; ++i ){
    sequence.push_back(i);
  }

  // shufle it
  shuffle(sequence.begin(), sequence.end(), gen);

  return sequence; 
}

