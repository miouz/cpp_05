#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	std::string	presidentialName_;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void setName(const std::string& name);
	virtual const std::string& getName() const;
	virtual void	action(const Bureaucrat& executor) const;
};

#endif // !PRESIDENTIALPARDONFORM_HPP_
