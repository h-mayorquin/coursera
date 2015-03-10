/* I wrote this file on 31/10/14 in order to play with the notion of copy constructors */

#include <iostream>
//#include <string>
#include <cstring> 


using namespace std;


// This the structure for a node 
struct Node{
  char *name;
  int age;
  Node(char *n, int a=0){
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    age = a;
  }
}


int main()
{
  
  Node node1;
  node1.name = "Proven";
  node1.age = 20;
  cout << node1.name << endl;
  cout << node1.age << endl;

  return 0;
}
