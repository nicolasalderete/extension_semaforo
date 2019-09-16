int rojo = 12;
int amarillo = 11;
int verde = 10;


void setup(){
    pinMode(rojo, OUTPUT);
    pinMode(amarillo, OUTPUT);
    pinMode(verde, OUTPUT);

  // Inicializo estado:  apago rojo y amarillo, enciendo verde
    digitalWrite(amarillo, LOW);
    digitalWrite(rojo, LOW);
    digitalWrite(verde, HIGH);
}


void loop() {

  // Verde
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, LOW);
    delay(2000);


  // Apago verde, enciendo amarillo por 3 segundos
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, HIGH);
    delay(2000);

    // Apago amarillo, enciendo rojo por 5 segundos
    digitalWrite(verde, LOW);
    digitalWrite(amarillo, LOW);
    digitalWrite(rojo, HIGH);
    delay(2000);
    
    digitalWrite(verde, LOW);
    digitalWrite(rojo, LOW);
    digitalWrite(amarillo, HIGH);
    delay(2000);
    
    // apago rojo y amarillo, enciendo verde



}