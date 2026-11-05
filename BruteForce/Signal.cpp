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

Complex& Complex::operator*(const Complex& other)
{
    // (a + bi)(c + di) = (ac - bd) + i(ad + bc)
    this->real *= other.real;
    this->imag *= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    *this = *this * other;
    return *this;
}

Complex& Complex::operator*(int other)
{
    this->real *= other;
    this->imag *= other;
    return *this;
}

Complex& Complex::operator*=(int other)
{
    *this = *this * other;
    return *this;
}

Complex& Complex::operator+(const Complex& other)
{
    this->real += other.real;
    this->imag += other.imag;
    return *this;
}

Complex& Complex::operator-(const Complex& other)
{
    this->real -= other.real;
    this->imag -= other.imag;
    return *this;
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

void Signal::add_signal_component(Complex signal_component)
{
    signal.push_back(signal_component);
}
    
Complex& Signal::operator[](int idx) 
{ 
    return signal.at(idx); 
}

Signal& Signal::operator=(const Signal& other)
{
    this->signal = other.signal;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex& obj)
{
    out << std::fixed << std::setprecision(2) << obj.real << " " << ((obj.imag < 0) ? "-" : "+")
        << " " << ((obj.imag < 0) ? obj.imag * -1 : obj.imag) << "i";
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