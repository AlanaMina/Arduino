// Chaleco para ciclistas con funciones ociosa, stop, giros derecha e izquierda
//VARIABLES
int bot[] = {1,2,3};
int led[] = {4,5,6,7,8,9,10,11,12,13};
int numLeds = 10;
int numBots = 3;
int tiempoRet = 400;
int tiempoRetOciosa = 200;
int estePin;
int cuenta_der = 0;
int cuenta_alto = 0;
int cuenta_izq = 0;
int cuenta_ocio = 0;
boolean bot_derecha = LOW;
boolean bot_alto = LOW;
boolean bot_izquierda = LOW;

//SETUP
void setup (){
  	for (estePin = 0; estePin < numBots; estePin++){
		pinMode (bot[estePin],INPUT);
	}
	for (estePin = 0; estePin < numLeds; estePin++){
		pinMode (led[estePin],OUTPUT);
	}
}

//LOOP
void loop() {
  	for (estePin = 0; estePin < numLeds; estePin++){
		digitalWrite (led[estePin], LOW);
	}
	bot_derecha = digitalRead (bot[0]);
	bot_alto = digitalRead (bot[1]);
	bot_izquierda = digitalRead (bot[2]);
	if (bot_derecha==HIGH){
		derecha ();
	}
	else if (bot_alto==HIGH){
		stop ();
	}
	else if (bot_izquierda==HIGH){
		izquierda ();
	}
	else{
		ociosa ();
	}
}

//FUNCIÓN OCIOSA
void ociosa () {
	digitalWrite (led[cuenta_ocio],HIGH);
	digitalWrite (led[cuenta_ocio+4],HIGH);
	delay (tiempoRetOciosa);
	digitalWrite (led[cuenta_ocio],LOW);
	digitalWrite (led[cuenta_ocio+4],LOW);
	cuenta_ocio++;
	if (cuenta_ocio > 3){
		cuenta_ocio = 0;
	}
}

//FUNCIÓN ALTO
void stop (){
  for (estePin=0; estePin < numLeds; estePin++) {  
  	digitalWrite(led[estePin], HIGH);
  }
  delay(tiempoRet);
  	
  for (estePin=0; estePin < numLeds; estePin++) {  
  	digitalWrite(led[estePin], LOW);
  }
  delay(tiempoRet);
}

//FUNCIÓN GIRO A LA DERECHA
void derecha (){
    switch (cuenta_der){
      case 0:
        digitalWrite (led[0],HIGH);
        digitalWrite (led[8],HIGH);
        digitalWrite (led[6],HIGH);
        break;
      case 1:
        digitalWrite (led[1],HIGH);
        digitalWrite (led[9],HIGH);
        digitalWrite (led[5],HIGH);
        break;
      case 2:
        digitalWrite (led[2],HIGH);
        digitalWrite (led[3],HIGH);
        digitalWrite (led[4],HIGH);
        break;
      default:
      	;
     }
     delay (tiempoRet);
     cuenta_der++;
     if (cuenta_der > 3){
     	cuenta_der = 0;
     }
     
  	for (estePin=0; estePin < numLeds; estePin++) {  
  		digitalWrite(led[estePin], LOW);
  	}
}

//FUNCIÓN GIRO A LA IZQUIERDA
void izquierda (){
    switch (cuenta_izq){
      case 0:
        digitalWrite (led[2],HIGH);
        digitalWrite (led[9],HIGH);
        digitalWrite (led[4],HIGH);
        break;
      case 1:
        digitalWrite (led[1],HIGH);
        digitalWrite (led[8],HIGH);
        digitalWrite (led[5],HIGH);
        break;
      case 2:
        digitalWrite (led[0],HIGH);
        digitalWrite (led[7],HIGH);
        digitalWrite (led[6],HIGH);
        break;
      default:
      	;
     }
     delay (tiempoRet);
     cuenta_izq++;
     if (cuenta_izq > 3){
     	cuenta_izq = 0;
     }
     
  	for (estePin=0; estePin < numLeds; estePin++) {  
  		digitalWrite(led[estePin], LOW);
  	}
}