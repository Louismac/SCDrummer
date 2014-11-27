
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
bool notExpecting=true;
bool expectingDrumPin=false,expectingDrumOnOff=false;
int drumPin;


void setup()
{

  Serial.begin(115200);

  
  for(int i=0;i<50;i++) {
    pinMode(i, OUTPUT); 
  }  
  inputString.reserve(200);

  delay(1000);

}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (stringComplete) {
    stringComplete=false;
    if(inputString=="solenoid") {
      expectingDrumPin=true;
      notExpecting=false;
    } else if(expectingDrumPin) {
      drumPin=(int)inputString.toInt();
      expectingDrumPin=false;
      expectingDrumOnOff=true;
    } else if(expectingDrumOnOff) {
      expectingDrumOnOff=false;
      notExpecting=true;
      if(inputString=="HIGH") { 
        digitalWrite(drumPin,HIGH);
        Serial.println(drumPin);
        digitalWrite(13,HIGH);
      } else if (inputString=="LOW") {
        digitalWrite(drumPin,LOW);
      }
    } 
    inputString="";
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
     // add it to the inputString:
      inputString += inChar;
    }
  }
}

void flash() {
   digitalWrite(13, HIGH);   // set the LED on
   delay(500);              // wait for a second
   digitalWrite(13, LOW);    // set the LED off
   delay(500);  
}


