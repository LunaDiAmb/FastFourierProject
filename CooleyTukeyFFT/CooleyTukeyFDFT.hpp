#pragma once
#include <cmath>
#include <random>
#include <iostream>
#include "../Resources/Signal.hpp"

#define PI 3.1415926535

void CT_FFT(Signal& input_signal, Signal* output, int N);
void CT_FFT_recursiveHelper(Signal* overall_signal, int N);