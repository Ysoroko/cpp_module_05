/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:36:51 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/13 12:03:46 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Default"), _grade_to_sign(150), _grade_to_execute(150), _signed(0)
{
	std::cout << "A default " << *this << " has been constructed" << std::endl;
}

Form::~Form()
{
	std::cout << *this << " has beed destroyed\n";
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(0)
{
	if (_grade_to_sign > 150 || _grade_to_execute > 150)
		throw (Form::GradeTooLowException());
	else if (_grade_to_sign < 1 || _grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << *this << " has been constructed" << std::endl;
}

Form::Form(Form const & ref) : _name(ref.getName()), _grade_to_sign(ref.getGradeToSign()), _grade_to_execute(ref.getGradeToExecute()), _signed(ref.getSigned())
{
	std::cout << *this << " has been constructed from a copy" << std::endl;
}

Form & Form::operator=(Form const & ref)
{
	this->_signed = ref.getSigned();
	return (*this);
}

// Getters
const std::string	Form::getName( void ) const
{
	return (this->_name);
}

int					Form::getGradeToSign( void ) const
{
	return (this->_grade_to_sign);
}

int					Form::getGradeToExecute( void ) const
{
	return (this->_grade_to_execute);
}

bool				Form::getSigned( void ) const
{
	return (this->_signed);
}

// Setters
void				Form::setSigned( const bool new_value)
{
	std::cout << *this << " signed value was set to " << new_value << std::endl;
	this->_signed = new_value;
}

// Nested Exception classes:
const char* Form::Exception::what() const throw()
{
	return ("FormException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("the grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("the grade is too high");
};

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form");
};

std::ostream & operator<<( std::ostream & o, Form const & rhs)
{
	o << "Form " << rhs.getName() << " having a grade_to_sign " << rhs.getGradeToSign() << " and a grade_to_execute "
		<< rhs.getGradeToExecute() << " with signed equal to " << rhs.getSigned();
	return (o);
}

// Functions
void	Form::be_signed(Bureaucrat & ref)
{
	int	grade = ref.getGrade();

	if (grade > _grade_to_sign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " was signed by the bureaucrat " << ref.getName() << " with a grade " << ref.getGrade() << std::endl;
}