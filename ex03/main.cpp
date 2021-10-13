/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 12:05:02 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Intern	intern;
	Form	*robo_form;
	Form	*shrub_form;
	Form	*president_form;
	Form	*unknown_form;
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "INTERN TESTS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	// Robo:
	robo_form = intern.makeForm("robotomy request", "robo");
	std::cout << *robo_form << " was just created " << std::endl;

	// President:
	president_form = intern.makeForm("presidential pardon", "president");
	std::cout << *president_form << " was just created " << std::endl;

	// Shrub:
	shrub_form = intern.makeForm("shrubbery creation", "shrub");
	std::cout << *shrub_form << " was just created " << std::endl;

	// Unknown:
	unknown_form = intern.makeForm("driving licence", "drive");
	std::cout << *unknown_form << " was just created " << std::endl;

	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	return (0);
	//-------------------------------------------------------	
}