#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	//test form subject
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;

	//my test
	try{
	Intern	aNewFreshIntern;
	AForm* cerfa0 = aNewFreshIntern.makeForm("shrubbery", "Francois");
	std::cout << *cerfa0;
	AForm* cerfa1 = aNewFreshIntern.makeForm("robotomy request", "Michel");
	std::cout << *cerfa1;
	AForm* cerfa2 = aNewFreshIntern.makeForm("presidential pardon", "Jerome");
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
