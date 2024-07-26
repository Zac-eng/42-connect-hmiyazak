#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractional = 8;
public:
    Fixed(void);
    Fixed(const Fixed &object);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    Fixed& operator = (const Fixed &object);
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& object);
Fixed& operator > (const Fixed& lhs, const Fixed& rhs);
Fixed& operator < (const Fixed& lhs, const Fixed& rhs);
Fixed& operator >= (const Fixed& lhs, const Fixed& rhs);
Fixed& operator <= (const Fixed& lhs, const Fixed& rhs);
Fixed& operator == (const Fixed& lhs, const Fixed& rhs);
Fixed& operator != (const Fixed& lhs, const Fixed& rhs);
Fixed& operator + (const Fixed& lhs, const Fixed& rhs);
Fixed& operator - (const Fixed& lhs, const Fixed& rhs);
Fixed& operator * (const Fixed& lhs, const Fixed& rhs);
Fixed& operator / (const Fixed& lhs, const Fixed& rhs);

#endif
