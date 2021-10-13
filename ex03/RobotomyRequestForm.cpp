/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 11:05:33 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : Form("Default Robo Parent", 72, 45)
{
	this->_target = "Default";
	std::cout << "Robotomy Request" << *this << " has beed defaultly constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robo Parent", 72, 45)
{
	this->_target = target;
	std::cout << "Robotomy Request" << *this << " has beed constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request" << *this << " has been destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Robotomy Request" << *this << " has beed constructed from a copy" << std::endl;
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
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());	
	int success = std::rand() % 2; // Random number between 0 and 1
	std::cout << "< intensive drilling noises >\n";
	if (success == 1)
	{
		std::cout << this->_target << " has been robotomized" << std::endl;
	}
	else
		throw (RobotomyRequestForm::FailureException());
}