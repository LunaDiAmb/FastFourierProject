#include "CooleyTukeyFDFT.hpp"
#include "BruteFourier.hpp"

void fft(Signal input_signal, 
	Signal output,
	int N) {

	// Make copy of array and apply window
	for (int i = 0; i < N; i++) {
		output[i] = input_signal[i];
		output[i] *= 1; // Window
	}

	// Start recursion
	fft_rec(output, N);
}

void fft_rec(Signal x, int N) {
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}

	// Split even and odd
	Signal odd;
	Signal even;
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	fft_rec(even, N/2);
	fft_rec(odd, N/2);


	// Calculate DFT
	for (int k = 0; k < N / 2; k++) {
		Complex t = compute_twiddle((2 * PI * k / N), N) * odd[k];
		x[k] = even[k] + t;
		x[N / 2 + k] = even[k] - t;
	}
}

int main() // testing 
{
	std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

	Signal input_signal;
	for(int i = 0; i < 100; ++i)
    {
        input_signal.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    }

	Signal output;

	fft(input_signal, output, input_signal.size());

	std::cout << "Output FFT signal: " << output << "\n";

	return 0;
}