#pragma once

#include "ofMain.h"
#include "ofxNcurses.h"

class ofxOceanodeTerminal: public ofBaseApp {
public:
    
    static shared_ptr<ofxOceanodeTerminal> getInstance()
    {
        static shared_ptr<ofxOceanodeTerminal> instance(new ofxOceanodeTerminal);
        return instance;
    }
    
    void setup();
    void update();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofEvent<string> commandEvent;
private:
    shared_ptr<nc::Win> mMainWindow;
    
    bool keyIsValid(int key);
    
    string currentInput;
    unsigned int mCursorIndex;
};

