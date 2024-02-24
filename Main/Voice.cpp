
#include "Arduino.h"
#include "Voice.h"

#include <TTS.h>


int speaker1 = 10;

TTS textToSpeech(speaker1);


Voice::Voice() {
  init();
}

void Voice::init() {

  pinMode(speaker2, OUTPUT);

}

void Voice::test() {

  textToSpeech.setPitch(6);
  strcpy(text, "Hi");
  textToSpeech.sayText(text);

  delay(1000);

}

void Voice::toneSound() {
  tone(speaker1, 3000, 500);
  tone(speaker1, 4000, 500);
  tone(speaker1, 2000, 500);
  tone(speaker1, 1000, 500);
  tone(speaker1, 2000, 500);

}
