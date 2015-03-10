#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

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

int main()
{
  vector<int> sequence; 
  vector<int>::iterator iter; 
  int n = 10;

  sequence = sample_without_replacement(n);

  for(iter=sequence.begin(); iter!=sequence.end(); ++iter){
    cout << *iter << endl;
  }


  return 0; 
}
