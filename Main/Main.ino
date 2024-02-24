#include "Drive.h"
#include "Vision.h"
#include "Remote.h"
#include "FollowMe.h"
#include "Init.h"

Drivetrain drivetrain;
Vision vision;
Remote remote;
Voice voice;


void setup() {
  init(drivetrain, vision, remote, voice);
  //drivetrain.init();
}

void loop() {
  
  //drivetrain.differentialEquationPath();

}

