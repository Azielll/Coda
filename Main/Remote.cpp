
#include "Arduino.h"
#include "Remote.h"

#include <IRremote.h>

int receiver = 27;

//IRrecv irrecv(receiver);
//decode_results results;


Remote::Remote() {
  init();
}

void Remote::init() {
  pinMode(reciever, INPUT);
  Serial.begin(115200); 
  //irrecv.enableIRIn();
  IrReceiver.begin(receiver);
}

void Remote::readButtonCodes() {
  if (IrReceiver.decode()) {                     // Returns 0 if no data ready, 1 if data ready.  
    int buttonCode = IrReceiver.decodedIRData.command;                      // Results of decoding are stored in result.value 
    Serial.print("Code: "); 
    Serial.println(buttonCode);                    //prints the value a a button press 
    Serial.println(" "); 
    IrReceiver.resume();                                  // Restart the ISR state machine and Receive the next value 
  }
}

//void Remote::start() {
//  if (irrecv.decode(&results)) {
//    int buttonCode = results.value;
//    if (buttonCode = powerButton) {                
//    }
//  }
//}

int Remote::getRecieverPin() {
    return reciever;
}
