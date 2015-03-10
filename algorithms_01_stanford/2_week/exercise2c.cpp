#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "vector.h"

using namespace std; 

int order(int a, int b, int c){
  int maximum = max(a, max(b, c));
  int minimum = min(a, min(b, c));
  return a + b + c - maximum - minimum;
}

int median_index(int a, int left_limit, int b, int middle, int c, int right_limit, int median){
  if(median == a){
    return left_limit;
  }
  if(median == b){
    return middle;
  }
  if(median == c){
    return (right_limit - 1);
  }
}


int partition(vector<int> &A, int left_limit, int right_limit, int &aux_counter){
  /* In this function we need to sort the array so the pivot is in the midle and the */
  int pivot_index; 
  int pivot; 
  int aux;
  int middle; 
  int array_length = right_limit - left_limit;
 
  int first_element = A[left_limit];
  // choose the middle element 
  if(array_length % 2 == 0){
    middle = array_length / 2;
    middle += (left_limit - 1);
  }else{
    middle = array_length / 2;
    middle += left_limit;
  }

  int middle_element = A[middle];
  int last_element = A[right_limit - 1];

  aux = order(first_element, middle_element, last_element);

  int aux_index =  median_index(first_element, left_limit, middle_element, middle, last_element, right_limit, aux);

  // Now we need to swap the last elements for the first one 
  aux = A[left_limit];
  A[left_limit] = A[aux_index];
  A[aux_index] = aux;

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
    // Routines 

    int k = partition(array, left_limit, right_limit, aux_counter); //partition
    quick_sort(array, left_limit, k, m, aux_counter);
    quick_sort(array, k + 1, right_limit, m, aux_counter);
  }

}


int main(){

  // Here we read the file 
  vector<int> array;
  int m = 0; // counter
  int aux_counter = 0; //aux counter 

  ifstream infile("QuickSort.txt");
  int read;

  while(infile >> read){
    array.push_back(read);
  }

  int n = array.size();

  // Order and show the array 
  quick_sort(array, 0, n, m, aux_counter);
  print_vector(array);

  cout << "counter " << m << endl;
  cout << "aux counter " << aux_counter << endl;

  return 0;
}
