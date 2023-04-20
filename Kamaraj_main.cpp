/*
Author: Rohaan Kamaraj
Date: 11/23/21
Description: The only thing this file does is contain the main method which will call the congaLine() method,
 which will simulate the zombie conga line
*/
#include <iostream>
#include <stdlib.h>
#include "Kamaraj_LinkedList.h"

using namespace std;

int main() {
  
  // creates a pointer to conga object, then simulates the conga line
  Conga* conga = new Conga();
  conga->congaLine();

  return 0;


}
