#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "sstream"
#include <string>

AForm::AForm():
formName_(""), isSigned_(false), gradeToSign_(150), gradeToExec_(150){}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExec):
formName_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExec_(gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::~AForm(){}

AForm::AForm(const AForm& other):
formName_(other.formName_), isSigned_(other.isSigned_), gradeToSign_(other.gradeToSign_), gradeToExec_(other.gradeToExec_){}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return *this;
	this->isSigned_ = other.isSigned_;
	return *this;
}

const std::string& AForm::getName() const
{
	return formName_;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign_;
}

int	AForm::getGradeToExec() const
{
	return gradeToExec_;
}

bool AForm::getIsSigned() const
{
	return isSigned_;
}

void	AForm::beSigned(const Bureaucrat& one)
{
	if (one.getGrade() <= gradeToSign_)
		isSigned_ = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade TOOOOOOOOOO LOWWWWWWW\n");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade TOOOOOOOOOO HIIIIIGGGHHHHH\n");
}

AForm::FormNotSigned::FormNotSigned(const std::string& formName): msg_(formName) {

	std::stringstream	outPut;

	outPut<< "Form " << msg_ << " is not signed\n";
	this->msg_ = outPut.str();
}

AForm::FormNotSigned::~FormNotSigned() throw() {}

const char* AForm::FormNotSigned::what() const throw()
{
	return (msg_.c_str());
}

std::ostream& operator<<(std::ostream& out, const AForm& one)
{
	out <<std::boolalpha << "File " << one.getName() <<", grade to sign " << one.getGradeToSign()
		<< ", grade to exec " << one.getGradeToExec() <<". Form is signed = " << one.getIsSigned() << std::endl;
	return out;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->getIsSigned())
		throw FormNotSigned(this->getName());
	if (executor.getGrade() > this->getGradeToExec())
		throw Bureaucrat::GradeTooLowException(executor.getName());
	this->action(executor);
}

