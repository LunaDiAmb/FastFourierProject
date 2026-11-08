#include "BruteFourier.hpp"

Complex compute_twiddle(double angular_frequency, int n)
{   // euler's formula: e^{ix} = cos(x) + isin(x)
    return Complex(cos(-1 * angular_frequency * n), sin(-1 * angular_frequency * n));
}   // x = -1 * angular_frequency * n 

Signal bruteForce_DFT(const Signal& input_signal)
{
    Signal output_signal; // define output signal to be edited
    size_t num_samples = input_signal.size();
    double angular_frequency;

    Complex signal_point_output, twiddle;
    for(int k = 0; k < num_samples; ++k)
    {   // k-loop is for each output point
        signal_point_output.set(0.0, 0.0); // reset current output for next iteration
        for(int n = 0; n < num_samples; ++n)
        {   // n-loop is for each input point
            angular_frequency = (2 * PI) * (k / (double)num_samples);
            twiddle = compute_twiddle(angular_frequency, n); // returns Complex
            signal_point_output += (twiddle * input_signal[n]); // summation step
        }
        output_signal.add_signal_component(signal_point_output);
    }

    return output_signal;
}

// Signal cooley_tukey_FDFT(Signal input_signal)
// {
    
// }