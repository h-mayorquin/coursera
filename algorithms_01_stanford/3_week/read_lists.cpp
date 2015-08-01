#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <sstream>
#include <ctime>

#include "vector.h"

using namespace std; 

// This is for printing a particular node
  
void print_node(int node_number, vector<vector<int> > graph){
    vector<int>::iterator vector_iterator; 
    
    cout << "This is node number " << node_number << endl;

    for(vector_iterator=graph[node_number - 1].begin(); vector_iterator!=graph[node_number - 1].end(); ++vector_iterator){
    cout << (*vector_iterator) << " "; 
  }
    cout << endl;
      
}

void select_edge(int *node_u, int *node_v, vector<vector<int> > graph){

    // First select a node
    (*node_u) = rand() % graph.size();
    vector<int> aux_vector = graph[(*node_u)];

    // Then select and edge
    int index_v = rand() % aux_vector.size();
    (*node_v) = aux_vector[index_v];

}

// Now we have a function to merge

void merge(int node_u, int node_v, vector<vector<int> > &graph){
    vector<int>::iterator vector_iterator; 
    vector<int>::iterator vector_iterator2; 
    int x; 
    for(vector_iterator=graph[node_v - 1].begin(); vector_iterator!=graph[node_v - 1].end(); ++vector_iterator){
	// cout << "----------------------" << endl;
	x = (*vector_iterator);  // This is the node that node_v points to
	// First we print the vector
	// Now we need to change the contents of the vector x
	for(vector_iterator2=graph[x - 1].begin(); vector_iterator2!=graph[x - 1].end(); ++vector_iterator2){
	    if ((*vector_iterator2)== node_v){
		(*vector_iterator2) = node_u;
	    }
	}
    }

}



int main()
{
  string line; 
  vector<string> data; 
  // Set the seed
  srand(time(NULL));

  // First we load the file
  
  ifstream infile("kargerMinCut.txt");
  
  if(!infile){
    cout << "no file " << endl; 
  }

  while(infile){
    getline(infile, line);
    data.push_back(line); // Put data in the vector 
  }
  
  // Now we define the graph as a vector of vector. 
  // Every entry in the vector is a node, and each node is 
  // a vector with the adjancent nodes. 

  vector<vector<int> > graph (data.size());

  int n = data.size();

  cout << "Number of nodes = " <<  n << endl;

  for(int i=0; i < data.size(); ++i){
    // Make the i row a string-stream 
    stringstream iss(data[i]);
    int number;
    vector<int> aux_vector; 
    // As long as there is something on the buffer
    while(iss >> number){
	if(number != i + 1){
	    aux_vector.push_back(number);
	}
    }
    graph[i] = aux_vector;
    
  }
  
  
  // First we select a node
  int node_u, node_v; 
  select_edge(&node_u, &node_v, graph);

  cout << "outside u is " << node_u << endl;
  cout << "outside v is " << node_v << endl;

  // First let's print node_v
  print_node(node_v, graph);
  // Then we merge the nodes u and v
  merge(node_u, node_v, graph);

  // No we need to erase the node_v
  vector<int>::iterator vector_iterator; 

  cout << "Size " << graph.size() << endl;

  print_node(node_v - 1, graph);
  print_node(node_v, graph);
  print_node(node_v + 1, graph);

  cout << "node _ v" << node_v << endl;


  for(int i=0; i<graph.size(); ++i){
      if(i == (node_v - 1)){
	  graph.erase(graph.begin() + i);
      }
  }

  //  print_node(node_v, graph);
  cout << "Size " << graph.size() << endl;

  print_node(node_v - 1, graph);
  print_node(node_v, graph);
  print_node(node_v + 1, graph);

  return 0; 

}
