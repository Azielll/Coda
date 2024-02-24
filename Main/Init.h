#ifndef Init_h
#define Init_h

#include "Arduino.h"

#include "Drive.h"
#include "Vision.h"
#include "Remote.h"
#include "Voice.h"

inline void init(Drivetrain drivetrain, Vision vision, Remote remote, Voice voice) {
  drivetrain.init();
  vision.init();
  remote.init();
  voice.init();

  
}


#endif
