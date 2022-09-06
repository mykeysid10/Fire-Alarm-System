float temp;
float vout;
float vout1;
int LED = 13;
int gasSensor = 7;
int piezo = 7;

void setup(){
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  /*** 
  1. Sensor value from analog to voltage. (divide by 1023)
  2. Convert Arduino 5V to mV. (multiply by 5000)
  3. Arduino supplies 5V, so to convert to mV 
  4. Subtract with 500 to remove the offset value.
  5. Since the TM36 reads value from -50 degree to 125. 
  6. After the temperature range will be 0 - 175 degrees. 
  7. It is in millivolts, we divide it by 10 to convert it into a degree.
  ***/
  
  vout = analogRead(A1);
  
  vout1 = (vout/1023)*5000; 
  temp = (vout1-500)/10;
  
  gasSensor = analogRead(A0);

  if(temp>=80)
  	digitalWrite(LED, HIGH);
  else
  	digitalWrite(LED, LOW);
  
  if(gasSensor>=100)
  	digitalWrite(piezo, HIGH);
  else
  	digitalWrite(piezo, LOW);
  
  Serial.print("In Degree Celcius: ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("GasSensor: ");
  Serial.print(" ");
  Serial.print(gasSensor);
  Serial.println();
  delay(1000);
} 