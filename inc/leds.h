#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

void ledsInit(uint16_t * direccion);

void ledsTurnOnSingle(int led); // Int cuando no defino el rango
void ledsTurnOffSingle(int led);
void ledsTurnOnAll(void);
void ledsTurnOffAll(void);

bool ledsGetStateSingle(int led);
bool ledsGetStateAllOn(void);
bool ledsGetStateAllOff(void);

bool ledsCheckValidLed(int led);

#endif