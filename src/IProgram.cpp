#include "IProgram.h"

using namespace sp;

IProgram::IProgram() {}
IProgram::~IProgram() {}

bool IProgram::init() { return false; }
void IProgram::update(const float time_delta) { return; }
void IProgram::render() { return; }
void IProgram::clean() { return; }

/* Outermost program initialization */
SPGN_STATUS IProgram::create(uint32_t width, uint32_t height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		consoleLog("SDL systems initialized...");

		int flags = SDL_WINDOW_SHOWN;
		if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

		sdlWindow = SDL_CreateWindow(mProgramName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, flags);
		if (sdlWindow) {
			consoleLog("Window created");
		}
		else {
			consoleError("SDL window create error");
			return SPGN_STATUS::ERROR;
		}

		sdlRender = SDL_CreateRenderer(sdlWindow, -1, 0);
		if (sdlRender) {
			consoleLog("Renderer created");
		}
		else {
			consoleError("SDL renderer create error");
			return SPGN_STATUS::ERROR;
		}

		mRunning = true;
	}
	else {
		consoleError("SDL init error");
		return SPGN_STATUS::ERROR;
	}


	return SPGN_STATUS::OK;
}

void IProgram::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		mRunning = false;
		break;
	default:
		break;
	}
}

/* Outermost program loop */
SPGN_STATUS IProgram::start() {

	if (!init()) { 
		consoleError("Game initialization error!");
		return SPGN_STATUS::ERROR;
	}

	// loop (update/render)
	while (mRunning) {
		handleEvents();
		update(1.0);
		render();
	}

	clean();

	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRender);
	SDL_Quit();

	consoleLog("SDL cleaned up");

	return SPGN_STATUS::OK;
}



