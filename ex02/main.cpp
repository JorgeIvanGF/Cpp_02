/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:23:18 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/10 16:39:54 by jorgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2) );

	std::cout << "a = " << a << std::endl;      // 0
	std::cout << "++a = " << ++a << std::endl;  // smallest step
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;  // returns old
	std::cout << "a = " << a << std::endl;

	std::cout << "b = " << b << std::endl;      // ≈10.1016

	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;

	std::cout << std::boolalpha;// to show/print ´true´ or ´false´ instead of ´0´or ´1´
	std::cout << "a < b? " << (a < b) << std::endl;
	std::cout << "a == b? " << (a == b) << std::endl;

	return 0;
}