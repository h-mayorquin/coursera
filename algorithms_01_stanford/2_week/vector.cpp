#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <random>

#include "vector.h"

using namespace std; 

void print_vector(vector<int> vector){
  cout << string(10, '-') << endl;
  cout << "("; 
  for(int i=0; i < vector.size() - 1; ++i){
    cout << vector[i] << ", ";
  }
  cout << vector[vector.size() - 1];
  cout << ")" << endl;

}


vector<int> sample_without_replacement(int n){
  random_device rd;
  mt19937 gen(rd());
  vector<int> sequence;
  
  //file the sequence
  for(int i=0; i<n; ++i ){
    sequence.push_back(i);
  }

  // shufle it
  shuffle(sequence.begin(), sequence.end(), gen);

  return sequence; 
}


