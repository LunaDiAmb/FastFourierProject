#pragma once
#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>
#include <exception>
#include <string>

typedef struct Complex 
{
    
    double real, imag;
    
    Complex(double real, double imag);
    Complex();

    void set(double r, double i);
    double magnitude() const;

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex& operator*=(const Complex& other);
    Complex operator*(int other) const;
    Complex& operator*=(int other);
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator=(const Complex& other);

} Complex;

typedef struct Signal
{

    std::vector<Complex> signal;
    
    Signal(std::initializer_list<Complex> list);
    Signal();

    size_t size() const;
    void add_signal_component(Complex signal_component);
    void add_signal_components(std::initializer_list<Complex> components);
        
    Complex& operator[](int idx);
    Signal& operator=(const Signal& other);

} Signal;

std::ostream& operator<<(std::ostream& out, const Complex& obj);

std::ostream& operator<<(std::ostream& out, const Signal& obj);