#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
formName_(""), isSigned_(false), gradeToSign_(150), gradeToExec_(150){}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExec):
formName_(name), isSigned_(false), gradeToExec_(gradeToExec), gradeToSign_(gradeToSign)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw gradeTooLowException(name);
	if (gradeToSign < 1 || gradeToExec < 1)
		throw gradeTooHighException(name);
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

const int	Form::getGradeToSign() const
{
	return gradeToSign_;
}

const int	Form::getGradeToExec() const
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
		throw gradeTooLowException(formName_);
}

Form::gradeTooHighException::gradeTooHighException(const std::string &name):
msg_name_(formName_)
{
	stringstream	output;

	output<< msg_name_<<" " 
}
