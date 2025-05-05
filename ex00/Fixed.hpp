/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:23:37 by jorgutie          #+#    #+#             */
/*   Updated: 2025/05/05 18:47:53 by jorgutie         ###   ########.fr       */
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
};

#endif