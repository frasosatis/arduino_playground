// constants won't change. Used here to set a pin number:
const int ledPin = LED_BUILTIN;  // the number of the LED pin

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// Variable, as we want to change this
long interval = 1000;  // interval at which to blink (milliseconds)

// via the serial port ..
int inByte = 0;        // incoming serial byte

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  Serial.println("Running blinking LED example with loop...");

  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
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
      Serial.println("HIGH");
    } 
    else 
    {
      ledState = LOW;
      Serial.println("LOW");
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);

    if ( Serial.available() > 0)
    {
      inByte = Serial.read();
      Serial.print("Received: ");
      Serial.println(inByte);
      if ( inByte == 45 )
      {
        interval -= 250;
        Serial.print("Interval set to ");
        Serial.println(interval);
      }
      else if ( inByte == 43 )
      {
        interval += 250;
        Serial.print("Interval set to ");
        Serial.println(interval);
      }
    }
  }
}
