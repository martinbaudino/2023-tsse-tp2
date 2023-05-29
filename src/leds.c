#include "leds.h"
#include <stdio.h>

static uint16_t *puerto_virtual;

#define INDEX_OFFSET 1
#define INDEX_MAX 8
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0X0000
#define ALL_LEDS_ON 0XFFFF


static bool ledsCheckValidLed(int led){
    return (led < INDEX_OFFSET || led > INDEX_MAX)? false : true;
}

// Utilizo una funcion que el compilador la va a expandir porque es muy corta. Tb podría ser inline
static uint16_t indexToMask(uint8_t led){
    if (ledsCheckValidLed(led)) {
        return (FIRST_BIT << (led-INDEX_OFFSET));
    } else {
        printf("Error en rango del led: %d\n", led);
    }        
}

void ledsInit(uint16_t * direccion){
    puerto_virtual = direccion;
    *direccion = ALL_LEDS_OFF;
}

void ledsTurnOnSingle(int led) {
    if (ledsCheckValidLed(led)) {
        *puerto_virtual |= indexToMask(led);
    } else {
        printf("Error en rango del led: %d\n", led);
    }    
}

void ledsTurnOffSingle(int led) {
    if (ledsCheckValidLed(led)) {
        *puerto_virtual &= ~indexToMask(led);    
    } else {
        printf("Error en rango del led: %d\n", led);
    }    
}

void ledsTurnOnAll(void) {
    *puerto_virtual = ALL_LEDS_ON;
}

void ledsTurnOffAll(void) {
    *puerto_virtual = ALL_LEDS_OFF;
}

bool ledsGetStateSingle(int led) {
    if (ledsCheckValidLed(led)) {
        return (indexToMask(led) & *puerto_virtual);
    } else {
        printf("Error en rango del led: %d\n", led);
    }        
}

bool ledsGetStateAllOn(void){
    return (*puerto_virtual == ALL_LEDS_ON);
}

bool ledsGetStateAllOff(void){
    return (*puerto_virtual == ALL_LEDS_OFF);
}
