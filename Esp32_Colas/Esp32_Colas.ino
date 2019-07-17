#define TAM_COLA 20 /*20 mensajes*/
#define TAM_MSG 7 /*Cada Mensaje 7 caracteres*/


TaskHandle_t Tarea1, Tarea2,Tarea3,Tarea4;
QueueHandle_t cola_Mensaje;


void escribe1( void * parameter )
{
  char cadena[7];
  for (;;) {
      strcpy (cadena, "Tarea1");
      xQueueSend(cola_Mensaje, &cadena,2000); //2seg--> Tiempo max. que la tarea está bloqueada si la cola está llena
      delay(2000);
  }
}


void escribe2( void * parameter )
{
  char cadena[7];
  for (;;) {
    strcpy (cadena, "Tarea2");
       xQueueSend(cola_Mensaje, &cadena,2000);
         delay(2000);
    }
}


void escribe3( void * parameter )
{
  char cadena[7];
  for (;;) {
    strcpy (cadena, "Tarea3");
    xQueueSendToBack(cola_Mensaje, &cadena,2000);
    delay(2000);
  }
}

void lee1( void * parameter )
{

  int i;
  char Rx[7];
  for (;;) {
   xQueueReceive(cola_Mensaje,&Rx,10000); //10s --> Tiempo max. que la tarea está bloqueada si la cola está vacía

         for(i=0; i<strlen(Rx); i++)
           {
             Serial.print(Rx[i]);
           }     
           Serial.println(".");
  }
}



void setup() {
  Serial.begin(115200);
  cola_Mensaje = xQueueCreate( TAM_COLA, TAM_MSG );
  if(cola_Mensaje == NULL){
    Serial.println("Error creating the queue");
  }

    xTaskCreatePinnedToCore(
    escribe1,
    "led1Task",
    1024,
    NULL,
    1,
    &Tarea1,
    0);
  delay(500);  // needed to start-up task1

    xTaskCreatePinnedToCore(
    escribe2,
    "led2Task",
    1024,
    NULL,
    1,
    &Tarea2,
    0);

    xTaskCreatePinnedToCore(
    escribe3,
    "led3Task",
    1024,
    NULL,
    1,
    &Tarea3,
    1);

    xTaskCreatePinnedToCore(
    lee1,
    "led1Task",
    1024,
    NULL,
    5,
    &Tarea4,
    1);
  
}
void loop() {



  delay(10);
}







