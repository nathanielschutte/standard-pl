
#ifndef IPROGRAM_H
#define IPROGRAM_H

#include "SDL.h"
#include "SPGNTypes.h"
#include <stdio.h>
#include <iostream>
#include <string>

#define CONSOLE_PREFIX "[SPGN]"
#define ERROR_PREFIX "[SPGN - ERROR]"

namespace sp {

	static void consoleLog(const char* str) {
		std::cout << CONSOLE_PREFIX << " " << str << std::endl;
	}

	static void consoleError(const char* str) {
		std::cout << ERROR_PREFIX << " " << str << std::endl;
	}

	class IProgram {

	public:
		IProgram();
		~IProgram();

		SPGN_STATUS create(uint32_t width, uint32_t height, bool fullscreen);
		SPGN_STATUS start();


	protected:

		SDL_Renderer* sdlRender;

		virtual bool init();
		virtual void update(const float time_delta);
		virtual void render();
		virtual void clean();

		void handleEvents();


		// settable by inheriting program class
		std::string mProgramName = "[no title]";


	private:

		SDL_Window* sdlWindow;

		bool mRunning = false;

		uint32_t mScreenWidth = 800;
		uint32_t mScreenHeight = 600;
		uint32_t mScreenScale = 1;
		uint32_t mMouseX = 0;
		uint32_t mMouseY = 0;

		// ...
	};
}

#endif