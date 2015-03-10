#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>

#include "vector.h"

using namespace std; 


int main()
{
  string line; 
  vector<string> data; 

  
  ifstream infile("kargerMinCut.txt");
  
  if(!infile){
    cout << "no file " << endl; 
  }

  while(infile){
    getline(infile, line);
    data.push_back(line); // Put data in the vector 
  }
  

  vector<list<int> > graph (data.size());

  cout << "Number of nodes = " <<  data.size() << endl;
  for(int i=0; i < data.size(); ++i){
    // Make the i row a string-stream 
    stringstream iss(data[i]);
    int number;
    list<int> aux_list; 
    while(iss >> number){
      aux_list.push_back(number);
    }
    graph[i] = aux_list; 
    
  }

  int node = 0; 
  list<int>::iterator list_iterator; 
  cout << data[node] << endl; 
  for(list_iterator=graph[node].begin(); list_iterator!=graph[node].end(); ++list_iterator){
    cout << (*list_iterator) << " "; 

  }
  

  return 0; 
}
