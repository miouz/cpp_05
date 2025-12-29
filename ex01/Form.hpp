#ifndef FORM_HPP_
#define FORM_HPP_

#include <string>
#include <exception>

class Bureaucrat;
class Form
{
	const std::string	formName_;
	bool		isSigned_;
	const int	gradeToSign_;
	const int	gradeToExec_;

	public:
	Form();
	Form(const std::string& name, const int gradeToSign, const int gradeToExec);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	const std::string getName() const;
	int	getGradeToSign() const;
	int	getGradeToExec() const;
	bool			getIsSigned() const;

	void	beSigned(const Bureaucrat& one);
	
	class	gradeTooHighException: public std::exception
	{
		public:
		const char*	what() const throw();
	};

	class gradeTooLowException: public std::exception
	{
		public:
		const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& one);

#endif // !FORM_HPP_
