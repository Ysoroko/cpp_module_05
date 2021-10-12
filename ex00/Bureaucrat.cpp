/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:49 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 12:22:27 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// --------------------------- Bureaucrat Functions ----------------------------

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "A default Bureaucrat has beed constructed\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (BureaucratExceptionGradeTooHigh());
	else if (grade < 1)
		throw (BureaucratExceptionGradeTooLow());
	else
	{
		this->_grade = grade;
		std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed constructed\n";
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed destroyed\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref) : _name(ref.getName() + "_copy")
{
	this->_grade = ref.getGrade();
	std::cout << "A Bureaucrat " << _name << " with a grade " << _grade << " has beed constructed from a copy\n";
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}

void				Bureaucrat::incrementGrade( Bureaucrat & ref )
{
	if (ref.getGrade() - 1 < 1)
		throw (BureaucratExceptionGradeTooLow());
	else
	{
		this->_grade--;
	}
}

void				Bureaucrat::decrementGrade( Bureaucrat & ref )
{
	if (ref.getGrade() + 1 > 150)
		throw (BureaucratExceptionGradeTooHigh());
	else
	{
		this->_grade++;
	}
}


// Getters
const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

const int			Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

// Setters
void				Bureaucrat::setGrade( const int new_grade)
{
	 this->_grade = new_grade;
}

// << operator overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs)
{
	o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade() << std::endl;
	return (o);
}

// ----------------------------------------------------------------------------



// ---------------------- BureaucratException Functions -----------------------

const char* BureaucratException::what() const throw()
{
	return ("BureaucratException");
}

const char* BureaucratExceptionGradeTooLow::what() const throw()
{
	return ("Cannot get a grade < 1!");
}

const char* BureaucratExceptionGradeTooHigh::what() const throw()
{
	return ("Cannot get a grade > 150!");
};
