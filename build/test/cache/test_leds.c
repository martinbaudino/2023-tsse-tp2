#include "inc/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
static uint16_t puerto_virtual;

void setUp(void){

    ledsInit(&puerto_virtual);

}





void test_todos_los_leds_inician_apagados(void) {

    uint16_t puerto_virtual = 0xFFFF;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0x0000)), (UNITY_INT)(UNITY_UINT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_UINT16);

}





void test_prender_un_led(void){

    ledsTurnOnSingle(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_un_led(void){

    ledsTurnOnSingle(9);

    ledsTurnOffSingle(9);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void){

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);

    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led_consultar_prendido(void){

    

   _Bool 

        led_encendido = 

                        0

                             ;

    ledsTurnOffSingle(6);

    ledsTurnOnSingle(6);

    led_encendido = ledsGetStateSingle(6);

    do {if ((led_encendido)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(54)));}} while(0);

}





void test_apagar_un_led_consultar_apagado(void){

    

   _Bool 

        led_encendido = 

                        1

                            ;

    ledsTurnOnSingle(4);

    ledsTurnOffSingle(4);

    led_encendido = ledsGetStateSingle(4);

    do {if (!(led_encendido)) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(63)));}} while(0);

}





void test_prender_todos_leds_consultar_prendidos(void){

    

   _Bool 

        leds_encendidos = 

                          0

                               ;

    ledsTurnOffAll();

    ledsTurnOnAll();

    leds_encendidos = ledsGetStateAllOn();

    do {if ((leds_encendidos)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);

}





void test_apagar_todos_leds_consultar_apagados(void){

    

   _Bool 

        leds_encendidos = 

                          1

                              ;

    ledsTurnOnAll();

    ledsTurnOffAll();

    leds_encendidos = ledsGetStateAllOff();

    do {if ((leds_encendidos)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(81)));}} while(0);

}
