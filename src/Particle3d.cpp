#include "Particle3d.h"

Particle3d::Particle3d(){
  radius = 3.0;
  friction = 0;
  mass = 1.0;
  bFixed = false;
}

void Particle3d::setup(ofVec3f _position, ofVec3f _velocity){
  position = _position;
  velocity = _velocity;
}

void Particle3d::resetForce(){
  force.set(0, 0, 0);
}

void Particle3d::addForce(ofVec3f _force){
  force += _force /mass;
}

void Particle3d::updateForce(){
  force -= velocity * friction;
}

void Particle3d::updatePos(){
  if(!bFixed){
    velocity += force;
    position += velocity;
  }
}

void Particle3d::update(){
  updateForce();
  updatePos();
}

void Particle3d::draw(){
}
