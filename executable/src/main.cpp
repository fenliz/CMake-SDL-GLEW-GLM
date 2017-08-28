#include "library1/log.h"
#include "library2/window.h"

#include "SDL.h"
#include "glad/glad.h"
#include "imgui/imgui.h"

using namespace library1;
using namespace library2;
int main(int argc, char* argv[])
{
	Log* log = new Log();
	log->write("this is a test");
	
	Window* window = new Window(log, 1200, 900);

	window->newFrame();
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		static bool window_open = true;
		ImGui::Begin("Test window", &window_open, ImVec2(500, 500));
		ImGui::End();

		ImGui::Render();
		SDL_GL_SwapWindow(window->getSDLWindow());
	}

	SDL_Delay(2000);
	return 0;
}