/** @module Interactive_h
 *  @since 2019.08.26, 20:03
 *  @changed 2019.08.26, 20:03
 */

#ifndef _Interactive_h_
#define _Interactive_h_

#ifdef ESP32 // Arduino build
#include <M5Stack.h>
// #include <WString.h>
#endif

#define NO_BTN -1

class Interactive {

  private:

    String id = "";

    bool enabled = true;

    int buttonPressed = NO_BTN;

  public:

    // Interactive();
    Interactive(String id);

    void init();

    void setEnabled(bool enabled);
    bool getEnabled();
    void enable();
    void disable();

    void setId(String id);
    String getId();
    int wasPressed();
    void pollButtons();

};

#endif // _Interactive_h_
