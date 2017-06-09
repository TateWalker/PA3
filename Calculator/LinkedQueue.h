// LinkedQueue.h
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <iostream>
#include "RuntimeException.h"
#include "TemplateDoublyLinkedList.h"

template <typename T> class LinkedQueue;

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue);

template <typename T>
class LinkedQueue {
private:
   /* declare member variables here */
DoublyLinkedList<T> s; //DLL of queue elements
int n; //size of queue

public:
   // user-defined exceptions
   class QueueEmptyException : public RuntimeException {
   public:
     QueueEmptyException() : RuntimeException("Access to an empty queue") {}
   };

   LinkedQueue(); //constructor
   int size() const;
   bool isEmpty() const;
   const T& front() const throw(QueueEmptyException);
   void enqueue(const T& e);
   T dequeue() throw(QueueEmptyException);
   friend std::ostream &operator<<<T>(std::ostream &out, const LinkedQueue<T> &queue);

   /* declare rest of functions */
};

/* describe rest of the functions here */
//constructor
template <typename T> LinkedQueue<T>::LinkedQueue()
: s(), n(0){}
//return size
template <typename T> int LinkedQueue<T>::size() const{
	return n;
}
//check if empty
template <typename T> bool LinkedQueue<T>::isEmpty() const{
	return n == 0;
}
//check if empty then return front of queue
template <typename T>
	const T& LinkedQueue<T>::front() const throw(QueueEmptyException){
		if(isEmpty()) throw QueueEmptyException();
		return s.last();
	}
//enqueue object e to end of queue
template<typename T>
		void LinkedQueue<T>::enqueue(const T& e){
			++n;
			s.insertLast(e);
		}
//dequeue object off end of queue
template<typename T>
		T LinkedQueue<T>::dequeue() throw(QueueEmptyException){
			if(isEmpty()) throw QueueEmptyException();
			--n;
			return s.removeLast();
		}
		//out operator
template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedQueue<T>& queue)
{
	out<<queue.s;
  	return out;
}
#endif