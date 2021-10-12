/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:53 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 12:23:08 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class BureaucratException : public std::exception
{
	public:
		virtual const char* what() const throw(); //in "throw" we can tell which exception it can throw
};

class BureaucratExceptionGradeTooLow : public BureaucratException
{
	public:
		virtual const char* what() const throw(); //in "throw" we can tell which exception it can throw
};

class BureaucratExceptionGradeTooHigh : public BureaucratException
{
	public:
		virtual const char* what() const throw(); //in "throw" we can tell which exception it can throw
};

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
		void				incrementGrade( Bureaucrat & ref );
		void				decrementGrade( Bureaucrat & ref );

		// Getters
		const std::string	getName( void ) const;
		const int			getGrade( void ) const;

		// Setters
		void				setGrade( const int new_grade);

	private:
		const std::string	_name;
		int					_grade; //1 = highest, 150 = lowest

};

// << overload
std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);


#endif