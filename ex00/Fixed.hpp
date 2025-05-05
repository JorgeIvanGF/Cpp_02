/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:23:37 by jorgutie          #+#    #+#             */
/*   Updated: 2025/05/05 17:51:50 by jorgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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