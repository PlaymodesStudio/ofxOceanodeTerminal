#include "ofMain.h"
#include "ofApp.h"
#include "ofxOceanodeTerminal.h"
#include "ofAppCurses.h"

//========================================================================
int main( ){
    
    shared_ptr<ofAppCurses> terminalWindow = make_shared<ofAppCurses>();
    terminalWindow->setup(ofWindowSettings());
    shared_ptr<ofxOceanodeTerminal> terminalApp = ofxOceanodeTerminal::getInstance();
    
    ofRunApp(terminalWindow, terminalApp);
    
//    terminalApp->commandEvent.newListener([](string &s){
//        ofLog() << "fksjdlfk";
//    });
    
    
    ofGLFWWindowSettings settings;
    
    settings.setSize(600, 600);
    settings.setPosition(glm::vec2(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
    
    
//    ofSetupOpenGL(1024,768,OF_WINDOW);// <-------- setup the GL context
    
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
//    ofRunApp(new ofApp());
}
