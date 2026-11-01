#include "Signal.hpp"
#include "BruteFourier.hpp"
#include <iostream>

int main()
{
    Signal digital_input_signal_1{
        Complex(3.0, -4.0),
        Complex(1.0, 0.0),
        Complex(5.0, 2.0)
    };

    Signal transformed_digital_output;

    transformed_digital_output = bruteForce_DFT(digital_input_signal_1);

    std::cout << digital_input_signal_1 << "\n";

    std::cout << transformed_digital_output << "\n";

    return 0;
}