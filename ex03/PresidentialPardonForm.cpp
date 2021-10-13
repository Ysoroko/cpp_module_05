/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:17:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 10:59:49 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//sign 25, exec 5

PresidentialPardonForm::PresidentialPardonForm() : Form("Default President Parent", 25, 5)
{
	this->_target = "Default";
	std::cout << "Presidential Pardon " << *this << " has beed defaultly constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("President Parent", 25, 5)
{
	this->_target = target;
	std::cout << "Presidential Pardon " << *this << " has beed constructed" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon " << *this << " has been destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Presidential Pardon " << *this << " has beed constructed from a copy" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
		std::cout << this->_target << " was pardonned by Zafod Beeblebrox\n";
}