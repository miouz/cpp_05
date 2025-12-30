#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat cafNpc(1,"Francois");
	Bureaucrat cafNpc2(150,"Patricia");

	std::cout << "------------------test for ShrubberyCreationForm--------------------------\n";
	//test for ShrubberyCreationForm
	AForm *cerfa01 = new ShrubberyCreationForm("WC");
	cafNpc.signForm(*cerfa01);
	cafNpc.executeForm(*cerfa01);
	std::cout << std::endl;

	//test for RobotomyRequestForm
	std::cout << "------------------test for RobotomyRequestForm--------------------------\n";
	AForm	*cerfa02 = new RobotomyRequestForm("aNewFreshIntern");
	cafNpc.signForm(*cerfa02);
	//test for the 50% time succeed
	cafNpc.executeForm(*cerfa02);
	cafNpc.executeForm(*cerfa02);
	cafNpc.executeForm(*cerfa02);
	cafNpc.executeForm(*cerfa02);
	cafNpc.executeForm(*cerfa02);
	std::cout << std::endl;

	std::cout << "------------------test for PresidentialPardonForm--------------------------\n";
	//test for PresidentialPardonForm
	AForm *cerfa03 = new PresidentialPardonForm("cafNPCPatricia");
	cafNpc.signForm(*cerfa03);
	cafNpc.executeForm(*cerfa03);
	std::cout << std::endl;

	std::cout << "------------------test for error catch--------------------------\n";
	//test for execute
	cafNpc2.executeForm(*cerfa03);
	cafNpc2.executeForm(*cerfa02);

	delete cerfa01;
	delete cerfa02;
	delete cerfa03;
	return (0);
}

