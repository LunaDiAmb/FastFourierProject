#include "../Resources/Signal.hpp"
#include "BruteFourier.hpp"
#include <iostream>
#include <ctime>
#include <random>

int main()
{
    Signal digital_input_signal_1;

    std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

    for(int i = 0; i < 5; ++i)
    {
        digital_input_signal_1.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    }

    Signal transformed_digital_output;

    transformed_digital_output = bruteForce_DFT(digital_input_signal_1);

    std::cout << "\nDigital Input Signal: " << digital_input_signal_1 << "\n\n";

    std::cout << "Output BruteForce Signal: " << transformed_digital_output << "\n\n";

    return 0;
}