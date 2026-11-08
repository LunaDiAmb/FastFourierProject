#include "Signal.hpp"
#include "TimeAnalysis.hpp"
#include "../BruteForceDFT/BruteFourier.hpp"
#include "../CooleyTukeyFFT/CooleyTukeyFDFT.hpp"
#include <random>

int main()
{
    Signal digital_input_signal_1;

    std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

    int N = 1000;
    for(int i = 0; i < N; ++i)
    {
        digital_input_signal_1.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    }

    function_analysis(bruteForce_DFT, digital_input_signal_1);

    return 0;
}