/*
** MyFirstSketch.ino
** located in a directory MyFirstSketch/ as otherwise the Arduino IDE does not
** like to open the sketch.
**
** In addition to the built-in LED, this example will use the serial port and
** also an additional Digital IO at Pin 10 for a second LED which is located
** on the breadboard and secured with a 330 Ohm resistor.
**
** E.g. Wire -> D10 -> Resistor -> LED (long Pin)
**      Wire <- GND <- LED (short Pin)
*/
// constants won't change. Used here to set a pin number:
const int led1Pin = LED_BUILTIN; // built in LED
const int led2Pin = 10; // use small breadboard, 330 Ohm resistor for

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// Variable, as we want to change this
long interval = 1000;  // interval at which to blink (milliseconds)
byte count = 1; // wraps around after 255 has been reached
// via the serial port ..
byte inByte = 0;        // incoming serial byte

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  Serial.println("Running blinking LED example with loop...");
  Serial.println("send '+' and '-' to increase/decrease interval");
  Serial.println("send 'r' to reset to default interval, external LED dark");

  Serial.print("Interval set to ");
  Serial.println(interval);

  // set the digital pin as output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() 
{
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) 
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) 
    {
      ledState = HIGH;
      Serial.print("HIGH ");
    } 
    else 
    {
      ledState = LOW;
      Serial.println("LOW");
    }

    // set the LEDs with the ledState of the variable:
    digitalWrite(led1Pin, ledState);
    analogWrite(led2Pin, count++);
    if ( ledState == HIGH )
    {
      Serial.println(count);
    }
    if ( Serial.available() > 0)
    {
      inByte = Serial.read();
      Serial.print("Received: ");
      Serial.println(inByte);
      if ( inByte == '-' )
      {
        interval -= 250;
        if ( interval < 0 )
        {
          interval = 100;
        }
        Serial.print("Interval set to ");
        Serial.println(interval);
      }
      else if ( inByte == '+' )
      {
        interval += 250;
        Serial.print("Interval set to ");
        Serial.println(interval);
      }
      else if ( inByte == 'r' )
      {
        interval = 1000;
        count = 1;
        Serial.print("Reset; Interval set to ");
        Serial.println(interval);
      }
    }
  }
}
