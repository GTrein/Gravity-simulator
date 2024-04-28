#include <vector>
#include <raylib.h>
#include "planet.h"
class App
{
public:
	App();
	void Run();
	int Collided(Planet& X, std::vector<Planet>& planets);


private:
	void ReleasePlanet();
	void NewPlanet();
	
	double Gravity(Planet& X, std::vector<Planet>& planets);
	 std::vector<Planet> planets;
}; 