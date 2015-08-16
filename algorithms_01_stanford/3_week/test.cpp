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

void select_edge(int *node_u, int *node_v, vector<vector<int> > &graph){

    // First select a node
    cout << "Select edge graph size" << graph.size() << endl;

    (*node_u) = rand() % graph.size()  + 1;
    vector<int> aux_vector = graph[(*node_u) - 1];

    // Then select and edge
    print_node((*node_u), graph);

    int index_v = rand() % aux_vector.size();
    
    cout << "Index " << index_v << endl;
    cout << "node v size" << aux_vector.size() << endl;

    (*node_v) = aux_vector[index_v];

    cout << "node v" << (*node_v) << endl;

}

// Now we have a function to merge

void merge(int node_u, int node_v, vector<vector<int> > &graph){
    vector<int>::iterator vector_iterator; 
    vector<int>::iterator vector_iterator2; 
    int x; 

    for(vector_iterator=graph[node_v - 1].begin(); vector_iterator!=graph[node_v - 1].end(); ++vector_iterator){
	x = (*vector_iterator);  // This is the node that node_v points to
	// Now we need to change the contents of the vector x
	for(vector_iterator2=graph[x - 1].begin(); vector_iterator2!=graph[x - 1].end(); ++vector_iterator2){
	    if ((*vector_iterator2)== node_v){
		(*vector_iterator2) = node_u;
	    }
	}
    }
    
}


void erase_node_v(int node_v, vector<vector<int> > &graph){
    
    for(int i=0; i<graph.size(); ++i){
	if(i == (node_v - 1)){
	    graph.erase(graph.begin() + i);
	}
    }
}

// Now we need to erase the self loops
void erase_self_loop(int node_u, vector<vector<int> > &graph){
    for(int i=0; i<graph[node_u - 1].size(); ++i){
	if(graph[node_u - 1][i]  == node_u){
	    graph[node_u - 1].erase(graph[node_u - 1].begin() + i);
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
  

  int node_u, node_v; 

  while(graph.size() > 2){
      cout << "graph size " << graph.size() << endl;

      // First we select a node
      // select_edge(&node_u, &node_v, graph);
      node_u = rand() % graph.size();
      vector<int> aux_vector = graph[node_u];

      // Then select and edge
      print_node(node_u, graph);

      int index_v = rand() % aux_vector.size();
    
      cout << "Index " << index_v << endl;
      cout << "node v size " << aux_vector.size() << endl;

      node_v = aux_vector[index_v];

      cout << "node v " << node_v << endl;


      cout << "outside u is " << node_u << endl;
      cout << "outside v is " << node_v << endl;

      // Then we merge the nodes u and v
      merge(node_u, node_v, graph);
      cout << "merged" << endl;

      // No we erase the self loops
      erase_self_loop(node_u, graph);
      cout << "self loop erased" << endl;

      // No we need to erase the node_v
      erase_node_v(node_v, graph);
      cout << "node erased" << endl;
  
      cout << "print node u for errors" << endl;
      print_node(node_u - 1, graph);
      // Jump the line to visualize
      cout << endl;
  }
  return 0; 

}
