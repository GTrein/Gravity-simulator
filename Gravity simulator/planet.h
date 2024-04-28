using namespace std;
#ifndef PLANET_H
#define PLANET_H
#include <vector>
#include <iostream>
class Planet
{
public:
	Planet();
	float x, y;
	float speed_x, speed_y;
	int radius;
	int color = 1;
	int index;
	int mass;

	Planet(float x, float y, int radius, float speed_x, float speed_y, int color,int index, int mass);
	void Update();
	void Draw();
	float GetY();
	float GetX();
	int GetRadius();
	float GetSpeedY();
	float GetSpeedX();
	void SetVelocity(float velocity_x, float velocity_y);
	void SetMass(int mass);


private:





};
#endif //PLANET_H
