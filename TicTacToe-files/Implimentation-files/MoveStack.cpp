// File Name: MoveStack.cpp
//
// Author: Chloe Gentry, c638
// Collaborators: Joy Davis, hxo4
// Date: 4/17/2023
// Assignment Number: 6
// CS 2308 Spring 2023
//
// Implimentation of MoveStack member functions.

#include "MoveStack.h"
#include <iostream>
#include <assert.h>
using namespace std; 

//***********************************************************
// MoveStack(): Creates the empty stack.
//***********************************************************

MoveStack::MoveStack() {
  head=-1;
}

MoveStack::~MoveStack() { 
}

//***********************************************************
// getSize: Returns the current size of the stack.
//***********************************************************

int MoveStack::getSize() {
  return currStackSize;
}

//***********************************************************
// top: Returns the move at the top of the stack without 
//   removing it from the stack.
//***********************************************************

Move MoveStack::top() { 
  assert(!isEmpty());
  return gameStack[head]; 
}

//***********************************************************
// push: Ensures stack is not full before adding a valid 
//   move to the top of the stack, also increases current
//   stack size to accomodate addition.
// Move move: User-entered coordinates into struct move (x, y).
//***********************************************************
void MoveStack::push(Move move) {
  assert (!isFull());
  head++; 
  gameStack[head]=move; 
  currStackSize++;
}

//***********************************************************
// pop: Ensures stack is not empty before removing the first 
//   element of the stack. Also decrements current stack size 
//   to accomodate removal.
//***********************************************************

void MoveStack::pop() {
  assert (!isEmpty()); 
  head--; 
  currStackSize--;
}

//***********************************************************
// isFull: Checks whether stack is full.
// Returns true if stack is full, otherwise returns false.
//***********************************************************

bool MoveStack:: isFull() const {
  if (head==stackSize-1) { 
    return true;
  } else { 
    return false;
  }
}

//***********************************************************
// isEmpty: Checks whether stack is empty.
// Returns true if stack is empty, otherwise returns false.
//***********************************************************
bool MoveStack:: isEmpty() const {
  if (head==-1) { 
    return true;
  } else { 
    return false;
  }
}