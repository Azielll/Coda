#ifndef Remote_h
#define Remote_h


class Remote {

    private: 

    int reciever = 27;

    int powerButton;
    int button1;
    int button2;


    public: 

    Remote();
    void init();
    void readButtonCodes();
    void start();
    int getRecieverPin();
};

#endif