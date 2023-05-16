#include "leds.h"

static uint16_t *puerto_virtual;
#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0X0000
#define ALL_LEDS_ON 0XFFFF

// Utilizo una funcion que el compilaror la va a expandir porque es muy corta. Tb podría ser inline

uint16_t indexToMask(uint8_t led){
    return (FIRST_BIT << (led-INDEX_OFFSET));
}

void ledsInit(uint16_t * direccion){
    puerto_virtual = direccion;
    *direccion = ALL_LEDS_OFF;
}

void ledsTurnOnSingle(int led) {
    *puerto_virtual |= indexToMask(led);    
}

void ledsTurnOffSingle(int led) {
    *puerto_virtual &= ~indexToMask(led);    
}

void ledsTurnOnAll(void) {
    *puerto_virtual = ALL_LEDS_ON;
}

void ledsTurnOffAll(void) {
    *puerto_virtual = ALL_LEDS_OFF;
}

bool ledsGetStateSingle(int led) {
    return (indexToMask(led) & *puerto_virtual);
}

bool ledsGetStateAllOn(void){
    return (*puerto_virtual == ALL_LEDS_ON);
}

bool ledsGetStateAllOff(void){
    return (*puerto_virtual == ALL_LEDS_OFF);
}