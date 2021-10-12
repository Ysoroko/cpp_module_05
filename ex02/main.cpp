/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 15:45:37 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	ShrubberyCreationForm	shrub("shrub"); 

	// Executing
	// ShrubberyCreationForm : sign 145, exec 137
	// RobotomyRequestForm sign 72, exec 45
	// PresidentialPardonForm sign 25, exec 5
	std::cout << std::endl;
	std::cout << "EXECUTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "UNSIGNED:" << std::endl;
	try
	{
		shrub.execute(bob);
	}
	catch(Form::Exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	shrub.be_signed(bob);
	shrub.execute(bob);
	std::cout << std::endl << std::endl;

	std::cout << "GRADE TO EXE TOO HIGH:" << std::endl;
	try
	{
		shrub.execute(bill);
	}
	catch(Form::Exception &e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	return (0);
	//-------------------------------------------------------	
}