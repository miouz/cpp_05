#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <string>
#include <exception>

class Bureacrat;
class AForm
{
	private:
	const std::string	formName_;
	bool		isSigned_;
	const int	gradeToSign_;
	const int	gradeToExec_;

	public:
	AForm();
	AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	const std::string getName() const;
	int	getGradeToSign() const;
	int	getGradeToExec() const;
	bool			getIsSigned() const;

	void	beSigned(const Bureacrat& one);
	
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

std::ostream& operator<<(std::ostream& out, const AForm& one);

#endif // !AFORM_HPP_
