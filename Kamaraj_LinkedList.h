/*
Author: Rohaan Kamaraj
Date: 11/23/21
Description: This header file contains the Node, LinkedList, Zombie and Conga classes. They contain all the public and protected
fields and methods that make these classes up.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// defining a template T
template <class T>

class Node // creating the Node class
{

  // protected fields
protected: 
  T data;

  // public fields
public:
  Node* next;

  // public methods
public:
  Node(T userData); // constructor
  T getData(); // getter
  void setData(T userData); // setter
  void setNext(Node* userNext); // setter

};

template <class T> // defining template T

class LinkedList // creating the LinkedList class
{

  // protected fields
protected:
  Node<T>* head;
  Node<T>* tail;

  // public methods
public:
  LinkedList(); // constructor
  void addToFront(T userData); // adds element to front of list
  void addToEnd(T userData); // adds element to end of list
  bool addAtIndex(T userData, int index); // adds element at the index
  void printList(); // prints the list
  T removeFromFront(); // removes the first element
  T removeFromEnd(); // removes the last element
  void removeTheFirst(T userData); // finds first instance of the data passed in and deletes it
  void removeAllOf(T userData); // finds all instances of the data passed in and deletes it
  bool elementExists(T userData); // finds whether the data passed in is in the list
  int indexOf(T userData); // finds where the data passed in is on the list
  T retrieveFront(); // retrieves the first element
  T retrieveEnd(); // retrieves the last element
  T retrieve(int index); // retrieves the element at the index
  void empty(); // empties the list
  int length(); // finds the list's number of elements
};

class Zombie // Zombie class
{

 protected: // attributes of the Zombie
  char color;
  
public:
  Zombie(); // default constructor
  Zombie(char userColor); // second constructor
  // i made these methods static so i could randomly pick a zombie from the list each round to run the method on
  static void engine(LinkedList<Zombie>* list, Zombie zombie); // zombie becomes first in conga line
  static void caboose(LinkedList<Zombie>* list, Zombie zombie); // zombie becomes last in conga line
  static void jumpInLine(LinkedList<Zombie>* list, Zombie zombie); // zombie joins line at a random position
  static void everyoneOut(LinkedList<Zombie>* list, Zombie zombie); // removes all matching zombies from the line
  static void youreDone(LinkedList<Zombie>* list, Zombie zombie); // removes the first matching zombie from the line
  static void brains(LinkedList<Zombie>* list, Zombie zombie); // generates 3 more matching zombies and adds one to the front, middle and end
  static void rainbowBrains(LinkedList<Zombie>* list, Zombie zombie); // adds zombie to the front, then adds a zombie of each color to the end of the line
  char getColor(); // getter for color
  friend ostream& operator<<(ostream& out, Zombie zombie); // << overload
  friend bool operator==(Zombie zombie1, Zombie Zombie2); // == overload
};

class Conga { // Conga class
  friend class Zombie; // friends with the Zombie class :)

public:
  void congaLine(); // has only one method which is to actually run the program
};
