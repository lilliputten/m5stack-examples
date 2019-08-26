/** @module Interactive_h
 *  @since 2019.08.26, 20:03
 *  @changed 2019.08.26, 20:03
 */

#ifndef _Interactive_h_
#define _Interactive_h_

#ifdef ESP32 // Arduino build
  #include <M5Stack.h>
  // #include <WString.h>
#else
  #ifndef BTN_A
    #define BTN_A 777
  #endif
  #ifndef BTN_B
    #define BTN_B 888
  #endif
  #ifndef BTN_C
    #define BTN_C 999
  #endif
#endif

#ifndef NO_BTN
  #define NO_BTN -1
#endif

class Interactive {

  private:

    String id = "";

    bool enabled = true;

    int buttonPressed = NO_BTN;

  public:

    // Interactive();
    explicit Interactive(String id = "");
    virtual ~Interactive();

    void init();

    virtual void setEnabled(bool enabled);
    virtual bool getEnabled();
    virtual void enable();
    virtual void disable();

    virtual void setId(String id);
    virtual String getId();

    virtual int wasPressed();

    virtual int pollButtons();

};

#endif // _Interactive_h_
