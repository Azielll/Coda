#ifndef Vision_h
#define Vision_h

class Vision {
    
    private:

    int servo = 26;
    int trigPin = 25;
    int echoPin = 24;
    

    long duration;
    int distance;
    

    public: 

    Vision();
    
    void init();
    
    void readDistance();
    void moveHead(int x);
    int getDistance();
    int getTrigPin();
    int getEchoPin();
};

#endif