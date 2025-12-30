#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try{
	Intern	aNewFreshIntern;
	AForm* cerfa0 = aNewFreshIntern.makeForm("ShrubberyCreationForm", "Francois");
	std::cout << *cerfa0;
	AForm* cerfa1 = aNewFreshIntern.makeForm("RobotomyRequestForm", "Michel");
	std::cout << *cerfa1;
	AForm* cerfa2 = aNewFreshIntern.makeForm("PresidentialPardonForm", "Jerome");
	std::cout << *cerfa2;
	AForm* cerfa3 = aNewFreshIntern.makeForm("Shrub", "Jerome");
	std::cout << *cerfa3;
	}
	catch(std::exception& e)
	{
		std::cout << "Error: "<< e.what();
	}
	return 0;
}
