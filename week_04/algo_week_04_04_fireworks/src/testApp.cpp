#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    //ofBackground( 100 );
    
    ofBackground(0);
    //ofEnableBlendMode (OF_BLENDMODE_ADD);
    //CGDisplayHideCursor(0);
    ofSetBackgroundAuto(false);
    ofEnableSmoothing();
    ofHideCursor();
    ofEnableAlphaBlending();
    ofSetLineWidth(2);
    
    for (int i =0; i < 4; i++){
    fireworks.push_back(Firework());
        
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    float sorting = ofRandom(20);
    
    if (fireworks.size() < 2 && sorting < 1) {
        
    fireworks.push_back(Firework());

    }
    
    
    for( vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = fireworks.erase(it);
        
        }else {
            it++;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofHideCursor();
    
    //ofSaveFrame();
    
    ofSetColor(0, 0, 0, 30);
    ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    for( vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); ){
        it->draw();
        it++;
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
