/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoroko <ysoroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:05 by ysoroko           #+#    #+#             */
/*   Updated: 2021/10/12 15:54:07 by ysoroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & ref);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & ref);
		
		std::string	getTarget( void ) const;
		void execute(Bureaucrat const & executor);

		// Failure
		class FailureException : public Form::Exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		std::string	_target;
};

#endif