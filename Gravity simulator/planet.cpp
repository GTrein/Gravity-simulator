
#include "planet.h"
#include <raylib.h>
#include <iostream>
#include "app.h"

App app;


Planet::Planet()
{

}
Planet::Planet(float x, float y, int radius, float speed_x, float speed_y, int color, int index,int mass)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speed_x = speed_x;
    this->speed_y = speed_y;
    this->color = color;
    this->index = index;
    this->mass = mass;
}



void Planet::Update() {
    y += speed_y;
    x += speed_x;

    
}



void Planet::Draw()
{

    DrawCircle(x, y, radius, ORANGE);


}


  

float Planet::GetY()
{
    return y;
}
float Planet::GetX()
{
    return x;
}
int Planet::GetRadius()
{
    return radius;
}
float Planet::GetSpeedY()
{
    return speed_y;
}
float Planet::GetSpeedX()
{
    return speed_x;
}

void Planet::SetVelocity(float velocity_x, float velocity_y)
{
    speed_x = velocity_x;
    speed_y = velocity_y;
}

void Planet::SetMass(int mass1)
{
    mass = mass1;
  
}


