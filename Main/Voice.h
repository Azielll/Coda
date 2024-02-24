#ifndef Voice_h
#define Voice_h

class Voice{

    private:

        int speaker1 = 27;
        int speaker2 = 28;

        char text [50];

    public:

        Voice();

        void init();
        void test();
        void toneSound();

};

#endif