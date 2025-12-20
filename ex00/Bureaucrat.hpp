#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

#include <exception>
#include <string>
#include <iostream>

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

	class	GradeTooHighException: public std::exception
	{
		public:
		const char* what() const throw ();
	};

	class	GradeTooLowException: public std::exception
	{
		public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const Bureacrat& one);

#endif // !BUREAUCRAT_HPP_
