#ifndef ROBOTOMYREQUESTFORM_HPP_
#define ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
	std::string	robotomyName_;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void setName(const std::string& name);
	virtual const std::string& getName() const;
	virtual void	action(const Bureaucrat& executor) const;
};

#endif // !ROBOTOMYREQUESTFORM_HPP_
