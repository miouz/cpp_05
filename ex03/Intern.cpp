#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>
#include <iostream>


Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

static AForm*	creatShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm*	creatRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm*	creatPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string	allForm[3] = {"shrubbery", "robotomy request", "presidential pardon"};
	AForm*	(*formCreator[3])(const std::string&) = {&creatShrubberyCreationForm, &creatRobotomyRequestForm, &creatPresidentialPardonForm };

	for(int i = 0; i < 3; i++)
	{
		if (allForm[i] == formName)
		{
			std::cout<< "Intern creates "<< formName <<"\n";
			return formCreator[i](target);
		}
	}
	throw FormNotFoundException(formName);
}

Intern::FormNotFoundException::FormNotFoundException(const std::string& formName)
{
	std::stringstream msg;

	msg<< formName << " cannot be found\n";
	msg_ = msg.str();
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return msg_.c_str();
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}
