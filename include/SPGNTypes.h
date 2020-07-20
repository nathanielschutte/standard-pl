
// Types and common values for SPGN

#ifndef SPGNTYPES_H
#define SPGNTYPES_H

namespace sp {

	typedef uint64_t tick_t;

	enum class SPGN_STATUS {
		OK = 1,
		ERROR = -1,
		IO_ERROR = -2,
	};

	struct pixel_t {
		union {
			uint32_t n = 0xFF000000;
			struct {
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			};
		};

		pixel_t();
		pixel_t(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
		pixel_t(uint32_t p);

		bool operator==(const pixel_t& p) const;
		bool operator!=(const pixel_t& p) const;
	};
}
#endif // SPGNTYPES_H



// Below is ensured to be defined only once
// =======================================

#ifdef SPGN_PROGRAM
#undef SPGN_PROGRAM

namespace sp {
	pixel_t::pixel_t() {
		r = 0; g = 0; b = 0; a = 255;
	}
	pixel_t::pixel_t(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		r = red; g = green; b = blue; a = alpha;
	}
	pixel_t::pixel_t(uint32_t p) {
		n = p;
	}
	bool pixel_t::operator==(const pixel_t& p) const {
		return n == p.n;
	}
	bool pixel_t::operator!=(const pixel_t& p) const {
		return n != p.n;
	}
}

#endif // SPGN_PROGRAM