#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat
{
	const std::string	name_;
	int					grade_	;

	public:
	Bureaucrat();
	Bureaucrat(int grade, const std::string& name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string getName() const;
	int	getGrade() const;
	void	upgrade();
	void	degrade();

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& one);

#endif // !BUREAUCRAT_HPP_
