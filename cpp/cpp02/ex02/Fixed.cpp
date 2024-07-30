#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const Fixed &object) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value = object.getRawBits();
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value * (1 << _fractional);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(value * (1 << _fractional) + FUDGE_FACTOR);
}

Fixed& Fixed::operator = (const Fixed &object) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = object.getRawBits();
    return *this;
}

bool    Fixed::operator > (const Fixed& compared) const {
    return _value > compared.getRawBits();
}

bool    Fixed::operator < (const Fixed& compared) const {
    return _value < compared.getRawBits();
}

bool    Fixed::operator >= (const Fixed& compared) const {
    return _value >= compared.getRawBits();
}

bool    Fixed::operator <= (const Fixed& compared) const {
    return _value <= compared.getRawBits();
}

bool    Fixed::operator == (const Fixed& compared) const {
    return _value == compared.getRawBits();
}

bool    Fixed::operator != (const Fixed& compared) const {
    return _value != compared.getRawBits();
}

Fixed   operator + (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() + oper2.toFloat());
};

Fixed   operator - (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() - oper2.toFloat());
};

Fixed   operator * (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() * oper2.toFloat());
};

Fixed   operator / (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() / oper2.toFloat());
};

Fixed&  Fixed::operator ++ (void) {
    this->_value += 1;
    return *this;
}

Fixed   Fixed::operator ++ (int) {
    this->_value += 1;
    return *this;
}

Fixed&  Fixed::operator -- () {
    this->_value += 1;
    return *this;
}

Fixed   Fixed::operator -- (int) {
    this->_value += 1;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object) {
    out << object.toFloat();
    return out;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw << _fractional;
}

float Fixed::toFloat(void) const {
    float float_value = static_cast<float>(_value) / (1 << _fractional);
    return float_value;
}

int Fixed::toInt(void) const {
    return _value / (1 << _fractional);
}
