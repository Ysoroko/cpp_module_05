/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:29:44 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 12:02:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Canonic class methods:
Intern::Intern()
{
	std::cout << "An Intern has been constructed\n";
}

Intern::~Intern()
{
	std::cout << "An Intern has been destroyed\n";
}

// Nothing to copy, an Intern has no name/type or any defining characteristics
Intern::Intern(Intern const & ref)
{
	(void)ref; // remove the "unused argument" warning
	std::cout << "An Intern has been constructed from a copy\n";
}

// Nothing to assign, an Intern has no name/type or any defining characteristics
Intern & Intern::operator=(Intern const & ref)
{
	(void)ref; // remove the "unused argument" warning
	std::cout << "They're the exact same Interns\n";
	return (*this);
}

// Functions to create specific forms

static Form	*new_robo(std::string target)
{
	Form	*robo = new RobotomyRequestForm(target);
	return (robo);
}

static Form	*new_president(std::string target)
{
	Form	*president = new PresidentialPardonForm(target);
	return (president);
}

static Form	*new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

// Subject required method:
Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form	*(*fct[3])(std::string target) = { new_robo, new_president, new_shrub};
	std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form_name == msg[i])
			ret = fct[i](form_target);
	}
	std::cout << "Intern creates " << ret << std::endl;
	return (ret);
}


// void	(Karen::*fct[4])(void) = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error };
// 	//void (*fct[4])() = {&(Karen::debug()), info(), warning(), error()};
// 	std::string	msg[4] = {"debug", "info", "warning", "error"};
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (msg[i] == level)
// 		{
// 			(this->*(fct[i]))();
// 		}
// 	}