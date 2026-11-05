#include <ctime>
#include <iostream>
#include <functional>
#include <type_traits>

template<typename FunctionReturnType, typename FunctionParameterType> 
void analyze_with_input_size_and_one_parameter(
    std::function<FunctionReturnType(FunctionParameterType)> func, 
    FunctionParameterType param, 
    int input_size)
{
    clock_t start = std::clock();

    if constexpr(std::is_same_v<FunctionReturnType, void>)
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