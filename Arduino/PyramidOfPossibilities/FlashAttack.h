//
//  FlashAttack.h
//
//  Created by Bill on 7/18/14.
//  Copyright (c) 2014 RN. All rights reserved.
//

#ifndef __FlashAttack__
#define __FlashAttack__

#include "RNAnimation.h"

struct FlashAttackParameters {
    uint8_t tapMultiplier = 2;
    uint8_t minimumValue = 20;
    uint16_t activityMultiplier = 400;


};

class FlashAttack : public RNAnimation {
public:
    FlashAttack(RNInfo & info, AnimationInfo animationInfo)
    : RNAnimation(info, animationInfo, sizeof(FlashAttackParameters), &parameters) {};
    
    virtual void paint(RNLights & lights);
    
    virtual const char * name();
    
    FlashAttackParameters parameters;

};

#endif /* defined(__FlashAttack__) */
