/** @module InteractiveStack_cpp
 *  @since 2019.08.26, 20:03
 *  @changed 2019.08.26, 20:03
 */

#ifndef _InteractiveStack_cpp_
#define _InteractiveStack_cpp_

#include "InteractiveStack.h"

#include "../Interactive/Interactive.cpp"

// Singleton
InteractiveStack* InteractiveStack::__singleton = 0; InteractiveStack InteractiveStack::singleton() {
  if (InteractiveStack::__singleton == 0) InteractiveStack::__singleton = new InteractiveStack();
  return *InteractiveStack::__singleton;
}

InteractiveStack::InteractiveStack(void) {
  this->size = 0;
}

int InteractiveStack::getSize() {
  return this->size;
}
void InteractiveStack::push(Interactive* ptr) {
  if (this->size + 1 >= INTERACTIVE_STACK_SIZE) {
    throw std::overflow_error("Cant' push Max Interactive: stack size exceeded");
  }
  this->ptrStack[this->size++] = ptr;
}
Interactive* InteractiveStack::pop() {
  if (this->size <= 0) {
    throw std::overflow_error("Can't pop Interactive: empty stack");
  }
  Interactive* ptr = this->ptrStack[--this->size];
  return ptr;
}
Interactive* InteractiveStack::getActive() {
  Interactive* ptr = (this->size > 0) ? this->ptrStack[this->size - 1] : 0;
  return ptr;
}

#endif // _InteractiveStack_cpp_
