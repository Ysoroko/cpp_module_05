/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:33 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 11:05:50 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Default Shrub Parent", 145, 137)
{
	this->_target = "Default";
	std::cout << "Shrubbery Creation " << *this << " has beed defaultly constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrub Parent", 145, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation " << *this << " has beed constructed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation " << *this << " has been destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & ref) : Form(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute())
{
	this->_target = ref.getTarget();
	std::cout << "Shrubbery Creation " << *this << " has beed constructed from a copy" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	tree = 
"     ccee88oo          \n"
"  C8O8O8Q8PoOb o8oo    \n"
" dOB69QO8PdUOpugoO9bD  \n"
"CgggbU8OU qOp qOdoUOdcb\n"
"   6OuU  /p u gcoUodpP \n"
"      \\\\//  /douUP   \n"
"        \\\\////       \n"
"         |||/\\        \n"
"         |||\\/        \n"
"         |||||         \n"
"  .....\\//||||\\....  \n";

	if (this->getSigned() == false)
		throw (Form::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw (Form::GradeTooLowException());
	else
	{
		std::ofstream	ofs(this->_target);
		if (!ofs.is_open())
		{
			std::cout << "Coulnd't open the output file" << std::endl;
			return ;
		}
		ofs << tree;
	}
}