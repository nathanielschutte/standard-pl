#define SPGN_PROGRAM
#include "SPGN.h"

class TestProgram : public sp::IProgram {

public:

	TestProgram() {

		mProgramName = "TestProgram";
		// ... set other presetable parameters
	}



private:

	bool init() override {
		return true;
	}

	void update(const float time_delta) override {

	}

	void render() override {

		// replace some of these with SPGN functions...

		SDL_RenderClear(sdlRender);

		SDL_RenderPresent(sdlRender);
	}

	void clean() override {
		
	}
};