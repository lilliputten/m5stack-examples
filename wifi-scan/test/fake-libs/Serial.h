/** @module Serial_h
 *  @since 2019.08.23, 21:47
 *  @changed 2019.08.23, 21:47
 */

#ifndef _Serial_h_
#define _Serial_h_

// Singleton class
class SERIAL {

  // // Singleton...
  // private: static SERIAL* __singleton;
  // public: static SERIAL singleton();

  public:

  void begin(int speed);
  void print(String str);
  void println(String str);

};

SERIAL Serial;

#endif // _Serial_h_
// vim: ft=arduino
