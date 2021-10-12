/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 14:17:39 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		// Constructors / destructor / '=' overload
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);
		Bureaucrat & operator=(Bureaucrat const & ref);

		// Increment / Decrement grade
		void				incrementGrade( void );
		void				decrementGrade( void );

		// Getters
		const std::string	getName( void ) const;
		int					getGrade( void ) const;

		// Setters
		void				setGrade( const int new_grade);

		// Nested Exception classes:
		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public Bureaucrat::Exception
		{
			public:
				virtual const char* what() const throw();
		};

		// ex01
		void signForm(Form & ref);

	private:
		const std::string	_name;
		int					_grade; //1 = highest, 150 = lowest

};

// << overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif