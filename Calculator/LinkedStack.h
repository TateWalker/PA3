// LinkedStack.h
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template <typename T> class LinkedStack;

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack);
    
template <typename T>
class LinkedStack {
private:
  /* declare member variables here */
DoublyLinkedList<T> s; //DLL of stack elements
int n; //size of stack

public:
   // user-defined exceptions
   class StackEmptyException : public RuntimeException {
   public:
     StackEmptyException() : RuntimeException("Stack is empty") {}
   };
   
   LinkedStack(); //constructor
   int size() const;
   bool isEmpty() const;
    T top() const throw(StackEmptyException);
   void push(const T& e);
   T pop() throw(StackEmptyException);
   friend std::ostream &operator<<<T>(std::ostream &out, const LinkedStack<T> &stack);
   /* declare rest of functions */
      
};

/* describe rest of the functions here */
//constructor
template <typename T> LinkedStack<T>::LinkedStack()
: s(), n(0){}
//return size
template <typename T> int LinkedStack<T>::size() const{
	return n;
}
//check if empty
template <typename T> bool LinkedStack<T>::isEmpty() const{
	return n == 0;
}
//check if empty, then return top
template <typename T>
	 T LinkedStack<T>::top() const throw(StackEmptyException){
		if(isEmpty()) throw StackEmptyException();
		return s.first();
	}
//push object e to top of the stack
template <typename T>
	void LinkedStack<T>::push(const T& e){
		++n;
		s.insertFirst(e);
	}
//pop object off of top of stack
template <typename T>
	T LinkedStack<T>::pop() throw(StackEmptyException){
		if(isEmpty()) throw StackEmptyException();
		--n;
		return s.removeFirst();
	}
//out operator
template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedStack<T>& stack)
{
  	out<<stack.s;
   return out;
}
#endif