#include "Signal.hpp"
#include <iostream>

int main()
{
    Signal digital_input_signal_1{
        Complex(3.0, -4.0),
        Complex(1.0, 0.0),
        Complex(5.0, 2.0)
    };

    std::cout << digital_input_signal_1 << "\n";

    return 0;
}