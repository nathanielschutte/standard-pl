#define SPGN_PROGRAM
#include "SPGN.h"

class TestProgram : public sp::IProgram {

public:

	TestProgram() {

		mProgramName = "TestProgram";

		// ... set other presetable parameters
	}

private:

	SDL_Rect rect;

	int rectX = 0;
	int rectSize = 50;
	int rectVel = 1;

	bool init() override {

		rect.x = rectX;
		rect.y = getScreenHeight() / 2;
		rect.w = rectSize;
		rect.h = rectSize;

		return true;
	}

	void update(const float time_delta) override {
		rectX += rectVel * time_delta;
		if (rectVel > 0 && (rectX + rectSize) > getScreenWidth()) {
			rectX -= rectVel * time_delta;
			rectVel = -1 * rectVel;
		}
		else if (rectX < 0) {
			rectX -= rectVel * time_delta;
			rectVel = -1 * rectVel;
		}
		rect.x = rectX;
	}

	void render() override {

		SDL_SetRenderDrawColor(getRender(), 0, 0, 0, 255);
		SDL_RenderClear(getRender());

		SDL_SetRenderDrawColor(getRender(), 255, 255, 255, 255);
		SDL_RenderDrawRect(getRender(), &rect);
		
		SDL_RenderPresent(getRender());
	}

	void clean() override {
		return;
	}
};



// ------------------------------------------------------------------

int main(int argc, char* argv[]) {

	TestProgram program;
	program.create(800, 600, false);
	program.start();

	return 0;
}