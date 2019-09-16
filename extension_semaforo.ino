#include <FastLED.h>

#define NUM_LEDS 5
#define LED_PIN 10
#define INPUT_RED 2
#define INPUT_YELLOW 3
#define INPUT_GREEN 4

CRGB leds[NUM_LEDS];

int estado = 0;
int estadoDeLaTira = -1;

void setup() {

    // Mode pins
    pinMode(INPUT_RED, INPUT);
    pinMode(INPUT_YELLOW, INPUT);
    pinMode(INPUT_GREEN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    // Setup LEDS WS2812
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    setColor(0, 0, 0);
    turnOn();
 //   Serial.begin(9600);
}

void loop() {
    // obtenemos el estado del semaforo exterior
    estado = obtenerEstadoSemaforo();
    if (estado != estadoDeLaTira) {
 //       Serial.println("Semaforo cambio de estado");
        // si el estado es distinto lo aplicamos a la tira
        ejecutarEstado();
        // guardamos el estado en el estadoDeLaTira
        estadoDeLaTira = estado;
    }
    //delay(10);
}

void ejecutarEstado() {
    Serial.println("Ejecutando estado actual");
    switch (estado)
    {
        case 1:
            turnOff();
            turnOnRed();
            break;
        case 2:
            turnOff();
            turnOnYellow();
            break;
        case 3:
            turnOff();
            turnOnGreen();
            break;
        default:
            turnOff();
            break;
    }
}

int obtenerEstadoSemaforo() {
//    Serial.println("Obteniendo estado...");

    if (digitalRead(INPUT_RED) == HIGH) {
        Serial.println("Semaforo rojo prendido");
        return 1; // Estado prender rojo
    }
    if (digitalRead(INPUT_YELLOW) == HIGH) {
        Serial.println("Semaforo amarillo prendido");
        return 2; // Estado prender amarillo
    }
    if (digitalRead(INPUT_GREEN) == HIGH) {
        Serial.println("Semaforo verde prendido");
        return 3; // Estado prender verde
    }
    Serial.println("Semaforo apagado");
    return 0; // Estado apagado
}

void turnOff() {
 //   Serial.println("Apagar tira");
    FastLED.setBrightness(0);
    FastLED.show();
}

void turnOnRed() {
//    Serial.println("Prender Rojo");
    setColor(255, 0, 0);
    turnOn();
}

void turnOnYellow() {
//    Serial.println("Prender Amarillo");
    setColor(255, 100, 0);
    turnOn();
}

void turnOnGreen() {
//    Serial.println("Prender Verde");
    setColor(0, 128, 0);
    turnOn();
}

void turnOn() {
    FastLED.setBrightness(255);
    FastLED.show();
}

void setColor(int r, int g, int b) {
    for(int i=0; i<NUM_LEDS; i++) {
        leds[i] = CRGB(r, g, b);
    } 
}