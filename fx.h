//fx.h
#pragma once

#include "primitives.h"

#ifndef FX__H_
#define FX__H_

namespace primitives
{
	void shockWave(const Point &, const int &, const int &);
	void showerConfetti(const int &, const int &, const double &, const double &, const int &, const int &, const int &); // WIP
	void particleWave(const Point &, const int &, const int &, const int &, const int &);
}

// void boxBlur(const int &, const int &, const int &, const int &, const int &); // WIP
//void ramp(starting point, ending point, type = linear/exponential, color);


#endif
