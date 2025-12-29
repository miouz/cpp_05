#ifndef SHRUBBERYCREATIONFORM_HPP_
#define SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
	std::string shrubberyName_;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	std::string& getShrubberyName() const;
	void	setShrubberyName(std::string& name);

};

#endif // !SHRUBBERYCREATIONFORM_HPP_
