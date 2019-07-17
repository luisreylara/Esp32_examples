

#include <Time.h>

TaskHandle_t Tarea1, Tarea2,Tarea3,Tarea4;


void codigoParaTarea1( void * parameter )
{
  for (;;) {
    long start = millis();
    Serial.print("Counter in Task 1: ");
    Serial.print(xPortGetCoreID());
    delay(1000);
    Serial.print(" Time ");
    Serial.println(millis() - start);
 
  }
}

void codigoParaTarea2( void * parameter )
{
  for (;;) {
    long start = millis();
    Serial.print("Counter in Task 2: ");
    Serial.print(xPortGetCoreID());
    delay(2000);
    Serial.print(" Time ");
    Serial.println(millis() - start);
  }
}


void codigoParaTarea3( void * parameter )
{
  for (;;) {
   long start = millis();
  Serial.print("Counter in Task 3: ");
  Serial.print(xPortGetCoreID());
  delay(3000);
  Serial.print(" Time ");
  Serial.println(millis() - start);
  }
}


void codigoParaTarea4( void * parameter )
{
  for (;;) {
    long start = millis();
    Serial.print("Counter in Task 4: ");
    Serial.print(xPortGetCoreID());
    delay(4000);
    Serial.print(" Time ");
    Serial.println(millis() - start);
  }
}

void setup() {
  Serial.begin(115200);

    xTaskCreatePinnedToCore(
    codigoParaTarea1,
    "led1Task",
    1000,
    NULL,
    1,
    &Tarea1,
    0);
  delay(500);  // needed to start-up task1

    xTaskCreatePinnedToCore(
    codigoParaTarea2,
    "led2Task",
    1000,
    NULL,
    4,
    &Tarea2,
    0);

    xTaskCreatePinnedToCore(
    codigoParaTarea3,
    "led3Task",
    1000,
    NULL,
    3,
    &Tarea3,
    1);

    xTaskCreatePinnedToCore(
    codigoParaTarea4,
    "led1Task",
    1000,
    NULL,
    2,
    &Tarea4,
    1);
  
}

void loop() {

  delay(10);
}


