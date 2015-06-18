#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
unsigned int newval=0;
unsigned int oldval=0;
unsigned int count=0;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    newval=results.value;
    count++;
    if (count==3)
    {
     oldval=newval;
     count=0;
    }
     irrecv.resume(); // Receive the next value
  }
   
  switch(oldval)
  {
    case 144: Serial.print("AT#MD");//Track up!
              Serial.print('\r');
              Serial.print('\n');
              break;
    case 2192:Serial.print("AT#ME");//Track DOWN!
              Serial.print('\r');
              Serial.print('\n');
              break;
    case 1168:Serial.print("AT#VU");//VOL up!
              Serial.print('\r');
              Serial.print('\n');
              break;
    case 3216: Serial.print("AT#VD");//VOL down!
              Serial.print('\r');
              Serial.print('\n');
              break;
    case 656: Serial.print("AT#MA");//Pause!
              Serial.print('\r');
              Serial.print('\n');
              break; 
    case 2704: Serial.print("AT#MC");//stop!
              Serial.print('\r');
              Serial.print('\n');
              break;               
    case 752: Serial.print("AT#MR");//FF
              Serial.print('\r');
              Serial.print('\n');
              delay(500);
              Serial.print("AT#MT");
              Serial.print('\r');
              Serial.print('\n');
              break;  
    case 2800:Serial.print("AT#MS");//FR!
              Serial.print('\r');
              Serial.print('\n');
              delay(500);
              Serial.print("AT#MT");//Forward 2 secs up!
              Serial.print('\r');
              Serial.print('\n');
              break;
   default: oldval=0;
            break;   
  }
  oldval=0;
}
