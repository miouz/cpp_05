#include "Bureaucrat.hpp"

Bureacrat::Bureacrat():
name_(""), grade_(150){}


Bureacrat::Bureacrat(int grade, const std::string& name):
name_(name)
{
	std::cout << "Bureacrat constructor called\n";
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		grade_ = grade;
}

Bureacrat::~Bureacrat()
{
	std::cout << "Bureacrat destructor called\n";
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
		throw GradeTooHighException();
	else
		grade_--;
}

void	Bureacrat::degrade()
{
	if (this->grade_ + 1 > 150 )
		throw GradeTooLowException();
	else
		grade_++;
}

const char* Bureacrat::GradeTooHighException::what() const throw()
{
	return "grade TOOOOOOOOOOOO HIIIGGGHHHHHHH\n";
}

const char* Bureacrat::GradeTooLowException::what() const throw()
{
	return "grade TOOOOOOOOOOOO LOOOOOOOOOWWWW\n";
}

std::ostream& operator<<(std::ostream& out, const Bureacrat& one)
{
	out << one.getName() << ",bureaucrat grade " << one.getGrade() << std::endl;
	return out;
}
