#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

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


void print_vector(std::vector<int> vector, std::vector<int>::iterator iter){
  cout << string(10, '-') << endl;
  cout << "("; 
  for(iter = vector.begin(); iter != vector.end(); ++iter){
    cout << (*iter) << ", ";
  }
  cout << ")" << endl;
}


int order(std::vector<int> &array, std::vector<int>::iterator iter,int left_limit,int right_limit){

  int pivot = *(array.begin() + left_limit) ; // takes the first element
  cout << " The pivot is " <<  pivot << endl;

  // Order the elements on the left
  vector<int> left; 
  vector<int> right;

 for(iter=array.begin() + left_limit; iter !=array.begin() + right_limit; ++iter){
  if( (*iter) < pivot ){ 
    left.push_back((*iter)); // send to the left the smaller 
  }
  else{
    right.push_back((*iter)); // send ot the right the bigger 
  }    
 }

 print_vector(left, iter);
 print_vector(right, iter);
 
 // Let's introduce the elements on the left 
 for(int i = 0; i < left.size(); ++i){
   array[i + left_limit] = left[i];
 }
 // Now we introduce the elements on the right 
 for(int i=0; i < right.size(); ++i){
   array[i + left_limit + left.size()] = right[i];
 }


 return left.size() + left_limit; 
}

void quick_sort(std::vector<int> &array, std::vector<int>::iterator iter, int left_limit, int right_limit){
  cout << "left limit " << left_limit << " right limit " << right_limit << endl;

  if(left_limit < right_limit - 1){
    int p = order(array, iter, left_limit, right_limit); // Partition the vector
    cout << "p " << p << endl; 
    print_vector(array, iter);
    quick_sort(array, iter, left_limit, p);
    quick_sort(array, iter, p + 1, right_limit);
    
  }
}


int main(){
  cout << "This code will order an array using quicksort" << endl;
  srand(time(NULL)); // Initialize the random number 

  int n = 10; // array length
  int max_range = 10; // maximum integer 

  vector<int> array; 
  std::vector<int>::iterator iter;

  array = sample_without_replacement(n);

  // Print the vector 
  print_vector(array, iter);
  quick_sort(array, iter, 0, n);
  print_vector(array, iter);

   

  
  return 0;
}
