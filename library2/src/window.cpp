#include "library2/window.h"
#include "library1/log.h"
#include "glad/glad.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl_gl3.h"

#include <stdio.h>


using namespace library1;
namespace library2
{
	Window::Window(Log* log, int width, int height)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			log->write("Could not initialize SDL.");
			return;
		}

		sdl_window = SDL_CreateWindow("Hello world",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (!sdl_window)
		{
			log->write("Could not create SDL window.");
			return;
		}

		gl_context = SDL_GL_CreateContext(sdl_window);
		if (!gl_context)
		{
			log->write("Could not create OpenGL context.");
			return;
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		if (gladLoadGL() != 1)
		{
			log->write("Failed to load GLAD.");
			return;
		}

		SDL_GL_SetSwapInterval(0);

		log->write("Window was created.");

		ImGui_ImplSdlGL3_Init(sdl_window);
	}
	Window::~Window()
	{
		ImGui_ImplSdlGL3_Shutdown();
		SDL_DestroyWindow(sdl_window);
	}

	void Window::newFrame()
	{
		ImGui_ImplSdlGL3_NewFrame(sdl_window);
	}
}