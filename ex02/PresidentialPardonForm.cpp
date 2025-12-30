#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5),
presidentialName_(""){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5),
presidentialName_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("PresidentialPardonForm", 25, 5),
presidentialName_(other.presidentialName_) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	presidentialName_ = other.presidentialName_;
	return *this;
}

void PresidentialPardonForm::setName(const std::string& name)
{
	presidentialName_ = name;
}

const std::string& PresidentialPardonForm::getName() const
{
	return presidentialName_;
}

void PresidentialPardonForm::action(const Bureaucrat& executor) const
{
	(void)executor;
	std::cout<< presidentialName_ << " has been pardoned by Zaphod Beeblebrox🙏🏻\n";
}
