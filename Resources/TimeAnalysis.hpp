#pragma once
#include <chrono>
#include <utility>
#include <iostream>
#include <type_traits>
#include <functional>

template<typename Function, typename... Args> // variadic template allows for passing
double analyze_single_time(                   // unspecified number of arguments
    Function&& func, 
    Args&&... params) // parameter pack for the function parameters
{
    const auto start = std::chrono::steady_clock::now();

    if constexpr(std::is_void_v<std::invoke_result_t<Function, Args...>>)
    {   // if the function return type is void, just invoke it
        std::invoke(std::forward<Function>(func), std::forward<Args>(params)...);
    }
    else
    {   // if function is non-void, assign it to a variable to prevent no-discard errors
        auto&& result = std::invoke(std::forward<Function>(func), std::forward<Args>(params)...);
        asm volatile("" : : "g"(&result) : "memory"); // tricks the compiler into thinking that we are
    }                                                 // using result for something, this prevents optimizing
                                                      // away the else branch and resulting in a time of 0
    const auto end = std::chrono::steady_clock::now();

    const std::chrono::duration<double> difference = end - start;

    return difference.count();
}

template<typename Function, typename... Args>
void function_analysis(Function&& func, Args&&... params)
{
    constexpr int num_samples = 5; // more samples = more precision but more time taken

    double running_total = 0;
    for(int i = 0; i < num_samples; ++i)
    {
        running_total += analyze_single_time(func, params...);
    }
    double final_total = running_total / num_samples; // average the times

    std::cout << std::fixed << "It took " << final_total << " avg time to run this function, in seconds.\n"
                            << "Total time taken: " << running_total << " across " << num_samples
                            << " samples.\n";
}

template<typename Function, typename... Args>
double function_analysis_time_only(Function&& func, Args&&... params)
{
    constexpr int num_samples = 5; // more samples = more precision but more time taken

    double running_total = 0;
    for(int i = 0; i < num_samples; ++i)
    {
        running_total += analyze_single_time(func, params...);
    }
    double final_total = running_total / num_samples; // average the times

    return final_total;
}