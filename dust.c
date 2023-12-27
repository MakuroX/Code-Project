int measurePin = A0;
int ledPower = A5;    //Pin LED
int Relay1 = 1; //pin relay

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);

}

void loop() {
  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); e

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); 
  delayMicroseconds(sleepTime);


  calcVoltage = voMeasured * (3.3 / 1024);

 
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(voMeasured);

  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
    if (dustDensity <= 0.00) {
    dustDensity = 0.00;
  }


  dustDensity = dustDensity * 1000;
  

  if (dustDensity < 47) {
    digitalWrite(Relay1, HIGH);
    delay(100);
    
  }
    if (dustDensity > 47) {
    digitalWrite(Relay1, LOW);
    delay(100);
   
  }




  Serial.print(" - Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" µg/m³");
    delay(1000);
 
}