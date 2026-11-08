#include "../Resources/Signal.hpp"
#include "BruteFourier.hpp"
#include "../Resources/TimeComplexityAnalysis.cpp"
#include <iostream>
#include <ctime>
#include <random>

int main()
{
    Signal digital_input_signal_1;

    std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

    for(int i = 0; i < 1000; ++i)
    {
        digital_input_signal_1.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    }

    Signal transformed_digital_output;

    clock_t start = std::clock();

    transformed_digital_output = bruteForce_DFT(digital_input_signal_1);

    double diff_brute = (std::clock() - start) / (double)CLOCKS_PER_SEC;

    analyze_with_input_size_and_one_parameter<Signal, Signal>(bruteForce_DFT, digital_input_signal_1, digital_input_signal_1.size());

    std::cout << "Time analysis from main: " << diff_brute << "\n";

    return 0;
}