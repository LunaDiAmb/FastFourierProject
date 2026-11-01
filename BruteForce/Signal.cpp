#include "Signal.hpp"

Complex::Complex(double real, double imag)
    : real(real), imag(imag) {}

Complex::Complex()
    : real(0.0), imag(0.0) {}
    
Signal::Signal(std::initializer_list<Complex> list)
    : signal(list) {}

Signal::Signal()
    : signal({}) {}

bool Complex::operator==(const Complex& other) const
{
    return this->real == other.real && this->imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

Complex Complex::operator*(const Complex& other)
{
    // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
    return Complex(
        (this->real * other.real - this->imag * other.imag), 
        (this->real * other.imag + this->imag * other.real)
    );
}

Complex& Complex::operator+(const Complex& other)
{
    this->real = other.real;
    this->imag = other.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
    return *this + other;
}

void Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imag = other.imag;
}

void Complex::set(double r, double i)
{
    this->real = r;
    this->imag = i;
}

size_t Signal::size() const
{
    return signal.size();
}

void Signal::add_signal_component(Complex signal_component)
{
    signal.push_back(signal_component);
}
    
Complex& Signal::operator[](int idx) 
{ 
    return signal.at(idx); 
}

void Signal::operator=(const Signal& other)
{
    signal = other.signal;
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