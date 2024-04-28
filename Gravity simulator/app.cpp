#include "app.h"
#include <cmath>
int radius = 10;
int mass = 10;
App::App()
{

}

Planet planet;
std::vector<Planet> planets;



	
	void App::NewPlanet()
	{
		int newIndex = planets.size();
		int initialMouseX = 0;
		int initialMouseY = 0;

		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			initialMouseX = GetMouseX();
			initialMouseY = GetMouseY();

			
			planets.push_back(Planet(initialMouseX, initialMouseY,radius, 0, 0, 0,newIndex ,0));

		}
	}

	void App::ReleasePlanet()
	{
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			if (!planets.empty())
			{
				int finalMouseX = GetMouseX();
				int finalMouseY = GetMouseY();

			
				float diffX = finalMouseX - planets.back().GetX();
				float diffY = finalMouseY - planets.back().GetY();

	
				float speed_x = diffX * .1;
				float speed_y = diffY * .1;

				planets.back().SetVelocity(speed_x *= -1, speed_y *= -1);
				planets.back().SetMass(mass);
			}
		}
	}



	int App::Collided(Planet& X, std::vector<Planet>& planets) {
		for (size_t i = 0; i < planets.size(); i++) {
			if (i == X.index)
				continue;
			const Planet& Y = planets[i];

			double distanceX = X.x - Y.x;
			double distanceY = X.y - Y.y;
			double distance = sqrt(distanceX * distanceX + distanceY * distanceY);

			if (distance < X.radius + Y.radius) {
				return i; // Retorna o índice do planeta com o qual houve colisão
			}
		}
		return -1; // Retorna -1 se não houver colisão
	}

double App::Gravity(Planet& X, std::vector<Planet>& planets) {

	const double G = 1.0;

	double totalForceX = 0;
	double totalForceY = 0;

	for (int i = 0; i < planets.size(); i++) {
		if (i == X.index)
			continue;

		const Planet& Y = planets[i];
		if (X.mass == 0 || Y.mass == 0)
			continue;

		double distanceX = X.x - Y.x;
		double distanceY = X.y - Y.y;

		double distance = sqrt(distanceX * distanceX + distanceY * distanceY);



	
		double force = (G * X.mass * Y.mass) / (distance * distance);


		force /= (X.mass + Y.mass);

		double massRatio = Y.mass / X.mass;
		force *= massRatio;

	
		double forceX = force * (distanceX / distance);
		double forceY = force * (distanceY / distance);

	
		totalForceX += forceX;
		totalForceY += forceY;
	}


	X.speed_x -= totalForceX;
	X.speed_y -= totalForceY;

	return 0;
}


void App::Run() {
	
	Color background = { 20, 20, 40, 255 };
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(background);
		
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			NewPlanet();
		ReleasePlanet();
		
		for (int i = planets.size() - 1; i >= 0; i--) {
			planets[i].Update();
			planets[i].Draw();
			
		}

		for (int i = 0; i < planets.size(); i++) {
			
			
			Gravity(planets[i], planets);
		}

		if (IsKeyPressed(KEY_SPACE))
			planets.clear();

		if (IsKeyDown(KEY_UP) && radius < 30)
			radius++;
			if (IsKeyDown(KEY_DOWN) && radius > 1)
				radius--;
			if (IsKeyDown(KEY_RIGHT) && mass <20)
			{
				mass = mass + 1;
			}
			else if (IsKeyDown(KEY_RIGHT) && mass < 100) {
				mass = mass + 5;
			}else if (IsKeyDown(KEY_RIGHT)) {
				mass = mass + 10;
			}

			if (IsKeyDown(KEY_LEFT) && mass < 20 && mass > 1)
			{
				mass = mass - 1;
			}
			else if (IsKeyDown(KEY_LEFT) && mass < 100 && mass > 1) {
				mass = mass - 5;
			}
			else if (IsKeyDown(KEY_LEFT) && mass > 1) {
				mass = mass - 10;
			}
			
					
		


		DrawText(TextFormat("Radius: %02i", radius), 20, 20, 20, ORANGE);
		DrawText(TextFormat("Mass: %02i", mass), 20, 40, 20, ORANGE);


		EndDrawing();
	}
}