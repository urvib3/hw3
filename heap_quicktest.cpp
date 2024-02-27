#include <iostream>
#include "heap.h"

using namespace std; 

int main(int argc, char* argv[]) {
  Heap<int, less<int>> heap(3); 
  heap.push(5); 
  heap.push(4); 
  heap.push(8); 
  heap.push(4); 
  heap.push(6); 
  heap.push(3); 
  
  cout << heap.top() << " " << endl;
  heap.pop(); 
  cout << heap.top() << " " << endl;
  heap.pop(); 
  cout << heap.top() << " " << endl;
  heap.pop(); 
  cout << heap.top() << " " << endl;
  heap.pop(); 
  cout << heap.top() << " " << endl;
  heap.pop(); 
  cout << heap.top() << " " << endl;



}