#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "vector.h"

using namespace std; 

int partition(vector<int> &A, int left_limit, int right_limit){
  /* In this function we need to sort the array so the pivot is in the midle and the */
  int pivot_index; 
  int pivot; 
  int aux;

  // Chose which element is going to be the pivot 
  pivot_index = left_limit; 

  // So first let's chose the pivot 
  pivot = A[pivot_index];
  int i = left_limit + 1; // Limit of vectors smaller than the pivot 
  for(int j=i; j<right_limit; ++j){
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


void quick_sort(vector<int> &array, int left_limit, int right_limit){
  //cout << "left and right limits ( " << left_limit << " , " << right_limit << ")" << endl;
  if(left_limit < right_limit - 1){
    int k = partition(array, left_limit, right_limit); //partition
    quick_sort(array, left_limit, k);
    quick_sort(array, k + 1, right_limit);
  }

}

int main(){

  int n = 10; 
  vector<int> array;
  
  // Create and show the array 
  array = sample_without_replacement(n);
  print_vector(array);

  // Order and show the array 
  quick_sort(array, 0, n);
  print_vector(array);

  return 0;
}
