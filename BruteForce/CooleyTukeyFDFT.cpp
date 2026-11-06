#include "CooleyTukeyFDFT.hpp"
#include "BruteFourier.hpp"

void fft(Signal input_signal, 
	Signal* output,
	int N) {

	// Make copy of array and apply window
	for (int i = 0; i < N; i++) {
		output->add_signal_component(input_signal[i]); // add element
		(*output)[i] *= 1; // Window
	}

	// Start recursion
	fft_rec(output, N);
}

void fft_rec(Signal* x, int N) {
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}

	// Split even and odd
	Signal odd_v;
	Signal even_v;
	Signal* odd = &odd_v;
	Signal* even = &even_v;
	for (int i = 0; i < N / 2; i++) {
		even->add_signal_component((*x)[i * 2]);
		odd->add_signal_component((*x)[i * 2 + 1]);
	}

	// Split on tasks
	fft_rec(even, N/2);
	fft_rec(odd, N/2);


	// Calculate DFT
	Complex twiddle_times_point, w;
	for (int k = 0; k < N / 2; k++) {
		w = Complex(cos(2 * PI * k / N), -sin(2 * PI * k / N));
		twiddle_times_point = w * (*odd)[k];
		(*x)[k] = (*even)[k] + twiddle_times_point;
		(*x)[N / 2 + k] = (*even)[k] - twiddle_times_point;
	}
}

int main() // testing 
{
	std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

	Signal input_signal;
	// for(int i = 0; i < 16; ++i)
    // {
    //     input_signal.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    // }

	input_signal.add_signal_components({
		Complex(1.0, 0.0), Complex(2.0, 0.0),
		Complex(1.0, 4.0), Complex(2.5, 1.0),
		Complex(5.5, 1.5), Complex(2.0, 0.0),
		Complex(4.0, 1.5), Complex(5.5, 6.0)
	});

	Signal output_v;
	Signal* output = &output_v;

	std::cout << "Input FFT Signal: " << input_signal << "\n";

	fft(input_signal, output, input_signal.size());

	std::cout << "Output FFT signal: " << *output << "\n";

	return 0;
}