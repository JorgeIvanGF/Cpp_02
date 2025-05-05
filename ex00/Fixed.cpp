/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:23:34 by jorgutie          #+#    #+#             */
/*   Updated: 2025/05/05 18:44:43 by jorgutie         ###   ########.fr       */
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