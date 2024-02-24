#ifndef Drive_h
#define Drive_h


class Drivetrain {
  private:

    int carspeed = 150;

    int rightENB = 2;
    int rightBackMotorPin1 = 3;
    int rightBackMotorPin2 = 4;
    int rightFrontMotorPin1 = 5;
    int rightFrontMotorPin2 = 6;
    int rightENA = 7;
        
    //Left Wheels
    int leftENA = 8;
    int leftBackMotorPin1 = 9;
    int leftBackMotorPin2 = 10;
    int leftFrontMotorPin1 = 11;
    int leftFrontMotorPin2 = 12;
    int leftENB = 13;

    int vl = 150;
    int vr = 255;

    #define PI 3.1415926535897932384626433832795

    const float rpm = 210;                 // In rev/min
    const float w = 3.5 * PI;              // In rad/sec
    const float wheelRaduis = 0.0315;     // In meters
    const float alpha = 0;     
    const float theta = 2 * PI;           
    float time;

  public:
    Drivetrain();
    void init();
    void forward(int carspeed, int time = 1);
    void back(int carspeed, int time = 1);
    void left(int carspeed, int time = 1);
    void right(int carspeed, int time = 1);
    void stop(int time = 1);
    void circlePath(int Vl, int Vr);
    void differentialEquationPath();
    int v1Calculator(int vcm);
};

#endif
