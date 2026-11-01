#include "Signal.hpp"

Complex::Complex(double real, double imag)
    : real(real), imag(imag) {}

Complex::Complex()
    : real(0.0), imag(0.0) {}
    
Signal::Signal(std::initializer_list<Complex> list)
    : signal(list) {}

bool Complex::operator==(const Complex& other) const
{
    return this->real == other.real && this->imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

void Complex::set(double r, double i)
{
    this->real = r;
    this->imag = i;
}
    
Complex& Signal::operator[](int idx) 
{ 
    return signal.at(idx); 
}

std::ostream& operator<<(std::ostream& out, const Complex& obj)
{
    out << obj.real << " " << ((obj.imag < 0) ? "-" : "+")
        << " " << abs(obj.imag) << "i";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Signal& obj)
{
    out << "[";
    for(const auto& item : obj.signal)
    {
        out << item;
        if(item != obj.signal[obj.signal.size() - 1])
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}