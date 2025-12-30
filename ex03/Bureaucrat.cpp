#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat():
name_(""), grade_(150){}


Bureaucrat::Bureaucrat(int grade, const std::string& name):
name_(name)
{
	std::cout << name_<< " Bureaucrat constructor called\n";
	if (grade < 1)
		throw GradeTooHighException(name_);
	else if (grade > 150)
		throw GradeTooLowException(name_);
	else
		grade_ = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << name_ << " Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):
name_(other.name_), grade_(other.grade_){
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	grade_ = other.grade_;
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return name_;
}

int	Bureaucrat::getGrade() const
{
	return grade_;
}

void	Bureaucrat::upgrade()
{
	if (this->grade_ - 1 < 1 )
		throw GradeTooHighException(name_);
	else
		grade_--;
}

void	Bureaucrat::degrade()
{
	if (this->grade_ + 1 > 150 )
		throw GradeTooLowException(name_);
	else
		grade_++;
}

void	Bureaucrat::signForm(AForm& toSign) const
{
	try {
		toSign.beSigned(*this);
		std::cout << name_ << " signed " << toSign.getName() << std::endl;
	} catch(std::exception& e)
	{
		std::cout << name_ << " coudn't sign " << toSign.getName()
			<< " because " << e.what();
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try {
	form.execute(*this);
	std::cout << getName() << " executed " << form.AForm::getName() << "\n";
	} catch (std::exception& e) {
		std::cout << getName() << " cannot execute form " << form.AForm::getName() << ": " << e.what();
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name):
msg_name_(name)
{
	std::stringstream output;

	output << msg_name_ << " grade TOOOOOOOOOOOO HIIIGGGHHHHHHH\n";
	msg_ = output.str();

}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return msg_.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name):
msg_name_(name)
{
	std::stringstream output;

	output << msg_name_ << " grade TOOOOOOOOOOOO LOOOOOOOOOOOWWW\n";
	msg_ = output.str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return msg_.c_str();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& one)
{
	out << one.getName() << ", bureaucrat grade " << one.getGrade() << "."<< std::endl;
	return out;
}
