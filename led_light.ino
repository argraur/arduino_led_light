#include "led_light.h"

#ifndef CONFIG_LED_CUSTOM_SETUP
void setup() {
#ifdef CONFIG_USES_POT
  pot = Pot(CONFIG_POT_CONNECT_PIN);
#endif
  int ports[CONFIG_LED_QUANTITY] = {CONFIG_LED_CONNECT_PINS};
  for (int i = 0; i < CONFIG_LED_QUANTITY; i++) {
    led[i] = LedLight(ports[i]);
  }
  for (int i = 0; i < CONFIG_LED_QUANTITY; i++) {
    led[i].setup();
  }
};
#else
void setup() {
#ifdef CONFIG_USES_POT
  Pot pot = Pot(CONFIG_POT_CONNECT_PIN);
#endif
  int port = CONFIG_LED_CONNECT_PINS;
  led = LedLight(port);
  led.setup();
}
#endif

// the loop function runs over and over again forever
void loop() {
  led[0].setBrightness(pot.getRotation() / 4);
  led[1].setBrightness(led[0].getBrightness() * 1.8);
  led[2].setBrightness(led[1].getBrightness() / 2);
}

/*
void breathing() {
  int brightnessMap[11] = {0, 25.5, 51, 76.5, 102, 127.5, 153, 178.5, 204, 229.5, 255};
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < 11; i++) {
      led[j].setBrightnessWithDelay(brightnessMap[i], 30);
    }
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 10; i >= 0; i--) {
      led[j].setBrightnessWithDelay(brightnessMap[i], 30);
    }
  }
}*/
