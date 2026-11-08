#include "CooleyTukeyFDFT.hpp"

void CT_FFT(Signal& input_signal, Signal* output, int N) 
{
	for (int i = 0; i < N; i++) 
	{ // copy input_signal into output signal pointer 
		output->add_signal_component(input_signal[i]); // add element 
	}

	CT_FFT_recursiveHelper(output, N); // begin recursive solution
}

void CT_FFT_recursiveHelper(Signal* overall_signal, int N) 
{
	if (N <= 1) 
	{ 			// base case: if N <= 1, return to previous call
		return; // because N is sufficiently divided
	}

	Signal odd_v;
	Signal even_v;
	Signal* odd = &odd_v;
	Signal* even = &even_v;
	for (int i = 0; i < N / 2; i++) 
	{	// loop to split on even/odd indices in the signal
		even->add_signal_component((*overall_signal)[i * 2]);
		odd->add_signal_component((*overall_signal)[i * 2 + 1]);
	}

	CT_FFT_recursiveHelper(even, N/2);  // recursive branch to split on even idx
	CT_FFT_recursiveHelper(odd, N/2);	// recursive branch to split on odd idx

	Complex twiddle_times_point, w;
	for (int k = 0; k < N / 2; k++) 
	{	// O(N) loop to stitch this recursive level's output to the overall signal
		w = Complex(cos(2 * PI * k / N), -sin(2 * PI * k / N));
		twiddle_times_point = w * (*odd)[k]; 

		(*overall_signal)[k] 		 = (*even)[k] + twiddle_times_point;
		(*overall_signal)[N / 2 + k] = (*even)[k] - twiddle_times_point;
	}
}

