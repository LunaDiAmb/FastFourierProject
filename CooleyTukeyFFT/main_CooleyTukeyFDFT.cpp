#include <iostream>
#include "CooleyTukeyFDFT.hpp"
#include "../Resources/Signal.hpp"

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
		Complex(1.0, 0.0), Complex(0.0, 0.0),
		Complex(0.0, 0.0), Complex(0.0, 0.0),
		Complex(0.0, 0.0), Complex(0.0, 0.0),
		Complex(0.0, 0.0), Complex(0.0, 0.0)
	});

	Signal output_v;
	Signal* output = &output_v;

	std::cout << "Input FFT Signal: " << input_signal << "\n";

	CT_FFT(input_signal, output, input_signal.size());

	std::cout << "Output FFT signal: " << *output << "\n";

	return 0;
}