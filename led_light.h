// LEDs quantity
#define CONFIG_LED_QUANTITY 3
//#define LED_CUSTOM_SETUP
#define CONFIG_LED_MULTIPLE
//#define CONFIG_USES_POT
#define CONFIG_LED_CONNECT_PINS 9, 11, 3
#define CONFIG_POT_CONNECT_PIN A0

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

  // Sets LED's brightness
  int setBrightness(int brightnessLevel) {
    if (brightnessLevel > 255) { return 1; }
    analogWrite(port, brightnessLevel);
    return 0;
  };

  int setBrightnessWithDelay(int brightnessLevel, int timeout) {
    delay(timeout);
    setBrightness(brightnessLevel);
  }
  
  // Registers LEDs for output.
  void setup() { pinMode(port, OUTPUT); };

  // Returns port integer for manual tasks.
  int getPort() { return port; };

  int getBrightness() {
    return analogRead(port);
  };
};

class Pot {
private:
  int pin;
public:
  Pot::Pot(int _pin) { pin = _pin; }

  int getRotation() {
    return analogRead(pin);
  }
};

#ifdef CONFIG_LED_MULTIPLE
LedLight led[CONFIG_LED_QUANTITY] = NULL;
#else
LedLight led = NULL;
#endif

#ifdef CONFIG_USES_POT
Pot pot = NULL;
#endif
