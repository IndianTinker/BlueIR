void setup() 
{
 
  Serial.begin(115200);
}

void loop() {
if(!(digitalRead(PUSH2))) //If button Pressed
{
  while(!(digitalRead(PUSH2))) //Release the Kraken!!
  {
    delay(100);
  }
  if(digitalRead(PUSH2)) // Now Released .. Whoosh
  {
  Serial.print("AT#MD");//Track up!
  Serial.print('\r');
  Serial.print('\n');

  }
}
delay(2000); // Keep Going but slowly!
}
