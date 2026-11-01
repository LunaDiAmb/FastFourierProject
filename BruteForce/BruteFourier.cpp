#include "BruteFourier.hpp"

inline Complex compute_twiddle(double angular_frequency, int n)
{   // euler's formula: e^{ix} = cos(x) + isin(x)
    return Complex(cos(-1 * angular_frequency * n), sin(-1 * angular_frequency * n));
}   // x = -1 * angular_frequency * n 

Signal bruteForce_DFT(Signal input_signal)
{
    Signal output_signal;
    size_t num_samples = input_signal.size();
    double angular_frequency;

    Complex signal_point_output, twiddle;
    for(int k = 0; k < num_samples; ++k)
    {
        for(int n = 0; n < num_samples; ++n)
        {
            angular_frequency = (2 * PI) * (k / (double)num_samples);
            twiddle = compute_twiddle(angular_frequency, n);
            std::cout << "TWIDDLE: " << twiddle << "\n";
            signal_point_output += (twiddle * input_signal[n]);
            std::cout << "SIGNAL_POINT_OUTPUT: " << signal_point_output << "\n";
        }
        
        output_signal.add_signal_component(signal_point_output);
    }

    return output_signal;
}