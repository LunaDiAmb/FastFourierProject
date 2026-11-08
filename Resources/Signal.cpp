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

Complex Complex::operator*(const Complex& other) const
{
    // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
    return Complex(
        this->real * other.real - this->imag * other.imag,
        this->real * other.imag + this->imag * other.real
    );
}

Complex& Complex::operator*=(const Complex& other)
{
    *this = *this * other;
    return *this;
}

Complex Complex::operator*(int other) const
{
    return Complex(this->real * other, this->imag * other);
}

Complex& Complex::operator*=(int other)
{
    *this = *this * other;
    return *this;
}

Complex Complex::operator+(const Complex& other) const
{
    return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const
{
    return Complex(this->real - other.real, this->imag - other.imag);
}

Complex& Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imag = other.imag;
    return *this;
}

Complex& Complex::operator+=(const Complex& other)
{
    *this = *this + other;
    return *this;
}

Complex& Complex::operator-=(const Complex& other)
{
    *this = *this - other;
    return *this;
}

void Complex::set(double r, double i)
{
    this->real = r;
    this->imag = i;
}

double Complex::magnitude() const
{
    return sqrt(real * real + imag * imag);
}

size_t Signal::size() const
{
    return signal.size();
}

void Signal::clear()
{
    signal.clear();
}

void Signal::add_signal_component(Complex signal_component)
{
    signal.push_back(signal_component);
}

void Signal::add_signal_components(std::initializer_list<Complex> components)
{
    for(Complex c : components)
    {
        signal.push_back(c);
    }
}
    
Complex& Signal::operator[](int idx)
{ 
    if(idx >= signal.size())
    {
        throw std::runtime_error("Signal object of size " + std::to_string(size()) + " was indexed at " + std::to_string(idx) + ".");
    }
    return signal.at(idx); 
}

const Complex& Signal::operator[](int idx) const
{
    if(idx >= signal.size())
    {
        throw std::runtime_error("Signal object of size " + std::to_string(size()) + " was indexed at " + std::to_string(idx) + ".");
    }
    return signal.at(idx);
}

Signal& Signal::operator=(const Signal& other)
{
    this->signal = other.signal;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Complex& obj)
{
    out << std::fixed << std::setprecision(2) << obj.real << " " << ((obj.imag < 0) ? "-" : "+")
        << " " << ((obj.imag < 0) ? obj.imag * -1 : obj.imag) << "i";
    return out;
}

std::ostream& operator<<(std::ostream& out, Signal& obj)
{
    out << "[";
    for(int i = 0; i < obj.size(); ++i)
    {
        out << obj[i];
        if(i != obj.size() - 1)
        {
            out << ", ";
        }
    }
    out << "]";
    return out;
}