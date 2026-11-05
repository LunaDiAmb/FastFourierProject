#pragma once
#include "Signal.hpp"
#define PI 3.1415926535

Complex compute_twiddle(double angular_frequency, int n);

Signal bruteForce_DFT(Signal input_signal);

// Signal cooley_tukey_FDFT(Signal input_signal);