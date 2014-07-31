//
//  WWPAnimation2.cpp
//  PlatformData
//
//  Created by Bill on 7/18/14.
//  Copyright (c) 2014 RN. All rights reserved.
//

#include "WWPAnimation2.h"


void WWPAnimation2::paint(RNLights & lights) {

  uint8_t baseHue = (getAnimationMillis() / 10) % 256;

  for(int i = 0; i < lights.getNumPixels(); i++) {
    lights.setPixelHSV(i, baseHue+i*512/lights.getNumPixels(), 255, 255);
  }

  info.showActivity(lights, true, 256);
}

char * WWPAnimation2:: name() {
  return "WWPAnimation2";
}

