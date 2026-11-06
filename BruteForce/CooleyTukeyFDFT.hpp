#ifndef FFT_h
#define FFT_h

#include <cmath>
#include <complex>
#include <random>
#include <iostream>
#include "Signal.hpp"

void fft(Signal input_signal, 
	Signal* output,
	int N);
void fft_rec(Signal* x, int N);

#endif