/** @module InteractiveStack_h
 *  @since 2019.08.26, 20:03
 *  @changed 2019.08.26, 20:03
 */

#ifndef _InteractiveStack_h_
#define _InteractiveStack_h_

#ifdef ESP32 // Arduino build
#endif

#include "../Interactive/Interactive.h"

#define INTERACTIVE_STACK_SIZE 10

class InteractiveStack {

  // Singleton...
  private: static InteractiveStack* __singleton;
  public: static InteractiveStack singleton();

  private:

    Interactive* ptrStack[INTERACTIVE_STACK_SIZE];
    int size;

  public:

    InteractiveStack();

    int getSize();
    void push(Interactive* ptr);
    Interactive* pop();
    Interactive* getLast();

    void lastRender();
    int lastPollButtons();
    int lastWasPressed();

};

#endif // _InteractiveStack_h_
