#pragma once
#include "SDL.h"

namespace library1
{
	class Log;
}
namespace library2
{
	class Window
	{
	public:
		Window(library1::Log* log, int width, int height);
		~Window();

		void newFrame();

		SDL_Window* getSDLWindow() { return sdl_window; }
	private:
		SDL_Window* sdl_window;
		void* gl_context;
	};
}