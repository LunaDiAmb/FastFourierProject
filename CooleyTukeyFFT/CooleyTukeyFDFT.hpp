#pragma once
#include <cmath>
#include <random>
#include <iostream>
#include "Signal.hpp"

void CT_FFT(Signal input_signal, Signal* output, int N);
void CT_FFT_recursiveHelper(Signal* x, int N);