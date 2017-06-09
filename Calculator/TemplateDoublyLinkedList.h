#ifndef TEMPLATEDOUBLYLINKEDLIST_H
#define TEMPLATEDOUBLYLINKEDLIST_H

/*--------DLL.h--------*/
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// extend range_error from <stdexcept>
template <typename T>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

template <typename T>
class DoublyLinkedList; // class declaration

// list node
template <typename T>
class DListNode {
private:
  T obj;
  T key;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(T e= T(), T k= T(), DListNode<T> *p = nullptr, DListNode<T> *n = nullptr)
    : obj(e), key(k) prev(p), next(n) {}
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template <typename T>
class DoublyLinkedList {
protected: DListNode<T> header, trailer;
public:
  DoublyLinkedList() : header(T()), trailer(T()) //constructor
    { header.next = &trailer; trailer.prev = &header; }
  
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
  
  ~DoublyLinkedList(); // destructor
  
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; } //should there be a const?
  // check if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
};
// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);



/*---------------DLL.cpp---------------*/
// programming assignment 3

// copy constructor
//O(n)
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  
  // Copy from dll
  // Complete this function

  DListNode<T> *temp_node;
  temp_node = dll.getFirst();

  while(temp_node != dll.getAfterLast())
  {
      this->insertLast(temp_node->getElem());
      temp_node = temp_node->next;
  }

}

// assignment operator
//O(n)
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
  // header.next = &trailer;
  // trailer.prev = &header;
  if (this != &dll)
  {
    while(!isEmpty())
    {
      this->removeFirst();
    }

    DListNode<T> *temp_nodeC;
    temp_nodeC = dll.getFirst();

    while (temp_nodeC != dll.getAfterLast())
    {
        this ->insertLast(temp_nodeC->getElem());
        temp_nodeC = temp_nodeC->next;
    }

  }

return *this;

}

// insert the object to the first of the linked list
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}

// insert the object to the last of the linked list
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}

// remove the first object of the list
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  DListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}

// remove the last object of the list
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  T key = node->key;
  delete node;
  return obj,key;
}

// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList<T>()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  
  return header.next->obj;
}

// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  return trailer.prev->obj;
}

// output operator
//O(n)
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
  DListNode<T> *temp_node;
  temp_node = dll.getFirst();

  while(temp_node != dll.getAfterLast())
  {

      out <<fixed<<setprecision(1)<<temp_node -> getElem() << " ";
      temp_node = temp_node -> getNext();
  }
  return out;
}
#endif