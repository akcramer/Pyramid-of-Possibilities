//
//  RNAnimation.h
//  PlatformData
//
//  Created by Bill on 7/17/14.
//  Copyright (c) 2014 RN. All rights reserved.
//

#ifndef __RNAnimation__
#define __RNAnimation__


#include "RNLights.h"
#include "RNInfo.h"
#include "AnimationInfo.h"

class RNAnimation {
public:
    // Constructor
    RNAnimation(RNInfo & info, AnimationInfo animationInfo);
    RNAnimation(RNInfo & info, AnimationInfo animationInfo,  unsigned int parametersSize, void *parametersPointer);

    
    
    virtual ~RNAnimation() {};
    
    // Local reference to the info object
    RNInfo & info;
    
    // Gives the time in milliseconds since this animation starter
    uint32_t getAnimationMillis();

    // Gives the time in milliseconds since this animation starter
    float getAnimationMinutes();
    
    // Gives the cycles since this animation started.
    float getAnimationCycles();
    float getAnimationCyclesFraction();

    // Always returns 0 for a non-effect
    // Otherwise, returns 0..1
    float getEffectFraction();

    int8_t getTweakValue();
    uint8_t getUnsignedTweakValue();
    bool hasBeenTweaked();
    uint32_t timeSinceTweak();
    // name of the animation
    virtual const char * name();
    
    // Request that the animation set the lights appropriately.
    // For a base animation, the lights will be entirely black before the call
    virtual void paint(RNLights & lights);
    
    
    // Parameters
    


    // Called if there are any parameters from central
    // return true if successful
    virtual bool setParameters(int size, char * data);
    
    // set the address of the parameters struct (from your animation subclass)
     void  * const parametersPointer;
    
    // set the size of the parameters struct (from your animation subclass)
    const unsigned int parametersSize;
    
private:
    AnimationInfo animationInfo;
    
    // Start time of the animation in LOCAL time
    const int32_t animationStartMillis;
    
    uint32_t haveTweaksAsOf = 0;
    

    friend class RNController;
};


RNAnimation * getAnimation(RNInfo & info, AnimationInfo animationInfo );
RNAnimation * getAnimation(RNInfo & info, AnimationEnum e );

#endif /* defined(__RNAnimation__) */
