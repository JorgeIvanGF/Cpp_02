/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:58:41 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/10 11:04:47 by jorgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

// Colors
#define RESET   "\033[0m"
#define YELLOW  "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define RED "\033[0;31m"

#include <iostream>
#include <cmath> // for roundf

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;
		
	public:
		Fixed();                               // Default Constructor
		Fixed(const Fixed &other);             // Copy Constructor
		Fixed &operator=(const Fixed &other);  // Copy assignment
		~Fixed();                              // Destructor

		// Member Functions
		int  getRawBits() const;
		void setRawBits(int raw);

		// For ex01________________________________________________
		Fixed(int const intValue);            // int → fixed-point
		Fixed(float const floatValue);        // float → fixed-point

		float toFloat(void) const;            // fixed-point → float
		int   toInt(void)   const;            // fixed-point → int

		// For ex02________________________________________________
		// Comparison operators
		bool operator>(Fixed const& other) const;
		bool operator<(Fixed const& other) const;
		bool operator>=(Fixed const& other) const;
		bool operator<=(Fixed const& other) const;
		bool operator==(Fixed const& other) const;
		bool operator!=(Fixed const& other) const;

		// Arithmetic operators
		Fixed operator+(Fixed const& other) const;
		Fixed operator-(Fixed const& other) const;
		Fixed operator*(Fixed const& other) const;
		Fixed operator/(Fixed const& other) const;
		
		// Increment / Decrement
		Fixed& operator++();    // pre-increment
		Fixed  operator++(int); // post-increment
		Fixed& operator--();    // pre-decrement
		Fixed  operator--(int); // post-decrement

		// Min / Max
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
};

// FREE OPERATOR (outside the Class) ________________
// Stream insertion: print the float value
std::ostream& operator<<(std::ostream& os, Fixed const& fx);

#endif