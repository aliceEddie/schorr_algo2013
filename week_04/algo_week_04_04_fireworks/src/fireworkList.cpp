//
//  fireworkList.cpp
//  algo_week_04_04_fireworks
//
//  Created by Bernardo Santos Schorr on 9/23/13.
//
//

#include "fireworkList.h"

Firework::Firework() {
    
    accel = ofVec2f (0, 0.1);
    exploded = false;
    dieCount = 255;
    
    posX = ofRandom(ofGetWindowWidth()/2 - 50, ofGetWindowWidth()/2 + 50);
    
    vel.x = ofRandom(-1.0, 1.0);
    vel.y = ofRandom(-9.0, -11.0);
    
    for( int i=0; i<100; i++){
        Mover myMover = Mover (posX, vel, accel);
        moverList.push_back( myMover );
    }
    
    bIsDead = false;
    
    
}

void Firework::update() {
    
    if (!exploded) {
        
    vel += accel;
    
    }
    
    
    for( vector<Mover>::iterator it=moverList.begin(); it!=moverList.end(); ){
        it->update();
        
        
        if (vel.y >= 0 && !exploded) {
        
        it->explode();
            
        }
        
        it++;


    }
    
    if (vel.y >= 0 && !exploded) {
        
        exploded = true;
        
    }
    
    if (exploded && dieCount > 0) {
        
        dieCount -= 4;
        
    }
    
    if (dieCount < 0) {
        
        bIsDead = true;
        
    }
    

}

void Firework::draw() {
    
    
    ofSetColor(255, dieCount);
    
    
    for( vector<Mover>::iterator it=moverList.begin(); it!=moverList.end(); ){
        it->draw();
        it++;
        
    }


}