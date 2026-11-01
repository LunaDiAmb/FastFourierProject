#include "BruteFourier.hpp"

Signal bruteForce_DFT(Signal input_signal)
{
    Signal output_signal;
    int num_samples = input_signal.size();

    for(int k = 0; k < num_samples; ++k)
    {
        Complex signal_point_output;

        for(int n = 0; n < num_samples; ++n)
        {
            double angular_frequency = (2 * PI) * (k / num_samples);
            constant_exponential = euler ** (Complex(0.0, angular_frequency * n))
        }
    }
}