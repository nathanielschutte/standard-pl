
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

		uint32_t getScreenWidth();
		uint32_t getScreenHeight();

		SDL_Renderer* getRender();
		SDL_Window* getWindow();


	protected:

		// Override functions for inheriting program
		virtual bool init();
		virtual void update(const float time_delta);
		virtual void render();
		virtual void clean();
		void handleEvents();

		// ===========================================


		// Settable by inheriting program class
		std::string mProgramName = "[no title]";

		// ===========================================


	private:
		SDL_Renderer* sdlRender;
		SDL_Window* sdlWindow;

		bool mRunning = false;
		bool mPaused = false;
		bool mFullscreen = false;
		tick_t mTime = 0;
		tick_t mPauseTime = 0;

		uint32_t mScreenWidth = 800;
		uint32_t mScreenHeight = 600;
		uint32_t mScreenScale = 1;
		uint32_t mMouseX = 0;
		uint32_t mMouseY = 0;

		// ...

		// Internal functions for base program class
		void SPGN_update(const float time_delta);
		void SPGN_render();
		void SPGN_clean();
		void SPGN_handleEvents();
	};
}

#endif