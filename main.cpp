#include <iostream>
#include <random>
#include <vector>
#include "BruteForceDFT/BruteFourier.hpp"
#include "CooleyTukeyFFT/CooleyTukeyFDFT.hpp"
#include "Resources/Signal.hpp"
#include "Resources/TimeAnalysis.hpp"

int main()
{
    std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);
    
    // brute force loop
    int size_control = 2;
    int num_runs = 14;
    Signal signal_control;
    std::vector<double> brute_times{};
    for(int i = 2; i < 2 + num_runs; ++i)
    {
        signal_control.clear();
        for(int k = 0; k < size_control; ++k)
        {
            signal_control.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
        }
        brute_times.push_back(function_analysis_time_only(bruteForce_DFT, signal_control));

        size_control = 1 << i;
    }

    std::vector<double> brute_ratios{};
    for(size_t i = 1; i < brute_times.size(); ++i)
    {
        brute_ratios.push_back(brute_times.at(i) / brute_times.at(i - 1));
    }

    double sum_brute = 0;
    std::cout << "\nBrute Force Ratios: [";
    for(size_t i = 0; i < brute_ratios.size(); ++i)
    {
        std::cout << brute_ratios.at(i);
        if(i != brute_ratios.size() - 1)
        {
            std::cout << ", ";
        }
        sum_brute += brute_ratios.at(i);
    }
    std::cout << "]\n";

    std::cout << "Average ratio: " << (sum_brute / (double)brute_ratios.size()) << "\n";

    std::cout << "Brute Force Times: [";
    for(size_t i = 0; i < brute_times.size(); ++i)
    {
        std::cout << brute_times.at(i);
        if(i != brute_times.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\n";

    // end brute time analysis
    // begin fft time analysis

    size_control = 2;
    num_runs = 12;
    Signal signal_control_fft;
    Signal dummy_output;
    std::vector<double> fft_times{};
    for(int i = 2; i < 2 + num_runs; ++i)
    {
        signal_control_fft.clear();
        dummy_output.clear();
        for(int k = 0; k < size_control; ++k)
        {
            signal_control_fft.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
        }
        fft_times.push_back(function_analysis_time_only(CT_FFT, signal_control_fft, &dummy_output, signal_control_fft.size()));

        size_control = 1 << i;
    }

    std::vector<double> fft_ratios{};
    for(size_t i = 1; i < fft_times.size(); ++i)
    {
        fft_ratios.push_back(fft_times.at(i) / fft_times.at(i - 1));
    }

    double sum_fft = 0;
    std::cout << "\nFFT Ratios: [";
    for(size_t i = 0; i < fft_ratios.size(); ++i)
    {
        std::cout << fft_ratios.at(i);
        if(i != fft_ratios.size() - 1)
        {
            std::cout << ", ";
        }
        sum_fft += fft_ratios.at(i);
    }
    std::cout << "]\n";

    std::cout << "Average ratio: " << (sum_fft / (double)fft_ratios.size()) << "\n";

    std::cout << "FFT Times: [";
    for(size_t i = 0; i < fft_times.size(); ++i)
    {
        std::cout << fft_times.at(i);
        if(i != fft_times.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n\n";

    return 0;
}