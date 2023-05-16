// Al inciarlizar la biblioteca todos los leds quedan apagados.
// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
// Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0 ---- HASTA ACÁ LLEGAMOS
// Prendo un led, consulto el estado y tiene que estar prendido.
// Apago un led, consulto el estado y tiene que estar apagado.
// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
// Con todos los leds prendidos, apago todos los leds y verifico que se apagan. ----- HASTA ACÁ es el práctico 1
// Revisar los valores limites de los argumentos.
// Revisar que pasa con valores erroneos en los argumentos.
#include <stdint.h>
#include "unity.h"
#include "leds.h"
static uint16_t puerto_virtual;
void setUp(void){
    ledsInit(&puerto_virtual);
}

// Al inciarlizar la biblioteca todos los leds quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;
    ledsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL_UINT16(0x0000, puerto_virtual);
}

// Con todos los leds apagados, prendo el led 2, verifico que se el bit 1 vale 1.
void test_prender_un_led(void){
    ledsTurnOnSingle(2);
    TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual); // Cada caso de prueba es independiente y arrance desde el inicio.
}

// Con el led 2 prendido, apago el led 2, verifico que se enciende el bit 1 vale 0.
void test_prender_y_apagar_un_led(void){
    ledsTurnOnSingle(9);
    ledsTurnOffSingle(9);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual); 
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberían quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void){
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual); 
}

// Prendo un led, consulto el estado y tiene que estar prendido.
void test_prender_un_led_consultar_prendido(void){
    bool led_encendido = false;
    ledsTurnOffSingle(6);
    ledsTurnOnSingle(6);
    led_encendido = ledsGetStateSingle(6);
    TEST_ASSERT_TRUE(led_encendido); 
}

// Apago un led, consulto el estado y tiene que estar apagado.
void test_apagar_un_led_consultar_apagado(void){
    bool led_encendido = true;
    ledsTurnOnSingle(4);
    ledsTurnOffSingle(4);
    led_encendido = ledsGetStateSingle(4);
    TEST_ASSERT_FALSE(led_encendido); 
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden.
void test_prender_todos_leds_consultar_prendidos(void){
    bool leds_encendidos = false;
    ledsTurnOffAll();
    ledsTurnOnAll();
    leds_encendidos = ledsGetStateAllOn();
    TEST_ASSERT_TRUE(leds_encendidos); 
}

// Con todos los leds prendidos, apago todos los leds y verifico que se apagan.
void test_apagar_todos_leds_consultar_apagados(void){
    bool leds_encendidos = true;
    ledsTurnOnAll();
    ledsTurnOffAll();
    leds_encendidos = ledsGetStateAllOff();
    TEST_ASSERT_TRUE(leds_encendidos); 
}
