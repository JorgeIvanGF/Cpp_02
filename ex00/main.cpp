/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgutie <jorgutie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:23:42 by jorgutie          #+#    #+#             */
/*   Updated: 2025/06/07 17:15:55 by jorgutie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main()
{
	std::cout << YELLOW << "--- Creating a ---" << RESET << std::endl;
	Fixed a;                  // Default ctor

	std::cout << YELLOW << "\n--- Creating b(a) ---" << RESET << std::endl;
	Fixed b(a);               // Copy ctor

	std::cout << YELLOW << "\n--- Creating c and doing c = b ---" << RESET << std::endl;
	Fixed c;
	c = b;                    // Copy assignment

	std::cout << YELLOW << "\n--- Raw bits after creation ---" << RESET << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "b: " << b.getRawBits() << std::endl;
	std::cout << "c: " << c.getRawBits() << std::endl;

	std::cout << YELLOW << "\n--- Setting c raw bits to 42 ---" << RESET << std::endl;
	c.setRawBits(42);
	std::cout << "c now has raw bits: " << c.getRawBits() << std::endl;

	std::cout << YELLOW << "\n--- Exiting main (destructors will run) ---" << RESET << std::endl;
	return 0;
}