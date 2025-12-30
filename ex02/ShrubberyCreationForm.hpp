#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
	std::string shrubberyName_;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual const std::string& getName() const;
	void	setName(const std::string& name);
	virtual void	action(Bureaucrat const & executor) const;
};

#endif // !SHRUBBERYCREATIONFORM_HPP_
