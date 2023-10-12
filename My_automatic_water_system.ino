
int inRelay = 40;

int sensorAout = A0;

float sensor1Value;

int delayT1 = 500;
int delayT2 = 5000;


void setup() {
 Serial.begin(9600);
 
 pinMode(inRelay, OUTPUT);
 pinMode(sensorAout, INPUT);


 digitalWrite(inRelay, HIGH);
 delay(delayT1);
 
 // min 211.0
 // max 520.0
 // With a few drops 422.0, 423.0
 
}

void loop() {

   Serial.print("The soil moisture is ");
   sensor1Value = analogRead(sensorAout);
   Serial.println(sensor1Value);
   
   if(sensor1Value > 274){
    digitalWrite(inRelay, LOW);
    Serial.println("The soil is dry.");  
    delay(6000);
  } else {
    digitalWrite(inRelay, HIGH);
    Serial.println("The soil is not dry.");
  }

  delay(delayT2);
  
}
