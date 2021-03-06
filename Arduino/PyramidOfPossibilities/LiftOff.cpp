//
//  LiftOff.cpp
//  PlatformCode
//
//  Created by Bill on 8/16/14.
//  Copyright (c) 2014 RN. All rights reserved.
//

#include "LiftOff.h"
#include "Constants.h"
#include <math.h>


void LiftOff::paint(RNLights & lights) {
    
    float c = getAnimationCycles() * parameters.speed;
    float cycle = c - floor(c);
    
    lights.setAllPixelColors(parameters.backgroundGradient.getColor(info.y * 255 / constants.pyramidHeight));
    paintWave(lights, cycle*parameters.overlap);
    paintWave(lights, (cycle+1.0)*parameters.overlap);
    lights.setBrightness(parameters.brightness);
    
    info.showActivityWithSparkles(lights);
}

bool LiftOff::paintWave(RNLights & lights, float height) {
    if (0 <= height && height < 1) {
        AHEasingFunction easingFunction = getEasingFunction(parameters.easingMode, parameters.curveType);
        height = easingFunction(height);
    }
    
    float topHeight = height * constants.pyramidHeight;
    float bottomHeight = (height - parameters.thickness) * constants.pyramidHeight;
    
    float gradientPosition = (info.z - bottomHeight)/(topHeight - bottomHeight);
    
    if (0.0 <= gradientPosition && gradientPosition < 1) {
        
        uint32_t color = parameters.gradient.getColor(256*gradientPosition);
        lights.setAllPixelColorsMax(color);
        return true;
    } else
        return false;
}



const char * LiftOff::name() {
    return "LiftOff";
}
