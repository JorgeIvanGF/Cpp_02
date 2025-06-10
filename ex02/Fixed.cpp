/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:12:27 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/10 16:06:24 by jorgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Defaul Constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy Constructor (initialization list)
Fixed::Fixed(const Fixed& other): _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)            // avoid self-assignment
		_value = other._value;     // or other.getRawBits()
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// METHODS______________________________________________

// Getter
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

// Setter
void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

// For ex01____________________________________________________

// Int constructor
Fixed::Fixed(int const intValue)
	: _value(intValue << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Float constructor
Fixed::Fixed(float const floatValue)
	: _value(static_cast<int>(roundf(floatValue * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

// Convert back to float
float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

// Convert back to int (drops fractions)
int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

// Stream insertion: print the float value
std::ostream& operator<<(std::ostream& os, Fixed const& fx)
{
	os << fx.toFloat();
	return os;
}


// For ex02_____________________________________________________

// Comparissons:
bool Fixed::operator>(Fixed const& other)const
{
	return (_value > other._value);
}

bool Fixed::operator<(Fixed const& other)const
{
	return (_value < other._value);
}

bool Fixed::operator>=(Fixed const& other)const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(Fixed const& other)const
{
	return (_value <= other._value);
}

bool Fixed::operator==(Fixed const& other)const
{
	return (_value == other._value);
}

bool Fixed::operator!=(Fixed const& other)const
{
	return (_value != other._value);
}


// Arithmetic

Fixed Fixed::operator+(Fixed const& other) const
{
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(Fixed const& other) const
{
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(Fixed const& other) const
{
	Fixed result;
	// Multiply raw, then shift back by fractional bits
	long tmp = (long)_value * other._value;
	result._value = (int)(tmp >> _fractionalBits); 
	// That single >> 8 divides tmp by 256 (dropping any extra bits),
	// exactly rescaling the product into fixed-point format.
	return result;
}

Fixed Fixed::operator/(Fixed const& other) const {
	Fixed result;
	// Shift up before dividing to retain precision
	// That single << 8 multiplies by 256 (keeping the precision)
	long tmp = ((long)_value << _fractionalBits);
	// Cast back to int bc after dividing, the value fits in 32 bits again
	result._value = (int)(tmp / other._value);
	return result;
}


// Increment and Decrement

Fixed& Fixed::operator++() 
{
	// pre-increment
	++_value;
	return *this;
}

Fixed Fixed::operator++(int) //dummy int value, just for differenciate the post-
{
	// post-increment
	Fixed old(*this);
	++_value;
	return old;
}

Fixed& Fixed::operator--()
{
	// pre-decrement
	--_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	// post-decrement
	Fixed old(*this);
	--_value;
	return old;
}