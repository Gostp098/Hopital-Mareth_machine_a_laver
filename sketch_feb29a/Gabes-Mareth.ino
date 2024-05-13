const int startButtonPin = A2; //button start


const int motorForwardPin = 0; // motor a gauche
const int motorBackwardPin = 1; //motor a droit
const int waterPumpPin = 2;  // water pump
const int waterOutPumpPin = 3; //vidange
const int spinningPin = 4; //esorage
const int DoorContactPin = 5; //contact de porte
const int WaterHeater = 6;

const int prewashingLED = 12; 
const int washingLED = 11; 
const int rinsingLED = 10; 
const int drainingLED = 9; 
const int spinningLED = 8; 


int startButtonState = 0;

void setup() {
 pinMode(motorForwardPin, OUTPUT);
  pinMode(motorBackwardPin, OUTPUT);
  pinMode(waterPumpPin, OUTPUT);
  pinMode(waterOutPumpPin, OUTPUT);
  pinMode(spinningPin, OUTPUT);
  pinMode(DoorContactPin, OUTPUT);
  pinMode(WaterHeater, OUTPUT);



  pinMode(prewashingLED, OUTPUT);
  pinMode(washingLED, OUTPUT);
  pinMode(rinsingLED, OUTPUT);
  pinMode(drainingLED, OUTPUT);
  pinMode(spinningLED, OUTPUT);



  digitalWrite(motorForwardPin, 1);
  digitalWrite(motorBackwardPin, 1);
  digitalWrite(waterPumpPin, 1);
  digitalWrite(waterOutPumpPin, 1);
  digitalWrite(DoorContactPin, 1);
  digitalWrite(spinningPin, 1);
 digitalWrite(WaterHeater, 1);



  pinMode(startButtonPin, INPUT);

}

void loop() {

int startButtonState = 0;
startButtonState = digitalRead(startButtonPin);

if (startButtonState == 1) {

 
      digitalWrite(DoorContactPin, 0);
        digitalWrite(motorBackwardPin, 0);

  preWashing();
  Draining();
  Washing();
  Draining();

    Rinsing();
    Draining();

    Rinsing();
    Draining(); 

    Spinning();
          


 }
 return;
}


//prelave
void preWashing() {
 digitalWrite(prewashingLED, 1); // prelave LED ON
   

   digitalWrite(waterPumpPin, 0); 

   digitalWrite(waterOutPumpPin, 0);

 const int cycleCount = 10; // Number of washing cycles

  for (int cycle = 0; cycle < cycleCount; cycle++) {
    // Forward
    digitalWrite(motorForwardPin, 0);
    delay(30000);  // 30s in milliseconds
    digitalWrite(motorForwardPin, 1);
 //   delay(2000);

    // Backward
   // digitalWrite(motorBackwardPin, 0);
    delay(30000);  // 30s in milliseconds
//    digitalWrite(motorBackwardPin, 1);
 //   delay(2000);



  }
    digitalWrite(waterPumpPin, 0); 
    delay(2000); // A3ML DELAY BIN PRELAV O VIDABGE     

      digitalWrite(waterOutPumpPin, 1);
digitalWrite(prewashingLED, 0);


}




//lavage
void Washing() {
   
 digitalWrite(washingLED, 1); // lave LED ON
   digitalWrite(WaterHeater, 0); 
   digitalWrite(waterPumpPin, 0); 

   digitalWrite(waterOutPumpPin, 0);

 const int cycleCount = 15; // Number of washing cycles

  for (int cycle = 0; cycle < cycleCount; cycle++) {
    // Forward
    digitalWrite(motorForwardPin, 0);
    delay(30000);  // 30s in milliseconds
    digitalWrite(motorForwardPin, 1);
  //  delay(2000);

    // Backward
 //   digitalWrite(motorBackwardPin, 0);
    delay(30000);  // 30s in milliseconds
   // digitalWrite(motorBackwardPin, 1);
 //   delay(2000);
  }
    digitalWrite(waterPumpPin, 0); 
    delay(2000); // A3ML DELAY BIN PRELAV O VIDABGE     

      digitalWrite(waterOutPumpPin, 1);
      digitalWrite(WaterHeater, 1);


    digitalWrite(washingLED, 0);


}


//Vidange
void Draining() {
digitalWrite(drainingLED, HIGH);
digitalWrite(waterOutPumpPin, 1);

 const int cycleCount = 1; // Number of washing cycles

  for (int cycle = 0; cycle < cycleCount; cycle++) {
    // Forward
    digitalWrite(motorForwardPin, 0);
    delay(30000);  // 30s in milliseconds
    digitalWrite(motorForwardPin, 1);
  //  delay(2000);

    // Backward
    //digitalWrite(motorBackwardPin, 0);
    delay(30000);  // 30s in milliseconds
  //  digitalWrite(motorBackwardPin, 1);
  //  delay(2000);


  }
      digitalWrite(waterOutPumpPin, 0);
  delay(2000);

digitalWrite(drainingLED, LOW);
}


//rinsage
void Rinsing() {
 digitalWrite(rinsingLED, HIGH);
  digitalWrite(waterPumpPin, 0); 
     digitalWrite(waterOutPumpPin, 0);


  const int cycleCount = 4; // Number of cycles each cycle is 1 min

  for (int cycle = 0; cycle < cycleCount; cycle++) {
    // Forward
    digitalWrite(motorForwardPin, 0);
    delay(30000);  // 30s in milliseconds
    digitalWrite(motorForwardPin, 1);
 //   delay(2000);

    // Backward
 //   digitalWrite(motorBackwardPin, 0);
    delay(30000);  // 30s in milliseconds
  //  digitalWrite(motorBackwardPin, 1);
   // delay(2000);
  }

     
     digitalWrite(waterOutPumpPin, 1);

      digitalWrite(waterPumpPin, 1); 
delay(2000);

digitalWrite( drainingLED, LOW);
}


//esorage
void Spinning() {
  digitalWrite(spinningLED, HIGH);
 digitalWrite(spinningPin, LOW);
     digitalWrite(waterOutPumpPin, 1);
     
      digitalWrite(spinningPin, 0);
     // digitalWrite(motorForwardPin, 0);

                delay(600000);// 7 min
     // digitalWrite(motorForwardPin, 1);
      digitalWrite(spinningPin, 1);  
      
    digitalWrite(motorBackwardPin, 1);

    digitalWrite(waterOutPumpPin, 0);

 delay(60000); // 1min

  digitalWrite(spinningLED, LOW);

  digitalWrite(DoorContactPin, 1);

}