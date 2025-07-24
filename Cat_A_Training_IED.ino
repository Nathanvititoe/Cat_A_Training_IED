// Nathan Vititoe & Kevin Hodgson
const int LED_ARM = 2;

const int trigPin = 12;  
const int echoPin = 9;
const int LED_1 = 3;
const int LED_2= 4;

const int voltageMonitor = A0;
const int LEDvm = 5;

const int LDR=A4;
const int LEDldr=6;

const int breakWire = A2;
const int LEDbw = 7;

const int deadman = A3;
const int LEDdm = 8;

const int sw = A1;
const int LEDsw = 10;

const int mSwitch = A5;
const int LEDmS = 11;

float duration, distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(LED_1,OUTPUT);
  pinMode (LED_2,OUTPUT);

  pinMode(voltageMonitor,INPUT);
  pinMode(LEDvm,OUTPUT);

  pinMode(LDR,INPUT);
  pinMode(LEDldr,OUTPUT);

  pinMode(breakWire,INPUT);
  pinMode(LEDbw,OUTPUT);

  pinMode(deadman, INPUT);
  pinMode(LEDdm, OUTPUT);

  pinMode(sw, INPUT);
  pinMode(LEDsw, OUTPUT);

  pinMode(mSwitch, INPUT);
  pinMode(LEDmS, OUTPUT);

  pinMode(LED_ARM,OUTPUT);

digitalWrite (LED_ARM,HIGH);
delay(250);
digitalWrite (LED_ARM,LOW);
delay(250);
digitalWrite (LED_ARM,HIGH);
delay(250);
digitalWrite (LED_ARM,LOW);
delay(250);
digitalWrite (LED_ARM,HIGH);
delay(250);
digitalWrite (LED_ARM,LOW);
delay(250);
digitalWrite (LED_ARM,HIGH);
delay(250);
digitalWrite (LED_ARM,LOW);
delay(250);
digitalWrite (LED_ARM,HIGH);
delay(250);
digitalWrite (LED_ARM,LOW);
delay(250);
digitalWrite (LED_ARM,HIGH);

}

void loop()
{  
int LDRStatus = analogRead(LDR);
int monitorStatus = analogRead(voltageMonitor);
int breakWire_Status=analogRead(breakWire);
int deadman_Status = analogRead(deadman);
int sw_Status = analogRead(sw);
int mSwitch_Status = analogRead(mSwitch);


// Ultrasonic Sensor
 digitalWrite(trigPin, LOW);  
 delayMicroseconds(2);  
 digitalWrite(trigPin, HIGH);  
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*.0343)/2;

  if (distance<20 || distance>35) {
    digitalWrite (LED_1,HIGH);
  }
  else {
    digitalWrite (LED_1,LOW);
  }
  if (distance<20 || distance>35) {
    digitalWrite (LED_2,HIGH);
  }

// Organic Voltage Monitor
  if (monitorStatus>1000||monitorStatus<100){
    digitalWrite(LEDvm,HIGH);
  }
  else{
    digitalWrite(LEDvm,LOW);
  }

// LDR
  if (LDRStatus > 1200 || LDRStatus < 750) {
    digitalWrite(LEDldr,HIGH);
  }
  else {
    digitalWrite(LEDldr,LOW);
  }

// Break Wire
if (breakWire_Status<100) {
    digitalWrite(LEDbw,HIGH);
  }
  else{
    digitalWrite(LEDbw,LOW);
  }

// Deadman
if (deadman_Status < 100){
  digitalWrite(LEDdm, HIGH); 
}
else {
  digitalWrite(LEDdm, LOW);
}

// Microswitch
if (mSwitch_Status < 100){
  digitalWrite(LEDmS, HIGH); 
}
else {
  digitalWrite(LEDmS, LOW);
}

//Switch cap
if (sw_Status>100){
  digitalWrite(LEDsw, HIGH); 
}
else {
  digitalWrite(LEDsw, LOW);
}

Serial.print("Distance: ");  
Serial.println(distance); 
Serial.print("LDRStatus:");
Serial.println(LDRStatus); 
Serial.print("OVM Status:");
Serial.println(monitorStatus);
Serial.println(" ");
delay(250);  
}