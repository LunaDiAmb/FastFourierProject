#include <chrono>
#include <utility>
#include <iostream>
#include <type_traits>
#include <random>
#include "../BruteForce/BruteFourier.hpp"
#include "Signal.hpp"

template<typename Function, typename FunctionParameterType> 
void analyze_with_input_size_and_one_parameter(
    Function&& func, 
    FunctionParameterType&& param, 
    int input_size)
{
    const auto start = std::chrono::steady_clock::now();

    if constexpr(std::is_void_v<std::invoke_result_t<F&, Param&&>>)
    {
        func(param);
    }
    else
    {
        FunctionReturnType dummy = func(param);
    }

    double time_diff = ((std::clock() - start) / (double)CLOCKS_PER_SEC);

    std::cout << "Time taken for function with input size " << input_size << ": " << time_diff << "\n";
}

int main()
{
    Signal digital_input_signal_1;

    std::random_device rd;

    std::mt19937 random_gen(rd());

    std::uniform_real_distribution<double> generate(0, 100);

    int N = 10000;
    for(int i = 0; i < N; ++i)
    {
        digital_input_signal_1.add_signal_component(Complex(generate(random_gen), generate(random_gen)));
    }

    analyze_with_input_size_and_one_parameter<Signal, Signal>(bruteForce_DFT, digital_input_signal_1, N);

    return 0;
}