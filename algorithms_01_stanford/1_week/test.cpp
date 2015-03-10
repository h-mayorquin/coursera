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

vector<int> sample_without_replacement(int n);
void print_vector(std::vector<int> vector, std::vector<int>::iterator iter);
vector<int> merge(vector<int> &vec, vector<int> &left, vector<int> &right, long &inv_number);
vector<int> merge_sort(vector<int> &vec, long &inv_number);

long brute_force_inv(vector<int> &array){
  long number_of_inv = 0;
  int n = array.size();
  
  for(int i=0; i < n; ++i){
   
    for(int j=0; j <i; j++){
      if(array[i] < array[j]){
	cout << "inversion = (" << array[i] << "," << array[j] << ")" << endl;
	++number_of_inv;
      }
    }
    
    //cout << "steps to go=" << (n - i) << endl; 
    //cout << "inversions so far " << number_of_inv << endl; 
  }
  return number_of_inv;
}



int main(){
  
  cout << "This code will order an array using quicksort" << endl;
  srand(time(NULL)); // Initialize the random number 

  vector<int> array; 
  std::vector<int>::iterator iter;
  /*
  // read the file 
  ifstream infile("IntegerArray.txt");
  int read; 
    while(infile >> read){
    array.push_back(read);
  }


  // build a reversed array 
  int n = 15;
  for(int i=0; i < n; ++i){
    array.push_back(n-i);
  }
    */
  //  an arbitrary array
  array = {2, 1, 3, 4, 5, 11, 14, 12, 13};
  int n = 10;
  array = sample_without_replacement(n);
  print_vector(array, iter);

  long number_of_inv;
  number_of_inv  = brute_force_inv(array);
  cout << n * ( n - 1) / 2 << endl;
  cout << "Brute force " << number_of_inv << endl;
  number_of_inv = 0; 
  merge_sort(array, number_of_inv);
  cout << "merge count " << number_of_inv << endl;


  return 0;
}

//-----------------------------------------------
// Functions 
//-----------------------------------------------


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


vector<int> merge(vector<int> &vec, vector<int> &left, vector<int> &right, long &inv_number){
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    unsigned left_it = 0, right_it = 0;
 
    while(left_it < left.size() && right_it < right.size())
    {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
	    inv_number = inv_number + left.size();
	    
        }
    }
 
    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }
 
    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;

    }
	vec = result;				
	return vec;
}



vector<int> merge_sort(vector<int> &vec, long &inv_number){
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1)
    {
        return vec;
    }
 
    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
 
    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());
 
    // Perform a merge sort on the two smaller vectors
    left = merge_sort(left, inv_number);
    right = merge_sort(right, inv_number);

    return merge(vec, left, right, inv_number);
}
