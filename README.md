# arduino_playground
Playground for Arduino UNO (V3) stuff

As usual: Links

  * Official homepage: https://www.arduino.cc/
  * https://docs.arduino.cc/tutorials/uno-rev3/getting-started/
  * https://www.youtube.com/watch?v=d8_xXNcGYgo&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-
  * https://docs.arduino.cc/language-reference/de/

After some initial playing around with the Arduino and the official IDE,
I found that I could continue to use Sublime Text with the Stino package
installed to compile and upload stuff to the Arduino. It even comes with
a Serial Monitor. --> Unfortunately, this blocks my Sublime under Linux
Mint so hard that it was not usable anymore - especially when it does
not find the Arduino Uno board, so this package had been removed.

However, the Arduino IDE does work as well - for the first steps it is
good. It "hides" some stuff from the programmer which might be good for
new programmers but a bit questionable for people who knows what is
going on. Anyway... The Arduino language is more C++ than I expected.

Tested with the "first" example which is also available here.

Btw: Errors in Linux Mint (or whatever) when uploading, I  had to insert
into etc/udev/rules.d/99-arduino.rules the following line:
SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", GROUP="plugdev", MODE="0666"


