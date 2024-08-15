# Materia: TSSE

## Trabajo Práctico N°3

Este repositorio muestra la implementación de la metodología de Test Driven Development en un ejemplo simple: El desarrollo de un contolador de 16 leds mapeados en memoria. El ejemplo es una adaptación a ceedling de ejemplo desarrollado en el libro Pragmatic Test Driven Development for Embedded C de James W. Genning

Por otro lado se configuró el repositorio con GitHub Actions para que se ejecuten automáticamente en cada pull-request las verificaciones de formato y las pruebas unitarias del código.

## Requerimientos

- Maneja 16 LEDs de dos estados (encendido y apagado).
- Al iniciar el procesador no hay estado conocido de los LEDs, estos deben ser apagados por software.
- Los LEDs estan mapeados en una palabra de 16 bits, en memoria, en una dirección a determinar.
- Para encender el led se debe escribir un “1” en el bit y para apagarlo se debe * escribir un “0”.
- El led 1 corresponde al bit menos significativo y el led 16 al bit mas significativo.
- Se puede cambiar el estado de un LED sin afectar a los otros.
- Se puede encender todos los LEDs en una sola operación.
- Se puede apagar todos los LEDs en una sola operación.
- Se puede recuperar el estado actual de un LED.
