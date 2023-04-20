/*
Author: Rohaan Kamaraj
Date: 11/23/21
Description: This file contains all the method implementations for the Node, LinkedList, Zombie and Conga classes.
*/
// import libraries needed
#include <iostream>
#include <stdlib.h>
#include "Kamaraj_LinkedList.h"
#include <random>

using namespace std;

template<class T>
Node<T>::Node(T userData) { // implementation of Node constructor
  data = userData;
  next = NULL;
}

template<class T>
T Node<T>::getData() {
  return data; // data getter
}

template<class T>
void Node<T>::setData(T userData) {
  data = userData; // data setter
}

template<class T>
void Node<T>::setNext(Node* userNext) {
  next = userNext; // next node setter
}

template<class T>
LinkedList<T>::LinkedList() { // implementation of default constructor
  head = NULL;
  tail = NULL;
}


template<class T>
void LinkedList<T>::addToFront(T userData) { // adds element to the front of the list 
  
  if (head == NULL && tail == NULL) { // if theres no elements in the list
    Node<T>* node = new Node<T>(userData);
    head = node;
    tail = node;
  } else { // if there is an existing element in the list
    Node<T>* node = new Node<T>(userData);
    node->setNext(head);
    head = node;
  }
}

template<class T>
void LinkedList<T>:: addToEnd(T userData) { // adds element to the end of the list
  
  if (head == NULL && tail == NULL) { // if theres no element in the list
    Node<T>* node = new Node<T>(userData);
    tail = node;
    head = node;
  } else { // if there is an existing element in the list
    Node<T>* node = new Node<T>(userData);
    tail->setNext(node);
    tail = node;
  }
}

template<class T>
void LinkedList<T>:: printList() { // prints the list out

  Node<T>* node = head;

  while (node != NULL) {

    cout << node->getData() << ' ';
    node = node->next;
    
  }

  cout << endl;

}

template<class T>
int LinkedList<T>:: length() { // finds the number of elements in the list

  int count = 0;

  if (head == NULL & tail == NULL) {
    return count;
  }

  Node<T>* node = head;
  
  while (node != NULL) {
    count++;
    node = node->next;
  }

  return count;

}

template<class T>
int LinkedList<T>:: indexOf(T userData) { // returns the location of the node containing the data passed in

  int tracker = 0;

  if (head == NULL && tail == NULL) {
    return tracker;
  }

  Node<T>* node = head;

  bool keepGoing = true;
  
  while (keepGoing || node != NULL) {
    if (userData == node->getData()) {
      keepGoing = false;
      break;
    } else {
      tracker++;
      node = node->next;
    }
  }

  return tracker;

}

template<class T>
void LinkedList<T>::empty() { // empties out the array

  if (head == NULL && tail == NULL) {
    // do nothing bc already empty
  } else {
    
    Node<T>* node = head;
    head = NULL;

    while (node != NULL) {
      node->next = NULL;
      free(node);
      node = node->next;
    }

  }

}

template<class T>
T LinkedList<T>::retrieveFront() { // returns the data of the head node
  return head->getData();
}

template<class T>
T LinkedList<T>::retrieveEnd() { // returns the data of the tail node
  return tail->getData();
}

template<class T>
T LinkedList<T>::retrieve(int index) { // returns the data from the node at the index passed in
  
  int counter = 0;

  Node<T>* node = head;

  

  while (node != NULL) {
    if (counter == index) {
      return node->getData();
    } else {
      counter++;
      node = node->next;
    }
  }

  return counter;

}

template<class T>
bool LinkedList<T>::elementExists(T userData) { // finds whether the data passed in exists in the list or not

  bool exists = false;

  Node<T>* node = head;

  while (node != NULL) {
    if (node->getData() == userData) {
      exists = true;
    }
    node = node->next;
  }

  return exists;

}

template<class T>
T LinkedList<T>::removeFromFront() { // removes the head node

  T value = head->getData();
  Node<T>* node = head;
  head = head->next;
  free(node);

  return value;

}

template<class T>
T LinkedList<T>::removeFromEnd() { // removes the tail node

  T value = tail->getData();

  Node<T>* node = head;

  while (node != NULL) {
    
    if (node->next->next == NULL) {
      Node<T>* end = tail;
      node->next = NULL;
      free(end);
      break;
    }
    else {
      node = node->next;
    }
  }
  
  return value;
}

template<class T>
void LinkedList<T>::removeTheFirst(T userData) { // removes the first instance of the data passed in 

  Node<T>* node = head;

  bool removed = true;

  if (node->next == NULL) {
    head = NULL;
  }

  while (removed && node->next != NULL) {
    if (node->next->getData() == userData) {
      Node<T>* node2 = node->next;
      node->next = node->next->next;
      free(node2);
      removed = false;
      break;
    } else {
      node = node->next;
    } 
  }

}

template<class T>
void LinkedList<T>::removeAllOf(T userData) { // removes all instances of the data passed in

  Node<T>* node = head;

  if (node->next == NULL) {
    head = NULL;
  }

  while (node->next != NULL) {

    if (node->next->getData() == userData) {
      Node<T>* node2 = node->next;
      node->next = node->next->next;
      free(node2);
    } else {
      node = node->next;
    }
  }
}

template<class T>
bool LinkedList<T>::addAtIndex(T userData, int index) { // inserts an element at the index specified

  bool successful = true;

  if (head == NULL && tail == NULL) {
    addToFront(userData);
    return successful;
  }

  Node<T>* inputNode = new Node<T>(userData);
  
  if (index == 0) {
    addToFront(userData);
    return successful;
  } else if (index == length() - 1) {
    addToEnd(userData);
    return successful;
  }

  Node<T>* node = head;
  int tracker = 0;

  while (tracker < index - 1) {
    node = node->next;
    tracker++;
  }

  inputNode->next = node->next;
  node->next = inputNode;

  return successful;
}

Zombie::Zombie() { // default constructor, randomly generates color

  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,6);
  random = generate(gen);

  color = 'A'; // will be overwritten below

  if (random == 1) {
    color = 'R';
  } else if (random == 2) {
    color = 'Y';
  } else if (random == 3) {
    color = 'G';
  } else if (random == 4) {
    color = 'B';
  } else if (random == 5) {
    color = 'M';
  } else {
    color = 'C';
  }

}

Zombie::Zombie(char userColor) { // second constructor that allows color to be chosen
  color = userColor;
}

char Zombie::getColor() { // getter for zombie color
  return color;
}

void Zombie::engine(LinkedList<Zombie>* list, Zombie zombie) { // engine action for zombies
  list->addToFront(zombie);
}

void Zombie::caboose(LinkedList<Zombie>* list, Zombie zombie) { // caboose action for zombies
  list->addToEnd(zombie);
}

void Zombie::jumpInLine(LinkedList<Zombie>* list, Zombie zombie) { // jump in line action for zombies
  int length = list->length();
  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(0, length - 1);
  random = generate(gen);

  list->addAtIndex(zombie, random);
  
}

void Zombie::everyoneOut(LinkedList<Zombie>* list, Zombie zombie) { // everyone out action for zombies
  list->removeAllOf(zombie);
}

void Zombie::youreDone(LinkedList<Zombie>* list, Zombie zombie) { // you're done action for zombies
  list->removeTheFirst(zombie);
}

void Zombie::brains(LinkedList<Zombie>* list, Zombie zombie) { // brains action for zombies
  int middle = list->length() / 2;

  Zombie zombie2(zombie.getColor());
  Zombie zombie3(zombie.getColor());
  Zombie zombie4(zombie.getColor());

  list->addToFront(zombie2);
  list->addAtIndex(zombie3, middle);
  list->addToEnd(zombie4);
}

void Zombie::rainbowBrains(LinkedList<Zombie>* list, Zombie zombie) { // rainbow brains action for zombies
  list->addToFront(zombie);
  
  Zombie zombie2('R');
  Zombie zombie3('Y');
  Zombie zombie4('G');
  Zombie zombie5('B');
  Zombie zombie6('M');
  Zombie zombie7('C');

  list->addToEnd(zombie2);
  list->addToEnd(zombie3);
  list->addToEnd(zombie4);
  list->addToEnd(zombie5);
  list->addToEnd(zombie6);
  list->addToEnd(zombie7);

}

ostream& operator<<(ostream& out, Zombie zombie) { // overloading the [cout] << operator
  out << '[';
  out << zombie.getColor();
  out << ']';
  return out;
}

bool operator==(Zombie zombie1, Zombie zombie2) { // overloading the == operator
  return zombie1.getColor() == zombie2.getColor();
}

int getRandomNumber() { // simple random number generator to set up the initial conga line
  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(2,5);
  random = generate(gen);
  return random;
}

int generateAction() { // random number generator to decide the action that will affect the congo line
  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(1,7);
  random = generate(gen);
  return random;
}

int whichZombie(int max) { // random number generator to decide which zombie in the list will the action be performed on or with
  int random;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> generate(0,max-1);
  random = generate(gen);
  return random;
}

void Conga::congaLine() { // Conga line method: simulates the entire zombie congo line
 
  LinkedList<Zombie>* list = new LinkedList<Zombie>();

  Zombie starter;
  Zombie::rainbowBrains(list, starter);

  list->printList();
  
  int random = getRandomNumber();
  for (int i = 0; i < random; i++) {
    Zombie brain;
    Zombie::brains(list, brain);
  }

  list->printList();

  bool isRunning = true;
  int rounds;
  bool isPartyOver = false;

  cout << "Welcome to the crazy fun Zombie congo line!" << endl;

  while (isRunning) { // the while loop that starts the simulation
    
    cout << "How many rounds would you like to run?: ";
    cin >> rounds;
    cout << endl;
    
    for (int i = 0; i < rounds; i++) { // the for loop that actually runs the simulation
      cout << "Round: " + to_string(i) << endl;
      cout << "The Zombie Party keeps on groaning!" << endl;
      cout << "Size: " + to_string(list->length()) + " :: ";
      list->printList();

      int action = generateAction(); // randomly generate the action
      int zombiePosition = whichZombie(list->length()); // randomly pick the zombie in the list in which the action will be performed on
      cout << "action: " + to_string(action) << endl;
      cout << "zombie position: " + to_string(zombiePosition) << endl;
      
      if (action == 1) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::engine(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie jumps in front of the line! (ENGINE)" << endl;
      }
      else if (action == 2) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::caboose(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie pulls up the rear! (CABOOSE)" << endl;
      }
      else if (action == 3) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::jumpInLine(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie jumps into the line! (JUMPINLINE)" << endl;
      }
      else if (action == 4) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::everyoneOut(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie and all of his friends are removed from the party! (EVERYONEOUT)" << endl;
      }
      else if (action == 5) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::youreDone(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie's friend is removed from the party! (YOU'RE DONE)" << endl;
      }

      else if (action == 6) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::brains(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie brings its friends to the party! (BRAINS!)" << endl;
      }
      else if (action == 7) {
	Zombie z = list->retrieve(zombiePosition);
	Zombie::rainbowBrains(list, list->retrieve(zombiePosition));
	cout << z;
	cout << " zombie brought a whole party itself! (RAINBOW BRAINS!)" << endl;
      }

      if (list->length() == 0) {
	cout << "Oh no! The party is over!" << endl;
	isPartyOver = true;
	break;
      }

      // display updated congo line
      cout << "The conga line is now:" << endl;
      cout << "Size: " + to_string(list->length()) + " :: ";
      list->printList();

      cout << "******************" << endl;
      cout << endl;
    }

    if (isPartyOver) {
      break;
    }

    int userContinue = 0;

    cout << "Would you like the party to continue? Enter 1 if yes, and any other number if no: ";
    cin >> userContinue;
      
    if (userContinue == 1) {
      // the loop will start from the beginning and ask the user for how many rounds 
    } else {
      cout << "Okay! The party is now over!" << endl;
      isRunning = false;
    } 
    
  }

}
