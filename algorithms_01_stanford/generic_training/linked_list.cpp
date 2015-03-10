/* Program to play with linked lists */

#include <iostream>


using namespace std; 

int main()
{
  class IntNode{
  public:
    int info;
    IntNode *next; 

    IntNode(int el, IntNode *ptr=0){
      info = el;
      next = ptr;
    }
  };

  IntNode *p = new IntNode(10);

  cout << (*p).info << endl; // This is the method of the class to which p points 
  cout << p -> next << endl; 


  
  

  return 0;
}
