#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45),
robotomyName_(""){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45),
robotomyName_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestForm", 72, 45),
robotomyName_(other.robotomyName_) {}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	robotomyName_ = other.robotomyName_;
	return *this;
}

void RobotomyRequestForm::setName(const std::string& name)
{
	robotomyName_ = name;
}

const std::string& RobotomyRequestForm::getName() const
{
	return robotomyName_;
}

void RobotomyRequestForm::action(const Bureaucrat& executor) const
{
	static bool	succes;
	
	std::cout << "Bzzzz...bzzzz.... "<< executor.getName() << " is trying to robotomy "<< robotomyName_<<"..bzz\n";
	if (succes == false)
	{
		std::cout<< robotomyName_ << " has been robotomized successfully🫡\n";
		succes = true;
	}
	else {
		std::cout<< "Oups >.< robotomy of "<< robotomyName_ << " just failed🤦🏻‍♀️\n";
		succes = false;
	}
}
