#include "omar.h"
#include "TileContainer.h"

using namespace omar;

int main()
{   
	omar::Terminal window(16.0f, ' ', "");
	window.initialize();
	
	window.showFps = true;
	
	int x_pos = window.getTileDimensions().x / 3;
	int y_pos = window.getTileDimensions().y / 2;
	
	window.setString(x_pos, y_pos, "OpenGL ", 120, 255, 87);
	window.setString(x_pos + 7, y_pos, "bitMap ", 255, 236, 110);
	window.setString(x_pos + 14, y_pos, "ASCII ", 255, 102, 134);
	window.setString(x_pos + 20, y_pos, "Renderer", 180, 120, 255);
	window.setString(x_pos + 3, y_pos + 2, "easy - portable - cool");
	
	for (int i = x_pos; i < x_pos + 28; i++)
	{
		window.setTileColor(i, y_pos, 50, 50, 50);
	}
	
	bool running = true;
	while (running)
	{
		window.setString(0, 2, to_string(window.getMousePosScreen().x));
		window.setString(0, 3, to_string(window.getMousePosScreen().y));
		window.setChar(0, 1, window.getKeyPress() > 0 ? window.getKeyPress() : ' ');
		
		if(window.getKeyPress() == 27)
			running = false;
		
		window.draw();
		
		window.setString(0, 1, "     ");
		window.setString(0, 2, "     ");
		window.setString(0, 3, "     ");
	}
}
