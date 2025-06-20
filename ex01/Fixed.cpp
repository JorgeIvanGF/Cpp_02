/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:55:42 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/07 18:14:14 by jorgutie         ###   ########.fr       */
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

// NEW FOR ex01________________________________________

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