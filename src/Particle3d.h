#pragma once
#include "ofMain.h"

class Particle3d{
public:
  Particle3d();

  void setup(ofVec3f position, ofVec3f velocity);

  void resetForce();

  void addForce(ofVec3f force);

  void updateForce();
  void updatePos();
  void update();

  void throughOfWalls();

  void draw();

  ofVec3f position;
  ofVec3f velocity;
  ofVec3f force;

  float radius;
  float friction;
  bool bFixed;
  float mass;
};
