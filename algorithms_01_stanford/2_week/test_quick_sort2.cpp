#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "vector.h"

using namespace std; 

int partition(vector<int> &A, int left_limit, int right_limit, int &aux_counter){
  /* In this function we need to sort the array so the pivot is in the midle and the */
  int pivot_index; 
  int pivot; 
  int aux;

  aux = A[right_limit];
  A[right_limit] = A[left_limit];
  A[left_limit] = aux;

  // Chose which element is going to be the pivot 
  pivot_index = left_limit; 

  // So first let's chose the pivot 
  pivot = A[pivot_index];
  int i = left_limit + 1; // Limit of vectors smaller than the pivot 
  for(int j=i; j<right_limit; ++j){
    aux_counter++;
    if (A[j] < pivot){
    // Swap A[i] and A[j]
      aux = A[i];
      A[i] = A[j];
      A[j] = aux;
      ++i;
    }
  }
  // Swap the pivot with the right-most of the smaller than the pivot elements 
  aux = A[i - 1];
  A[i - 1] = pivot; 
  A[pivot_index] = aux;
  pivot_index = i - 1; 
    
  return pivot_index; 
}


void quick_sort(vector<int> &array, int left_limit, int right_limit, int &m, int &aux_counter){
  if(left_limit < right_limit - 1){
    // Count things 
    int array_length = right_limit - left_limit;
    m += (array_length - 1); 
    cout << "left and right limits ( " << left_limit << " , " << right_limit << ")" << endl;
    cout << "m = " << m << " add = " << (array_length - 1) << endl; 
    
    // Routines 

    int k = partition(array, left_limit, right_limit, aux_counter); //partition
    quick_sort(array, left_limit, k, m, aux_counter);
    quick_sort(array, k + 1, right_limit, m, aux_counter);
  }

}

int main(){

  int n = 10; 
  vector<int> array;
  int m = 0; // counter
  int aux_counter = 0; // Aux counter 
  
  // Create and show the array 
  array = sample_without_replacement(n);
  print_vector(array);

  // Order and show the array 
  quick_sort(array, 0, n, m, aux_counter);
  print_vector(array);

  cout << "counter " << m << endl;
  cout << "aux counter " << aux_counter << endl;


  return 0;
}
