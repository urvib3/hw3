#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  // m-ary tree
  int m_; 

  // comparator
  PComparator comp_; 

  // stores all data as a complete tree
  std::vector<T> data_; 
  
  // conversion functions between parent and child
  size_t parent(int child) const; 
  size_t child(int parent, int numChild) const; 
  bool hasChild(int parent) const; 
  size_t minChild(int parent) const; 

  void printData() {
    std::cout << "data in current heap" << std::endl; 
    for(T d : data_)  
      std::cout << d << " "; 
    std::cout << std::endl; 
  }

};

// Add implementation of member functions here


template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) 
{}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const 
{
  return data_.empty(); 
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const 
{
  return data_.size(); 
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){

    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("top() may not be called on an empty stack"); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_[0]; 


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{

  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("top() may not be called on an empty stack"); 
  }

  // swap first(top of the tree) and last item
  // remove last item (essentially deleting the top of the tree)
  std::swap(data_[0], data_[data_.size()-1]); 
  data_.pop_back(); 


  // while item has child and item is worse than its best child
  int i = 0; 
  while(hasChild(i) && comp_(data_[minChild(i)], data_[i])) {

    int minChildIndex = minChild(i); 
    std::swap(data_[i], data_[minChildIndex]); 
    i = minChildIndex; 

  }


}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  
  // append item to the back of the vector
  data_.push_back(item); 

  // while item is not the root and is better than parent, trickle up
  int i = data_.size() - 1; 
  while(i > 0 && comp_(data_[i], data_[parent(i)])) {
    std::swap(data_[i], data_[parent(i)]); 
    i = parent(i); 
  }
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::parent(int child) const{
  return (child - 1) / m_; 
}

// numChild = 1 corresponds to the first child node from the left of parent
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::child(int parent, int numChild) const {
  return m_ * parent + numChild; 
}

// returns true if the parent has a child and false if it is a leaf node
// parent has a child if its first child's index is within the data_ vector's range
template <typename T, typename PComparator>
bool Heap<T, PComparator>::hasChild(int parent) const{
  return child(parent, 1) < data_.size(); 
}

// returns the index of the best child (to replace its parent in trickle down)
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::minChild(int parent) const{

  // sets initial best child to the first child
  int min = child(parent, 1); 

  // loop through from the second child to the m child to determine a better child
  for(int i = 2; i <= m_; i++) {
    int curChild = child(parent, i); 
    
    // check that curChild is a valid index
    if(curChild >= data_.size()) break;

    if(comp_(data_[curChild], data_[min]))
      min = curChild; 
  }

  return min; 

}


#endif

