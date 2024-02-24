#ifndef FollowMe_h
#define FollowMe_h

#include "Arduino.h"

#include "Remote.h"
#include "Vision.h"
#include "Drive.h"
#include "Voice.h"



inline void followMeMode(Drivetrain drivetrain, Vision vision, Remote remote, Voice voice)  {
  
  vision.readDistance();

  int direction = 90;

  vision.moveHead(direction);

  bool clockwise = true;

  while (vision.getDistance() > 20) {

    if (direction <= 20) {
      clockwise = false;
    }

    if (direction >= 150) {
      clockwise = true;
    }

    if (clockwise) {
      direction++;
    }

    else {
      direction--;
    }

    vision.moveHead(direction);
    delay(25);
  }

//  findObstacle(direction);

  do
  {
    if (vision.getDistance() < 20 && vision.getDistance() > 10) {
      int carspeed = map(vision.getDistance(), 10, 20, 0, 255);
      drivetrain.forward(carspeed);
    }
    else if (vision.getDistance() < 10 && vision.getDistance() > 5) {
      //drivetrain.stop();
    }
    else if (vision.getDistance() < 5 && vision.getDistance() > 0) {
      int carspeed = map(vision.getDistance(), 0, 5, 0, 255);
      drivetrain.back(carspeed);
    }
  } while (vision.getDistance() < 20);

}



inline void findObstacle(int angle) {
  
}





#endif
