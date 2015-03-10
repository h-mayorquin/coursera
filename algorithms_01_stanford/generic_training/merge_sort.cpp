#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> sample_without_replacement(int n);
void print_vector(std::vector<int> vector, std::vector<int>::iterator iter);


vector<int> merge(vector<int> &vec, vector<int> &left, vector<int> &right)
{
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
    //show merge process..
      int i;
      for(i=0;i<result.size();i++)
         {                                
	     cout<<result[i]<<" ";
         }
    // break each line for display purposes..
        cout<<"***********"<<endl; 
 
    //take a source vector and parse the result to it. then return it.  
	vec = result;				
	return vec;
}


vector<int> merge_sort(vector<int> &vec)
{
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
    left = merge_sort(left);
    right = merge_sort(right);
 
    return merge(vec, left, right);
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
  // Order the vector 
  merge_sort(array);
  // print the vectora gain to see the output 
  print_vector(array, iter);

  
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
