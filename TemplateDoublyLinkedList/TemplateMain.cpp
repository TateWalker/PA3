// programming assignment 3

#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main () {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  //DoublyLinkedList<string> dll;
  //DoublyLinkedList<int> dll;
  DoublyLinkedList<double> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  //testing strings
  // for (int i=10; i<=100; i+=10) {
  //   stringstream ss;
  //   ss << i;
  //   dll.insertLast(ss.str());
  // }
  //testing ints
  // for (int i=10; i<=100; i+=10){
  //   dll.insertLast(i);
  // }
  //testing doubles
  for (double i =10.0; i<=100.0; i+=10.0){
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  //testing strings
  // for (int i=10; i<=100; i+=10) {
  //   stringstream ss;
  //   ss << i;
  //   dll.insertFirst(ss.str());
  // }
  //testing ints
  // for (int i=10; i<=100; i+=10){
  //   dll.insertFirst(i);
  // }
  //testing doubles
  for (double i =10.0; i<=100.0; i+=10.0){
    dll.insertFirst(i);
  }


  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  //DoublyLinkedList<string> dll2(dll);
  //DoublyLinkedList<int> dll2(dll);
  DoublyLinkedList<double> dll2(dll);

  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  //DoublyLinkedList<string> dll3;
  //DoublyLinkedList<int> dll3;
   DoublyLinkedList<double> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  //testing strings
  // for (int i=0; i<10; i++) {
  //   dll.removeLast();
  // }
  //testing ints
  // for (int i=0; i<10; i++){
  //   dll.removeLast();
  // }
  //testing doubles
   for (double i =0.0; i<10.0; i++){
     dll.removeLast();
   }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  //testing strings
  // for (int i=0; i<10; i++) {
  //   dll.removeFirst();
  // }
  //testing ints
  // for (int i=0; i<10; i++){
  //   dll.removeFirst();
  // }
  //testing doubles
  for (double i =0.0; i<10.0; i++){
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;
  
  return 0;
}
