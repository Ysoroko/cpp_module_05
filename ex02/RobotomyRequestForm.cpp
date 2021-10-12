/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 15:57:54 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robo Parent", 72, 45)
{
	this->_target = "Default";
	std::cout << *this << " has beed defaultly constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robo Parent", 72, 45)
{
	this->_target = target;
	std::cout << *this << " has beed constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << *this << " has been destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << *this << " has beed constructed" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy failure");
}

// RANDOM TO IMPLEMENT
void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (executor.getGrade() > this->getGradeToExecute() || this->getSigned() == false)
		throw (Form::GradeTooLowException());
	
	
}

