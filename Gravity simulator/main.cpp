


#include <cmath>
#include <ctime>
#include "app.h"
using namespace std;

const int screen_width = 1280;
const int screen_height = 720;



int main() {
	App app;
	srand(time(0));
	SetTargetFPS(60);

	InitWindow(screen_width, screen_height, "Gravity simulator - GABRIEL TREIN");
	InitAudioDevice();

	app.Run();

	



	CloseWindow();
	return 0;
}


