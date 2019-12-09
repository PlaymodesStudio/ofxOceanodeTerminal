#include "ofxOceanodeTerminal.h"

//--------------------------------------------------------------
void ofxOceanodeTerminal::setup(){
    ofxNcurses::setup();
    //ofxNcurses::hideCursor();
    
    mMainWindow         = ofxNcurses::addWindow(0, 0, ofxNcurses::getWidth(), ofxNcurses::getHeight(), true, true);
    mMainWindow->box();
}

//--------------------------------------------------------------
void ofxOceanodeTerminal::update(){

}

//--------------------------------------------------------------
void ofxOceanodeTerminal::keyPressed(int key){
    auto moveCursor = [this](unsigned int pos){
        mCursorIndex = pos;
        mMainWindow->curMove(pos+1, 1);
    };
    
    if (key == 10) { // if key is return
        commandEvent.notify(currentInput);
        currentInput = "";
        moveCursor(0);
    }
    if (keyIsValid(key)){
        if (key == OF_KEY_BACKSPACE || key == OF_KEY_DEL){
            // delete character at cursor position //
            if (mCursorIndex > 0) {
                currentInput = (currentInput.substr(0, mCursorIndex - 1) + currentInput.substr(mCursorIndex));
                moveCursor(mCursorIndex - 1);
            }
        } else if (key == 260) {
            moveCursor(max( (int) mCursorIndex - 1, 0));
        } else if (key == 261) {
            moveCursor(min( mCursorIndex + 1, (unsigned int) currentInput.size()));
        } else if (key == 'v' && ofGetKeyPressed(OF_KEY_SUPER))  {
            currentInput = (ofGetWindowPtr()->getClipboardString());
            moveCursor(currentInput.size());
        } else {
            // insert character at cursor position //
            currentInput = (currentInput.substr(0, mCursorIndex) + (char)key + currentInput.substr(mCursorIndex));
            moveCursor(mCursorIndex+1);
        }
    }
    
    mMainWindow->erase();
    
    mMainWindow->box();
    mMainWindow->moveTo(1, 1);
    mMainWindow->attrOn(nc::Win::COLOR_1);
    mMainWindow->print(currentInput);
    mMainWindow->attrOff(nc::Win::COLOR_1);
    
    mMainWindow->refresh();
}

//--------------------------------------------------------------
void ofxOceanodeTerminal::keyReleased(int key){
    
}


bool ofxOceanodeTerminal::keyIsValid(int key){
    if (key == OF_KEY_BACKSPACE || key == OF_KEY_DEL || key == 260 || key == 261){
        return true;
    }
//    if (mType == ofxDatGuiInputType::NUMERIC){
//        // allow dash (-) or dot (.) //
//        if (key==45 || key==46){
//            return true;
//            // allow numbers 0-9 //
//        }   else if (key>=48 && key<=57){
//            return true;
//        }   else{
//            // an invalid key was entered //
//            return false;
//        }
//    }   else if (mType == ofxDatGuiInputType::ALPHA_NUMERIC){
        // limit range to printable characters http://www.ascii-code.com //
        if (key >= 32 && key <= 255) {
            return true;
        }   else {
            // an invalid key was entered //
            return false;
        }
//    }   else{
//        // invalid textfield type //
//        return false;
//    }
}
