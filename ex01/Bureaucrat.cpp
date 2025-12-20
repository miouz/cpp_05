#include "Bureaucrat.hpp"
#include <sstream>

Bureacrat::Bureacrat():
name_(""), grade_(150){}


Bureacrat::Bureacrat(int grade, const std::string& name):
name_(name)
{
	std::cout << name_<< " Bureacrat constructor called\n";
	if (grade < 1)
		throw GradeTooHighException(name_);
	else if (grade > 150)
		throw GradeTooLowException(name_);
	else
		grade_ = grade;
}

Bureacrat::~Bureacrat()
{
	std::cout << name_ << " Bureacrat destructor called\n";
}

Bureacrat::Bureacrat(const Bureacrat& other):
name_(other.name_), grade_(other.grade_){
	std::cout << "Bureacrat copy constructor called\n";
}

Bureacrat& Bureacrat::operator=(const Bureacrat& other)
{
	if (this == &other)
		return (*this);
	grade_ = other.grade_;
	return *this;
}

const std::string Bureacrat::getName() const
{
	return name_;
}

int	Bureacrat::getGrade() const
{
	return grade_;
}

void	Bureacrat::upgrade()
{
	if (this->grade_ - 1 < 1 )
		throw GradeTooHighException(name_);
	else
		grade_--;
}

void	Bureacrat::degrade()
{
	if (this->grade_ + 1 > 150 )
		throw GradeTooLowException(name_);
	else
		grade_++;
}

Bureacrat::GradeTooHighException::GradeTooHighException(const std::string& name):
msg_name_(name)
{
	std::stringstream output;

	output << msg_name_ << " grade TOOOOOOOOOOOO HIIIGGGHHHHHHH\n";
	msg_ = output.str();

}
const char* Bureacrat::GradeTooHighException::what() const throw()
{
	return msg_.c_str();
}

Bureacrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureacrat::GradeTooLowException::GradeTooLowException(const std::string& name):
msg_name_(name)
{
	std::stringstream output;

	output << msg_name_ << " grade TOOOOOOOOOOOO LOOOOOOOOOOOWWW\n";
	msg_ = output.str();
}

Bureacrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char* Bureacrat::GradeTooLowException::what() const throw()
{
	return msg_.c_str();
}

std::ostream& operator<<(std::ostream& out, const Bureacrat& one)
{
	out << one.getName() << ", bureaucrat grade " << one.getGrade() << "."<< std::endl;
	return out;
}
