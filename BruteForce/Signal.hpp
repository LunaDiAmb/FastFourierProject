#pragma once
#include <iostream>
#include <complex>
#include <vector>

typedef struct Complex 
{
    
    double real, imag;
    
    Complex(double real, double imag);
    Complex();

    void set(double r, double i);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

} Complex;

typedef struct Signal
{

    std::vector<Complex> signal;
    
    Signal(std::initializer_list<Complex> list);
        
    Complex& operator[](int idx);

} Signal;

std::ostream& operator<<(std::ostream& out, const Complex& obj);

std::ostream& operator<<(std::ostream& out, const Signal& obj);