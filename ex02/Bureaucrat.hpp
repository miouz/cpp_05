#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureacrat
{
	const std::string	name_;
	int					grade_	;

	public:
	Bureacrat();
	Bureacrat(int grade, const std::string& name);
	~Bureacrat();
	Bureacrat(const Bureacrat& other);
	Bureacrat& operator=(const Bureacrat& other);

	const std::string getName() const;
	int	getGrade() const;
	void	upgrade();
	void	degrade();
	void	signForm(AForm& toSign) const;

	class	GradeTooHighException: public std::exception
	{
		const ::std::string	msg_name_;
		std::string	msg_;

		public:
		GradeTooHighException(const std::string& name);
		~GradeTooHighException() throw();
		const char* what() const throw ();
	};

	class	GradeTooLowException: public std::exception
	{
		const ::std::string	msg_name_;
		std::string msg_;

		public:
		GradeTooLowException(const std::string& name);
		~GradeTooLowException() throw();
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const Bureacrat& one);

#endif // !BUREAUCRAT_HPP_
