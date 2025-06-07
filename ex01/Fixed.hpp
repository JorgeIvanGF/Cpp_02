/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:02:35 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/07 18:45:52 by jorgutie         ###   ########.fr       */
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

		// New for ex01
		Fixed(int const intValue);            // int → fixed-point
		Fixed(float const floatValue);        // float → fixed-point

		float toFloat(void) const;            // fixed-point → float
		int   toInt(void)   const;            // fixed-point → int

};

// FREE OPERATOR (outside the Class) ________________
// Stream insertion: print the float value
std::ostream& operator<<(std::ostream& os, Fixed const& fx);

#endif