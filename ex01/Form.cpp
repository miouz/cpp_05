#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
formName_(""), isSigned_(false), gradeToSign_(150), gradeToExec_(150){}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec):
formName_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw gradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw gradeTooHighException();
}

Form::~Form(){}

Form::Form(const Form& other):
formName_(other.formName_), isSigned_(other.isSigned_), gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_){}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return *this;
	this->isSigned_ = other.isSigned_;
	return *this;
}

const std::string Form::getName() const
{
	return formName_;
}

int	Form::getGradeToSign() const
{
	return gradeToSign_;
}

int	Form::getGradeToExec() const
{
	return gradeToExec_;
}

bool Form::getIsSigned() const
{
	return isSigned_;
}

void	Form::beSigned(const Bureacrat& one)
{
	if (one.getGrade() <= gradeToSign_)
		isSigned_ = true;
	else
		throw gradeTooLowException();
}

const char* Form::gradeTooLowException::what() const throw()
{
	return ("grade TOOOOOOOOOO LOWWWWWWW\n");
}

const char* Form::gradeTooHighException::what() const throw()
{
	return ("grade TOOOOOOOOOO HIIIIIGGGHHHHH\n");
}

std::ostream& operator<<(std::ostream& out, const Form& one)
{
	out <<std::boolalpha << "File " << one.getName() <<", grade to sign " << one.getGradeToSign()
		<< ", grade to exec " << one.getGradeToExec() <<". Form is signed = " << one.getIsSigned() << std::endl;
	return out;
}
