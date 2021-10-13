/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 10:12:18 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{

	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator
	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");

	// Executing
	// ShrubberyCreationForm : sign 145, exec 137
	// RobotomyRequestForm sign 72, exec 45
	// PresidentialPardonForm sign 25, exec 5
	std::cout << std::endl;
	std::cout << "EXECUTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << "UNSIGNED:" << std::endl;
	std::cout << "ShrubberyCreationForm:" << std::endl;
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
	//-----------------------------------------------------
	std::cout << "UNSIGNED:" << std::endl;
	std::cout << "RobotomyRequestForm:" << std::endl << std::endl;
	try
	{
		robo.execute(bob);
	}
	catch(Form::Exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	robo.be_signed(bob);
	std::cout << std::endl;
	std::cout << "50% Failure chance:" << std::endl << std::endl;
	try
	{
		robo.execute(bob);
		robo.execute(bob);
		robo.execute(bob);
		robo.execute(bob);
		robo.execute(bob);
	}
	catch(Form::Exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << std::endl;


	std::cout << "GRADE TO EXE TOO HIGH:" << std::endl;
	std::cout << "----------------------------" << std::endl;
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