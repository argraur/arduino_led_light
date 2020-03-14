// LEDs quantity
#define LED_QUANTITY 6

// LED class
class LedLight {
// Private space
private:
  // Port number
  int port;

// Public space
public:
  // Main constructor
  LedLight::LedLight(int _port) { port = _port; };

  // Method for enabling the LED
  void enable() { digitalWrite(port, 255); };

  // Method for disabling the LED
  void disable() { digitalWrite(port, LOW); };

  // Enables LED with a given delay
  void enableWithDelay(int _delay) {
    delay(_delay);
    enable();
  };

  // Disables LED with a given delay
  void disableWithDelay(int _delay) {
    delay(_delay);
    disable();
  };
  
  // Registers LEDs for output.
  void setup() { pinMode(port, OUTPUT); };

  // Returns port integer for manual tasks.
  int getPort() { return port; };
};

// Register LEDs or LED.
#ifdef LED_QUANTITY
LedLight led[LED_QUANTITY] = NULL;
#else
LedLight led = null;
#endif

  
void setup() {
  // Initialize LED(s).
  int port = 1;

#ifdef LED_QUANTITY
  for (int i = 0; i < LED_QUANTITY; i++) {
    led[i] = LedLight(port);
    port += 2; // LEDs are connected in every 2 ports
  }

  for (int i = 0; i < LED_QUANTITY; i++) {
    led[i].setup();
  }
#else
  led = LedLight(port);
  led.setup();
#endif
}

// the loop function runs over and over again forever
void loop() {
  int ms = 100; // Default 100 ms delay
  // Enable and disable all LEDs with a increasing delay
  for (int j = 0; j < 5; j++) {
    ms = 100 * j; // Increase ms by j times 5 times
#ifdef LED_QUANTITY
    for (int i = 0; i < LED_QUANTITY; i++) {
      led[i].enableWithDelay(ms);
      led[i].disableWithDelay(ms);
    }
#else
    led.enableWithDelay(ms);
    led.disableWithDelay(ms);
#endif
  }

  // Enable and disable all LEDs with a decreasing delay
  for (int j = 5; j > -1; j--) {
    ms = 100 * j;
#ifdef LED_QUANTITY
    for (int i = 0; i < LED_QUANTITY; i++) {
      led[i].enableWithDelay(ms);
      led[i].disableWithDelay(ms);
    }
#else
    led.enableWithDelay(ms);
    led.disableWithDelay(ms);
#endif
  }

  // loop
}
